/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: maindialog.h
\brief  CMainDialog�ඨ��ͷ�ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "ui_maindialogbase.h" // ͷ�ļ���������: maindailogbase.ui  ---> ui_maindialogbase.h


// �������������ui�ļ��жԻ��������������鿴���е�����
class CMainDialog : public QDialog 
{
	Q_OBJECT
public:
	CMainDialog(QWidget* pParent);
	~CMainDialog();

private slots:
	void initialDialog();

private:
    Ui::CMainDialogBase ui;
};

#endif