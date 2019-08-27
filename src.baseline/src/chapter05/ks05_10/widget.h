/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: widget.h
\brief  CWidget�ඨ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h" // ͷ�ļ���������: dialog.ui  ---> ui_widget.h


// ��������������ui�ļ��жԻ����������������鿴���е�����
class CWidget : public QWidget 
{
	Q_OBJECT
public:
	CWidget(QWidget* pParent);
	~CWidget();

protected:

private slots:
	void slot_fontFamilyChanged(const QFont &font);
	void slot_fontSizeChanged(int);
private:
    Ui::CWidget ui;
};

#endif  // WIDGET_H