/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: ellipseitem.cpp
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#include "ellipseitem.h"

#include <QPainter>

CGraphEllipseItem::CGraphEllipseItem(QGraphicsItem * parent /* = 0 */)
    :QGraphicsItem(parent)
{
}


CGraphEllipseItem::~CGraphEllipseItem()
{
}

void CGraphEllipseItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget/* = 0*/)
{
	Q_UNUSED(widget);
    painter->drawEllipse(boundingRect());
	
}
QRectF CGraphEllipseItem::boundingRect() const
{
	QRectF boundRt(-m_width/2, -m_height/2, m_width, m_height);	
	return boundRt;
}
QPainterPath CGraphEllipseItem::shape() const
{
	QPainterPath paintPath;
    paintPath.addRect(boundingRect());
	return paintPath;
}
