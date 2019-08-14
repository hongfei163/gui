/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: widget.h
\brief  CWidget�ඨ��ͷ�ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widgetbase.h" // ͷ�ļ���������: dialogbase.ui  ---> ui_widgetbase.h


// �������������ui�ļ��жԻ��������������鿴���е�����
class CWidget : public QWidget 
{
	Q_OBJECT
public:
	CWidget(QWidget* pParent);
	~CWidget();

private slots:
	void on_fontFamilyChanged(const QFont &font);
	void on_fontSizeChanged(int);

private:
    void initialStyleSheet();
private:
    Ui::CWidgetBase ui;
};

#endif  // WIDGET_H