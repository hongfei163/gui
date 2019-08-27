/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: simpledialog.h
\brief  CSimpleDialog���Ķ����ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef SIMPLEDIALOG_H
#define SIMPLEDIALOG_H

#include <QDialog>
#include "ui_simpledialog.h" // ͷ�ļ���������: simpledialog.ui  ---> ui_simpledialog.h


// ��������������ui�ļ��жԻ����������������鿴���е�����
class CSimpleDialog : public QDialog
{
	Q_OBJECT
public:
	CSimpleDialog(QWidget* pParent);
	~CSimpleDialog();

private:
    Ui::CSimpleDialogBase ui;
};

#endif // SIMPLEDIALOG_H