/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: step3.h
\brief  �Ի�������ʾ��, Ԥ�������ඨ��ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/7
*/

#pragma once

#include <QWidget>

#include "ui_step3.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class CStep3 : public QWidget
{
    Q_OBJECT

public:
    /// ���캯��
    CStep3(QWidget *parent = 0);



private:
    Ui::CStep3 ui;
};



