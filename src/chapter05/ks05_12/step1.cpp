/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: step1.cpp
\brief  �Ի�������ʾ��, Ԥ��������ʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
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
    emit sig_showPage(1); // ���Ŵ�0��ʼ, step1�����ǵ�0����������һ��Ҫ��ʾ��1����
}