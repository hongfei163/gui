/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief main()������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include <QCoreApplication>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QDir>
#include <QFile>
#include "qglobal.h"
#include <QString>



void example01();
void example02();


int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	QCoreApplication app(argc, argv);
   

	if (1) {
		example01();
	}

	if (1) {
		example02();
	}
	
	system("pause");

	return 0;
}

/**
* @brief ����xml��ʽ�ļ�ʾ������
*        xml�ļ�����
*       --------------------------------------------------------------------
*       <?xml version="1.0" encoding="GB2312" standalone="yes"?>
*       <!--�����ع���-->
*       <doc>
*           <courses count="4" institution="�����ع���" teacher="Ů�����ϰ�">
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="1" fee="����">C++�����ռ�</lesson>
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="2" fee="����">C++��ƽ̨�����еı�������</lesson>
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="3">Qt����������-GUI��Ʒ����</lesson>
*               <lesson url="sorry, not ready" id="4">C++��ƽ̨����ģ�鿪��</lesson>
*           </courses>
*       </doc>
*
*/
void example01() {

}

/**
* @brief ��ȡxml��ʽ�ļ�ʾ������
*/
void example02() {

}
