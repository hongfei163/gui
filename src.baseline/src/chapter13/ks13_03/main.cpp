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
#include <iostream>
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
    

 	return 0;
}
