/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file tableview.cpp
\brief tableviewʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#include <QtWidgets>

#include "tableview.h"

void CTableView::mousePressEvent(QMouseEvent *event)
{
	QPoint pos = event->pos();
	QPersistentModelIndex index = indexAt(pos);
	// ��������ѡ�����ϴβ�һ��������Ҫ�ر��ϴεı༭��
	if ((index != m_indexLast) && m_indexLast.isValid()) {
		closePersistentEditor(m_indexLast);
	}
	m_indexLast = index;
	if (index.isValid() && (1==index.column())) {
		// �򿪱༭�������༭״̬
		openPersistentEditor(index);
	}
	QTableView::mousePressEvent(event);
}