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

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>

class CCustomWidget;

class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* parent);
	~CDialog(){;}

protected:
    /*
     *  @brief ��д����� paintEvent()
     *  @param[in] event ˢ���¼�����ָ��
    */
    virtual void paintEvent(QPaintEvent *event);
private:
	Ui::CDialog ui;
	CCustomWidget* m_pWidget;
};

#endif 
