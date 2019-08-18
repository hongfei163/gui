/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: customwidget.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QImage>

#include "ui_customwidgetbase.h"

class CCustomWidget : public QWidget
{
public:
	CCustomWidget(QWidget* parent);
	~CCustomWidget(){;}

protected:
    /*
     *  @brief ��д����� resizeEvent()
     *  @param[in] event QResizeEvent����ָ��
    */
    virtual void resizeEvent(QResizeEvent *event);
    /*
     *  @brief ��д����� paintEvent()
     *  @param[in] event ˢ���¼�����ָ��
    */
    virtual void paintEvent(QPaintEvent *event);
private:
	void initialize();

private:
	Ui::CCustomWidgetBase ui;
	QLabel* m_transparentLabel;
    QImage  m_img;
};

#endif // CUSTOMWIDGET_H
