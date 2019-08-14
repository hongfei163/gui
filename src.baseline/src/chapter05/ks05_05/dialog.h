/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: dialog.h
\brief  CDialog�ඨ��ͷ�ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialogbase.h" // ͷ�ļ���������: dialogbase.ui  ---> ui_dialogbase.h

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE


// �������������ui�ļ��жԻ��������������鿴���е�����
class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

private slots:
	void on_fontFamilyChanged(const QFont &font);
	void on_fontSizeChanged(int);
	void slot_selectionChanged();
	void slot_selectionChanged2();
	void on_setDefaultFont();
private:
	void updateFontWidget();
	void setTextFont(QLineEdit* pText, const QFont& newFont);
private:
	QLineEdit * m_pCurrentLabel;
    Ui::CDialogBase ui;
};

#endif