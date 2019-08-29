/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: widget.cpp
\brief  CWidget

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/

#include "widget.h"


CWidget::CWidget(QWidget* pParent) : QWidget(pParent) {
    ui.setupUi(this);
    ui.plainTextEdit->setPlainText("file detected:");

	connect(ui.cbFontSize, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_fontSizeChanged(int)));

	connect(ui.fontComboBox, &QFontComboBox::currentFontChanged, this, &CWidget::slot_fontFamilyChanged);
}

CWidget::~CWidget(){
	
}


void CWidget::slot_fontFamilyChanged(const QFont &font){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = font;
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}

void CWidget::slot_fontSizeChanged(int /*idx*/){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = ui.fontComboBox->currentFont();
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}
