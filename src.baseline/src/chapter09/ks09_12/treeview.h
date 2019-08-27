/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file treeview.h
\brief treeviewͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
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
