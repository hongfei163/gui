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

#include "tableview.h"
#include <QtWidgets>

void CTableView::mousePressEvent(QMouseEvent* event) {

    QPoint pt = event->pos();
    QPersistentModelIndex index =  indexAt(pt);
    // ��������ѡ�����ϴβ�һ������Ҫ�ر��ϴεı༭��
    if ((index != m_indexLast) && m_indexLast.isValid()) {
        closePersistentEditor(m_indexLast);
    }

    m_indexLast = index;
    // �µ�������Ч�����������༭����
    if (index.isValid() && (1== index.column())){
        openPersistentEditor(index);
    }
    QTableView::mousePressEvent(event);
}


