/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: dialog.h
\brief  CDialog ���Ķ����ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h" // ͷ�ļ���������: dialog.ui  ---> ui_dialog.h

class CMyObject;

// ��������������ui�ļ��жԻ����������������鿴���е�����
class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

Q_SIGNALS:
    void signal_addressSaved(const QString&); // CDialog���ź�

private slots:
	void slot_addressSaved(const QString&);
private:
	void initialDialog();

private:
    Ui::CDialog ui;
};

#endif // DIALOG_H