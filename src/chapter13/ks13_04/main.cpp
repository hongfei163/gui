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
#include "baseapi.h"

using std::cout;
using std::endl;
typedef QMap<QString, QByteArray> MD5Map;

/**
* @brief  reduce����
* @param[in|out] result reduce�����ķ������ݴ��ŵ�result��
* @param[in] w ִ����map�����õ��Ľ���w��Ϊ���봫��reduce������
* @return void
*/
void reduce(MD5Map &result, const MD5Map &w)
{
    QMapIterator<QString, QByteArray> i(w);
    while (i.hasNext()) {
        i.next();
        result[i.key()] += i.value();
    }
}

/**
* @brief  map����
* @param[in] strFileName ������md5�����ļ�����
* @return MD5Map ���������ļ�����md5����ӳ�䣬��ֵ������������reduce�ӿ�(��Ϊ�ӿڵĲ���2)
*/
MD5Map getMd5OfFile(const QString& strFileName)
{
    qDebug() << "get md5 in thread" << QThread::currentThread();
    MD5Map md5map;
    md5map[strFileName] = ns_train::getMd5(strFileName);
    return md5map;
};
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
    strFilters << "*.h" << "*.cpp"; // ��Ҫע�������ѱ�demo������md5_a.txt��md5_b.txtͳ�����ڡ�

    // �õ�������MD5�����ļ��б�.
    QString strScanPath = ns_train::getPath("$TRAINDEVHOME");
    qDebug() << strScanPath;
    QStringList files = ns_train::getFileList(strScanPath, strFilters, true);
    QStringList::iterator ite = files.begin();
   
    int singleThreadTime = 0; // ���̼߳���md5��������ʱ�䡣
    QTime time;
    time.start();
    MD5Map md5_a;
    { // ���в���
        QString strFileName;
        for (; ite != files.end(); ite++) {
            md5_a[*ite] = ns_train::getMd5(*ite);
        }
        singleThreadTime = time.elapsed(); // ms
        qDebug() << "single thread" << singleThreadTime;
    }
    
    // ������aд���ļ�
    {
        QString strFileName;
        strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter13/ks13_04/md5_a.txt");
        QString strDir = ns_train::getDirectory(strFileName);
        QDir dir;
        dir.mkpath(strDir);

        QFile file(strFileName);
        // �򿪷�ʽ��ֻ�����ı���ʽ
        if (!file.open(QFile::Truncate | QFile::WriteOnly | QFile::Text)) {
            qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        }
        else {
            QMapIterator<QString, QByteArray> iteMd5(md5_a);
            while (iteMd5.hasNext()) {
                iteMd5.next();
                file.write(iteMd5.key().toLocal8Bit());
                file.write(iteMd5.value());
            }
        }
        file.close();
    }

    int mapReduceTime = 0;
    MD5Map md5_b;
    {
        QTime time;
        time.start();
        md5_b = QtConcurrent::mappedReduced(files, getMd5OfFile, reduce);
        mapReduceTime = time.elapsed();
        qDebug() << "MapReduce" << mapReduceTime;
    }

    qDebug() << "Map speedup x" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;

    // ������bд���ļ�
    {
        QString strFileName;
        strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter13/ks13_04/md5_b.txt");
        QString strDir = ns_train::getDirectory(strFileName);
        QDir dir;
        dir.mkpath(strDir);

        QFile file(strFileName);
        // �򿪷�ʽ��ֻ�����ı���ʽ
        if (!file.open(QFile::Truncate | QFile::WriteOnly | QFile::Text)) {
            qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        }
        else {
            QMapIterator<QString, QByteArray> iteMd5(md5_b);
            while (iteMd5.hasNext()) {
                iteMd5.next();
                file.write(iteMd5.key().toLocal8Bit());
                file.write(iteMd5.value());
            }
        }
        file.close();
    }
 	return 0;
}
