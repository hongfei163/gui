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
#include <QFile>
#include <QMainWindow>
#include <QTextEdit>
#include <QTextStream>
#include "base/basedll/baseapi.h"
#include "textedit.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
	
	QMainWindow mainWindow(NULL);
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
