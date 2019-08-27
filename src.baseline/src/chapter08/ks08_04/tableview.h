/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file tableview.h
\brief tableviewͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#ifndef CTABLEVIEW_H
#define CTABLEVIEW_H

#include <QTableView>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class CTableView : public QTableView
{
    Q_OBJECT

public:
	explicit CTableView(QWidget *parent = nullptr):QTableView(parent) {}

signals:

protected:
	virtual void mousePressEvent(QMouseEvent *event) override;

private:
	QModelIndex m_indexLast;
};

#endif
