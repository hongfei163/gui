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

#include "qglobal.h"
#include <iostream>

#include "config.h"

#include "myclass.h"


using std::cout;
using std::endl;

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

    CModel model;
    model.initialize();

    qreal r = CConfig::instance().getSelectRadius();// todo������CConfig��getSelectRadius()�ӿ�����ȡ���ò�����
    cout << "r = " << r << endl;
	return 0;
}
