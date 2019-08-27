/*! \file: main.cpp
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\brief main()������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/
#include <QCoreApplication>
#include <QStringList>
#include <QDir>

#include <iostream>

#include "qglobal.h"
#include "sync.h"


using std::cerr;
using std::cout;
using std::endl;

/////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	QCoreApplication app(argc, argv);

	CSync sync;
	sync.exec();  

	

	return 0;
}




