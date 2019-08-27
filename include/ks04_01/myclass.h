/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ����������CPrint�Ķ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_01_dll.dll
*/

#ifndef _MYCLASS_DLL_H
#define _MYCLASS_DLL_H

#include "ks04_01_export.h"
/// ��ӡ��CPrint����
class KS04_01_Export CPrint {
public:
	CPrint(){}
	~CPrint(){}
public:
	/**
	* @brief ��ָ����Ϣ��ӡ����Ļ

	* @param[in] szInfo  ����ӡ����Ϣ
	* @return void
	*/
	void printOnScreen(const char*);
};

KS04_01_Export int func1();
KS04_01_Export int func2(int, float);

#endif  // _MYCLASS_DLL_H