/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: simpledialog.h
\brief  CSimpleDialog类的定义文件

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef SIMPLEDIALOG_H
#define SIMPLEDIALOG_H

#include "ui_simpledialogbase.h" // 头文件名称来自: simpledialogbase.ui  ---> ui_simpledialogbase.h


// 父类的名称来自ui文件中对话框的类名：对象查看器中的类名
class CSimpleDialog : public QDialog
{
    Q_OBJECT
public:
    CSimpleDialog(QWidget* pParent);
    ~CSimpleDialog();

public slots:
    void slot_AddressSaved(const QString&);
private:
    Ui::CSimpleDialogBase ui;
};
#endif // SIMPLEDIALOG_H