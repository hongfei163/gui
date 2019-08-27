/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���
\file: dialog.h
\brief main()������ʵ���ļ�


\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/
#include <QApplication>

#include "dialog.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
	CDialog dialog(NULL);
	dialog.show();
    return app.exec();
}
