/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: baseapi.h
\brief ͨ��dll�����������ڵ�ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
* please import basedll.dll
*/

#ifndef _BASE_EXPORT_H
#define _BASE_EXPORT_H


// ��̬�⵼���궨��
#ifdef WIN32		// windows platform
#	if defined __BASEDLL_SOURCE__
#		define BASE_API __declspec(dllexport)
#	else
#		define BASE_API __declspec(dllimport)
#	endif

#else				// other platform
#  define BASE_API
#endif // WIN32


#endif  // _BASE_EXPORT_H