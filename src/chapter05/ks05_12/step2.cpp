/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: step2.cpp
\brief  �Ի�������ʾ��, Ԥ��������ʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/7
*/


#include "step2.h"

CStep2::CStep2(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this); 

    connect(ui.btnPrevious, &QPushButton::clicked,
        this, &CStep2::slot_previous);

    connect(ui.btnNext, &QPushButton::clicked,
        this, &CStep2::slot_next);

}

void CStep2::slot_previous() {
    emit sig_showPage(0); // ���Ŵ�0��ʼ, step2�����ǵ�1����������һ��Ҫ��ʾ��0����
}

void CStep2::slot_next() {
    emit sig_showPage(2); // ���Ŵ�0��ʼ, step2�����ǵ�1����������һ��Ҫ��ʾ��2����

}