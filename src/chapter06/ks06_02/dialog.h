/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: dialog.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/8 
*/

#pragma once

#include "ui_dialog.h"
#include <QDialog>


class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* parent);
    ~CDialog(){}
private slots:
    /*
     *  @brief ����OK��ťʱ��Ӧ�Ĳۺ���
     *  @return void
    */
    void slot_accepted();
private:
    Ui::CDialog ui;
};


