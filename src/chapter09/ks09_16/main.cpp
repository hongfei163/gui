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
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QTranslator>
#include <QLibraryInfo>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include "mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    // ���������в���
    // -f="c:/dir/fielname.dat"
    QCommandLineOption op1("f");
    op1.setValueName("path"); // ����ֵ��·����������ValueName�󡣽����������ô�������ֵ
    QCommandLineParser parser;
    parser.addOption(op1);
    parser.process(app);
    if (parser.isSet("f")) {
        qDebug() << parser.value(op1);// "c:/dir/fielname.dat"
    }
        
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
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/ks03_01.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks09_15.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}


    return app.exec();
}
