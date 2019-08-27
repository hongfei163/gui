#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h" // 头文件名称来自: dialog.ui  ---> ui_dialog.h


// 父类的名称来自ui文件中对话框的类名：对象查看器中的类名
class CDialog : public QDialog
{
	Q_OBJECT 
public:
	CDialog(QWidget* pParent);
	~CDialog();
private:
    Ui::CDialog ui;
};

#endif