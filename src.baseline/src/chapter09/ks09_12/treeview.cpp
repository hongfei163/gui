/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file treeview.cpp
\brief treeviewʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#include <QMouseEvent>
#include <QStandardItemModel>

#include "treeview.h"

void CTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
	QPoint pos = event->pos();
	QPersistentModelIndex index = indexAt(pos);
	QAbstractItemModel* pModel = model();
	if (NULL != pModel) {
		QStandardItemModel* pStandardModel = dynamic_cast<QStandardItemModel*>(model());
		if (NULL != pStandardModel)	{
			QString str = pStandardModel->data(index).toString();
			emit itemDoubleClicked(str);
		}
	}

	QTreeView::mousePressEvent(event);
}