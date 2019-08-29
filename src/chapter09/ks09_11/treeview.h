/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file treeview.h
\brief treeview头文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/1
*/

#ifndef CTREEVIEW_H
#define CTREEVIEW_H

#include <QTreeView>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class CTreeView : public QTreeView
{
    Q_OBJECT

public:
	explicit CTreeView(QWidget *parent = nullptr):QTreeView(parent) {}

signals:
	void itemDoubleClicked(const QString&);
protected:
	//virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
	QModelIndex m_indexLast;
};

#endif
