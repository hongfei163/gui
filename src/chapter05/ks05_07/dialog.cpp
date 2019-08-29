/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.cpp
\brief  CDialog

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/

#include "customevent.h"
#include "dialog.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent) {
    ui.setupUi(this);
    ui.plainTextEdit->setPlainText("file detected:");

	//connect(ui.fontComboBox, SIGNAL(currentFontChanged(const QFont &)), this, SLOT(slot_fontFamilyChanged(const QFont &)));
	connect(ui.cbFontSize, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_fontSizeChanged(int)));

	connect(ui.fontComboBox, &QFontComboBox::currentFontChanged, this, &CDialog::slot_fontFamilyChanged);
	//connect(ui.cbFontSize, &QFontComboBox::currentIndexChanged, this, &CDialog::slot_fontSizeChanged);
}

CDialog::~CDialog(){
	
}


void CDialog::slot_fontFamilyChanged(const QFont &font){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = font;
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}

void CDialog::slot_fontSizeChanged(int /*idx*/){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = ui.fontComboBox->currentFont();
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}

void CDialog::customEvent(QEvent *event) {
	QString str;
	CCustomEvent* pEvent = NULL;
	switch (event->type()) {
	case (QEvent::User+1): 	{
			pEvent = dynamic_cast<CCustomEvent*>(event);
			if (NULL != pEvent) {
				str = ui.plainTextEdit->toPlainText();
				str += "\n";
				str += pEvent->getFileName();
                ui.plainTextEdit->setPlainText(str);
			}
		}
		break;
	default:
		break;
	}
}
