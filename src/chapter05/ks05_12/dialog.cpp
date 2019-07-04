/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.cpp
\brief	
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/7

*/

#include <QStackedLayout>

#include "dialog.h"
#include "step1.h"
#include "step2.h"
#include "step3.h"

CDialog::CDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);  

    // 构建QStackedLayout对象和3个子界面对象
    QStackedLayout* pStackLayout = new QStackedLayout(this);
    CStep1* pWidgetStep1 = new CStep1(this);
    CStep2* pWidgetStep2 = new CStep2(this);
    CStep3* pWidgetStep3 = new CStep3(this);

    // 将3个子界面对象添加到堆栈布局pStackLayout
    pStackLayout->addWidget(pWidgetStep1);
    pStackLayout->addWidget(pWidgetStep2);
    pStackLayout->addWidget(pWidgetStep3);

    // 设置默认页
    pStackLayout->setCurrentIndex(0);
    // 将堆栈布局对象添加到父窗口的对应布局。
    ui.horizontalLayout->addLayout(pStackLayout);

    connect(pWidgetStep1, &CStep1::showpage, 
            pStackLayout, &QStackedLayout::setCurrentIndex);
    connect(pWidgetStep2, &CStep2::showpage,
        pStackLayout, &QStackedLayout::setCurrentIndex);
    connect(pWidgetStep3, &CStep3::showpage,
        pStackLayout, &QStackedLayout::setCurrentIndex);

    connect(pWidgetStep3, &CStep3::closeWindow,
        this, &CDialog::close);

}