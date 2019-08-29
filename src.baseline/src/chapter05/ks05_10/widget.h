/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: widget.h
\brief  CWidget类定义头文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h" // 头文件名称来自: dialog.ui  ---> ui_widget.h


// 父类的名称来自ui文件中对话框的类名：对象查看器中的类名
class CWidget : public QWidget 
{
	Q_OBJECT
public:
	CWidget(QWidget* pParent);
	~CWidget();

protected:

private slots:
	void slot_fontFamilyChanged(const QFont &font);
	void slot_fontSizeChanged(int);
private:
    Ui::CWidget ui;
};

#endif  // WIDGET_H