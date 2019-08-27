/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: customwidget.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

#include "ui_customwidget.h"

class CCustomWidget : public QWidget
{
public:
	CCustomWidget(QWidget* parent);
	~CCustomWidget(){;}

protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	void initialize();

private:
	Ui::CCustomWidget ui;
	QMovie*	m_movie;
	QLabel* m_transparentLabel;
};

#endif // CUSTOMWIDGET_H