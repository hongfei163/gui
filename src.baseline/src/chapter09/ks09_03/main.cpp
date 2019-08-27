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
#include <QTranslator>
#include <QLibraryInfo>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include "base/basedll/baseapi.h"
#include "mainwindow.h"
#include "textedit.h"

int main(int argc, char * argv[])
{
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
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/ks03_01.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks08_03.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}
	CMainWindow mainWindow(NULL);
	CTextEdit textEdit(&mainWindow);
	QFile file;
	QString strFile = ns_train::getFileName("$TRAINDEVHOME/test/chapter08/ks08_01/input.txt");
	file.setFileName(strFile);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		return -1;
	}
	QTextStream input(&file);
	input.setCodec("GBK"); // ���߿���������: UTF-8��

	QString str = input.readAll();
	textEdit.setText(str);

	mainWindow.setCentralWidget(&textEdit);
	mainWindow.show();

    return app.exec();
}
