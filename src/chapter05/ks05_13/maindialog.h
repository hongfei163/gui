/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: maindialog.h
\brief  CMainDialog类定义头文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QPixmap>

#include "ui_maindialog.h" // 头文件名称来自: maindailog.ui  ---> ui_maindialog.h

QT_BEGIN_NAMESPACE
class QMovie;
class QTimer;
QT_END_NAMESPACE

// 父类的名称来自ui文件中对话框的类名：对象查看器中的类名
class CMainDialog : public QDialog
{
	Q_OBJECT
public:
	CMainDialog(QWidget* pParent);
	~CMainDialog();

protected:

private slots:
    void slot_timeOut();
	void onStartStop();
private:
	
	void initialDialog();
private:
	bool	m_bStart;
	Ui::CMainDialog ui;
	QPixmap	m_png[4];
	QMovie* m_movie;
	int		m_idx;

    QTimer  * m_pTimer;
};

#endif