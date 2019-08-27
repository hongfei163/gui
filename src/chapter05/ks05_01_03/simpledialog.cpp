﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: simpledialog.cpp
\brief  CSimpleDialog类的实现文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/
#include "simpledialog.h"


CSimpleDialog::CSimpleDialog(QWidget* pParent) : QDialog(pParent) {
    ui.setupUi(this);
	
}

CSimpleDialog::~CSimpleDialog() {

}

void CSimpleDialog::slot_addressSaved(const QString& strAddress){
	
	if (NULL != ui.m_plainTextEdit->document()) {
		QString str = "The Address is:" + strAddress;
        ui.m_plainTextEdit->document()->setPlainText(str);
	}
}

