﻿/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: dialog.h
\brief  CDialog�ඨ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h" // ͷ�ļ���������: dialog.ui  ---> ui_dialog.h

class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

protected:

private slots:
	void slot_startthread();

private:
    Ui::CDialog ui;
};

#endif