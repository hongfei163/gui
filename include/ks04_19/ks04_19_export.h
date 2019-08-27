﻿/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�������������ڵ�ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10 
* please import ks04_19_dll.dll
*/

#ifndef _KS04_19_EXPORT_H
#define _KS04_19_EXPORT_H


// ��̬�⵼���궨��
#ifdef WIN32		// windows platform
#	if defined __KS04_19_DLL_SOURCE__
#		define KS04_19_Export __declspec(dllexport)
#	else
#		define KS04_19_Export __declspec(dllimport)
#	endif

#else				// other platform
#  define KS04_19_Export
#endif // WIN32


#endif  // _KS04_19_EXPORT_H