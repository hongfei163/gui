#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h" // ͷ�ļ���������: dialog.ui  ---> ui_dialog.h


// ��������������ui�ļ��жԻ����������������鿴���е�����
class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

private Q_SLOTS:
	void onChecked(bool checked);
private:
    Ui::CDialog ui;
};

#endif