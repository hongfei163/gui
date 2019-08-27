/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: previewwindow.h
\brief  �Ի�������ʾ��, Ԥ�������ඨ��ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#pragma once

#include <QWidget>
#include "ui_prevwindow.h"

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class CPreviewWindow : public QWidget
{
    Q_OBJECT

public:
    /// ���캯��
    CPreviewWindow(QWidget *parent = 0);

    /**
    * @brief ���ô�����flags

    * @param[in] flags  ������flags
    * @return void
    */
    void setWindowFlags(Qt::WindowFlags flags);

private:
    Ui::CPreviewWindow ui;
};



