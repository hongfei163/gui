/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: dialog.h
\brief  CDialog ��Ķ����ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialogbase.h" // ͷ�ļ���������: dialogbase.ui  ---> ui_dialogbase.h


// �������������ui�ļ��жԻ��������������鿴���е�����
class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();


Q_SIGNALS:
    void sig_addressUpdated(const QString&);
private:
	void initialDialog();

private:
    Ui::CDialogBase ui;
};

#endif // DIALOG_H