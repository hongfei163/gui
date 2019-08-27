/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: myclass.h
\brief exe+dll编程示例，引出类的定义头文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9 
*/

#ifndef _MYCLASS_DLL_H
#define _MYCLASS_DLL_H


class CPrint
{
public:
	CPrint(){}
	~CPrint(){}
public:
	void printOnScreen(const char*);
};

int func1();
int func2(int, float);

#endif  // _MYCLASS_DLL_H