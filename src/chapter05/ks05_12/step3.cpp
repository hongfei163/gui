/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: step3.cpp
\brief  �Ի�����ʾ��, Ԥ��������ʵ���ļ�
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
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