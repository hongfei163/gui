/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: rectitem.cpp
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#include "rectitem.h"

#include <QPainter>

CGraphRectItem::CGraphRectItem(QGraphicsItem * parent /* = 0 */)
    :QGraphicsItem(parent)
{
}


CGraphRectItem::~CGraphRectItem()
{
}

void CGraphRectItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget/* = 0*/)
{
	Q_UNUSED(widget);
    painter->drawPath(shape());
	
}
QRectF CGraphRectItem::boundingRect() const
{
	QRectF boundRt(-m_width/2, -m_height/2, m_width, m_height);	
	return boundRt;
}
QPainterPath CGraphRectItem::shape() const
{
	QPainterPath paintPath;
    paintPath.addRect(boundingRect());
	return paintPath;
}
