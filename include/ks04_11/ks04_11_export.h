/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: ks04_11_export.h
\brief exe+dll����ʾ�������������ڵ�ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_11_dll.dll
*/

#ifndef _KS04_11_EXPORT_H
#define _KS04_11_EXPORT_H


// ��̬�⵼���궨��
#ifdef WIN32		// windows platform
#	if defined __KS04_11_DLL_SOURCE__
#		define KS04_11_Export __declspec(dllexport)
#	else
#		define KS04_11_Export __declspec(dllimport)
#	endif

#else				// other platform
#  define KS04_11_Export
#endif // WIN32


#endif  // _KS04_08_EXPORT_H