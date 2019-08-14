/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.h
\brief  CDialog 类的定义文件

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialogbase.h" // 头文件名称来自: dialogbase.ui  ---> ui_dialogbase.h


// 父类的名称来自ui文件中对话框的类名：对象查看器中的类名
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