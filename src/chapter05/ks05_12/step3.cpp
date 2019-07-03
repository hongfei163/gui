/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: step3.cpp
\brief  对话框编程示例, 预览窗口类实现文件
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/7
*/


#include "step3.h"

CStep3::CStep3(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.btnPrevious, &QPushButton::clicked, this, &CStep3::slot_previous);
    connect(ui.btnClose, &QPushButton::clicked, this, &CStep3::slot_close);
  
}

void CStep3::slot_previous()
{
    emit showpage(1);
}
void CStep3::slot_close()
{
    emit closeWindow();
}
