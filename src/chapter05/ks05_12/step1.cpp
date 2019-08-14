/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: step1.cpp
\brief  对话框编程示例, 预览窗口类实现文件
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/7
*/

#include <QPushButton>

#include "step1.h"

CStep1::CStep1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
 
    connect(ui.btnNext, &QPushButton::clicked,
        this, &CStep1::slot_next);
}

void CStep1::slot_next() {
    emit sig_showPage(1); // 序号从0开始, step1界面是第0个，所以下一步要显示第1个。
}