/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: simpledialog.h
\brief  CSimpleDialog��Ķ����ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef SIMPLEDIALOG_H
#define SIMPLEDIALOG_H

#include <QDialog>
#include "ui_simpledialogbase.h" // ͷ�ļ���������: simpledialogbase.ui  ---> ui_simpledialogbase.h


// �������������ui�ļ��жԻ��������������鿴���е�����
class CSimpleDialog : public QDialog
{
	Q_OBJECT
public:
	CSimpleDialog(QWidget* pParent);
	~CSimpleDialog();

public Q_SLOTS:
    void slot_updateAddress(const QString&);
private:
    Ui::CSimpleDialogBase ui;
};

#endif // SIMPLEDIALOG_H