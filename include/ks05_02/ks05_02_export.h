/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�������������ڵ�ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10 
* please import ks05_02_dll.dll
*/

#ifndef _KS05_02_EXPORT_H
#define _KS05_02_EXPORT_H


// ��̬�⵼���궨��
#ifdef WIN32		// windows platform
#	if defined __KS05_02_DLL_SOURCE__
#		define KS05_02_Export __declspec(dllexport)
#	else
#		define KS05_02_Export __declspec(dllimport)
#	endif

#else				// other platform
#  define KS05_02_Export
#endif // WIN32


#endif  // _KS05_02_EXPORT_H