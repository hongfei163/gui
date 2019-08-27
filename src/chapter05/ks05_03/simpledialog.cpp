/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: simpledialog.cpp
\brief  CSimpleDialog����ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/
#include "simpledialog.h"


CSimpleDialog::CSimpleDialog(QWidget* pParent) : QDialog(pParent) {
    ui.setupUi(this);
    setWindowTitle("CSimpleDialog");
}

CSimpleDialog::~CSimpleDialog() {

}

void CSimpleDialog::slot_updateAddress(const QString& strAddress) {
   if (NULL != ui.m_plainTextEdit->document()) {
        ui.m_plainTextEdit->document()->setPlainText(strAddress);
    }
}


