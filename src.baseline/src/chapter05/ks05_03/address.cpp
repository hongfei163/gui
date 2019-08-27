/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: address.cpp
\brief  CWidgetAddress����ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/
#include "address.h"


CWidgetAddress::CWidgetAddress(QWidget* pParent) : QWidget(pParent) {
    ui.setupUi(this);

	//connect(ui.m_btnSave, SIGNAL(clicked()), this, SLOT(slot_addressSaved()));
	connect(ui.m_btnSave, &QPushButton::clicked,
        this, &CWidgetAddress::slot_btnSaveClicked);
}

CWidgetAddress::~CWidgetAddress(){
	
}


void CWidgetAddress::slot_btnSaveClicked(){
}

