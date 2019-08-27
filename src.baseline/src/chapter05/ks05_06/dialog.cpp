/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: dialog.cpp
\brief  CDialog ����ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include "address.h"
#include "dialog.h"

#include "myobject.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent) {
    ui.setupUi(this);

	initialDialog();
}

CDialog::~CDialog(){

}
void CDialog::initialDialog() {
	
	// �����Զ����ؼ�����
	CWidgetAddress* pWidgetAddress = new CWidgetAddress(this);
	

	connect(pWidgetAddress, &CWidgetAddress::sig_addressSaved, this, &CDialog::slot_addressSaved);

	// ��Ҫ�����Զ�����
	QGridLayout *gridLayout_2;
	gridLayout_2 = new QGridLayout(this);
	gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
	gridLayout_2->addWidget(pWidgetAddress, 0, 0, 1, 1);

}


void CDialog::slot_addressSaved(const QString& strAddress){
	
	if (NULL != ui.m_plainTextEdit->document()) {
		QString str = "The Address is:" + strAddress;
        ui.m_plainTextEdit->document()->setPlainText(str);
	}
}

