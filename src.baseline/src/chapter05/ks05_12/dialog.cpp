﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.cpp
\brief	
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/7

*/

#include "dialog.h"
#include "step1.h"
#include "step2.h"
#include "step3.h"

CDialog::CDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);  
}