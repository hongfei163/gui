﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.h
\brief 演示用头文件
  
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>

class CCustomWidget;

class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* parent);
	~CDialog(){;}

private:
	Ui::CDialog ui;
	CCustomWidget* m_pWidget;
};

#endif 