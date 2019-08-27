/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�����������Ķ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_02_dll.dll
*/

#ifndef _MYCLASS_DLL_H
#define _MYCLASS_DLL_H


class CPrint {
public:
	CPrint(){}
	~CPrint(){}
public:
	void printOnScreen(const char*);
};

int func1();
int func2(int, float);

#endif  // _MYCLASS_DLL_H