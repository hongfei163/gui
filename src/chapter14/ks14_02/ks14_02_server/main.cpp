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
#include <QTextStream>
#include <QThread>
#include "inputthread.h"
#include "server.h"


int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	QApplication app(argc, argv);

    CServer server;
    server.startListen();
    CInputThread thread;
    thread.start();

    QObject::connect(&thread, SIGNAL(finished()), &app, SLOT(quit()));

	return app.exec();
}
