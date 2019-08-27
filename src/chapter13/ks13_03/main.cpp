/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief main()������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/
#include <QApplication>
#include <QTranslator>	// ���ʻ�
#include "qglobal.h"
#include <QLibraryInfo> // ���ʻ�

#include <QDir> 
#include <QFile> 
#include <qtconcurrentmap.h>
#include <iostream>
#include <functional>

#include "baseapi.h"

using std::cout;
using std::endl;

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	QApplication app(argc, argv);

	// ���ʻ�
	// ��װqt�Դ������ķ���
	const QString localSysName = QLocale::system().name();
	QScopedPointer<QTranslator> qtTranslator(new QTranslator(QCoreApplication::instance()));
	if (qtTranslator->load(QStringLiteral("qt_") + localSysName,
		QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		QCoreApplication::installTranslator(qtTranslator.take());
	}

	// ��װ������Ŀ�ķ����ļ�
	QString strPath = qgetenv("TRAINDEVHOME");	// ��ȡ����������ָ����·��
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/xxxxx.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks13_03.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}

    QStringList strFilters;
 //   strFilters << "*.h" << "*.cpp";
    strFilters << "*";

    // �õ�������MD5�����ļ��б�.
    QString strScanPath = ns_train::getPath("$TRAINDEVHOME");
    qDebug() << strScanPath;
    QStringList files = ns_train::getFileList(strScanPath, strFilters, true);
    QStringList::iterator ite = files.begin();
   
    int singleThreadTime = 0; // ���̼߳���md5��������ʱ�䡣
    QTime time;
    time.start();
    QList<QByteArray> md5_a;
    { // ���в���
        QString strFileName;
        for (; ite != files.end(); ite++) {
            md5_a.push_back(ns_train::getMd5(*ite));
        }
        singleThreadTime = time.elapsed(); // ms
        qDebug() << "single thread" << singleThreadTime;
    }
    // ������aд���ļ�
    {
        QString strFileName;
        strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter13/ks13_03/md5_a.txt");
        QString strDir = ns_train::getDirectory(strFileName);
        QDir dir;
        dir.mkpath(strDir);

        QFile file(strFileName);
        // �򿪷�ʽ��ֻ�����ı���ʽ
        if (!file.open(QFile::Truncate | QFile::WriteOnly | QFile::Text)) {
            qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());            
        }
        else {
            QList<QByteArray>::iterator iteMd5 = md5_a.begin();
            for (; iteMd5 != md5_a.end(); iteMd5++) {
                file.write(*iteMd5);
            }
        }
        file.close();
    }

    // ����std::function�����ĺ���
    std::function<QByteArray(const QString&)> getMd5OfFile = [](const QString &strFileName) -> QByteArray
    {
        qDebug() << "get md5 in thread" << QThread::currentThread();
        return ns_train::getMd5(strFileName);
    };

    // Use QtConcurrentBlocking::mapped to apply the getMd5OfFile function to all the
    // files in the list.
    QList<QByteArray> md5_b;
    int mapTime = 0; // ʹ��QtConcurrent��map����md5��������ʱ�䡣
    {
        QTime time;
        time.start();
        md5_b = QtConcurrent::blockingMapped(files, getMd5OfFile);
        mapTime = time.elapsed(); // ms
        qDebug() << "Map:" << mapTime;

    }
    qDebug() << "Map speedup x" << ((double)singleThreadTime - (double)mapTime) / (double)mapTime + 1;
    
    // ������bд���ļ�
    {
        QString strFileName;
        strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter13/ks13_03/md5_b.txt");
        QString strDir = ns_train::getDirectory(strFileName);
        QDir dir;
        dir.mkpath(strDir);

        QFile file(strFileName);
        // �򿪷�ʽ��ֻ�����ı���ʽ
        if (!file.open(QFile::Truncate | QFile::WriteOnly | QFile::Text)) {
            qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        }
        else {
            QList<QByteArray>::iterator iteMd5 = md5_b.begin();
            for (; iteMd5 != md5_b.end(); iteMd5++) {
                file.write(*iteMd5);
            }
        }
        file.close();
    }
 	return 0;
}
