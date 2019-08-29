/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: ks04_11_export.h
\brief exe+dll编程示例，引出类所在的头文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_11_dll.dll
*/

#ifndef _KS04_11_EXPORT_H
#define _KS04_11_EXPORT_H


// 动态库导出宏定义
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