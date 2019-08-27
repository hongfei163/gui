/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。
\file: main.cpp
\brief main()函数的实现文件


\author 女儿叫老白   http://xingdianketang.cn/
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
	// 国际化
	// 安装qt自带的中文翻译
	const QString localSysName = QLocale::system().name();
	QScopedPointer<QTranslator> qtTranslator(new QTranslator(QCoreApplication::instance()));
	if (qtTranslator->load(QStringLiteral("qt_") + localSysName,
		QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		QCoreApplication::installTranslator(qtTranslator.take());
	}

	// 安装我们项目的翻译文件
	QString strPath = qgetenv("TRAINDEVHOME");	// 获取环境变量所指向的路径
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
	input.setCodec("GBK"); // 读者可以试试用: UTF-8。

	QString str = input.readAll();
	textEdit.setText(str);

	mainWindow.setCentralWidget(&textEdit);
	mainWindow.show();

    return app.exec();
}
