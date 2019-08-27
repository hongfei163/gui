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
    :CGraphItemBase(parent)
{
}


CGraphRectItem::~CGraphRectItem()
{
}

void CGraphRectItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget/* = 0*/)
{
	Q_UNUSED(widget);
	Q_UNUSED(option);
    painter->drawPath(shape());	
}
QRectF  CGraphRectItem::getItemRect() const
{
    QRectF rct(-getWidth() / 2, -getHeight() / 2, getWidth(), getHeight());
    return rct;
}

QRectF CGraphRectItem::boundingRect() const
{
	QRectF boundRt(-getWidth() /2-2, -getHeight() /2-2, getWidth() +4, getHeight() +4);
	return boundRt;
}
QPainterPath CGraphRectItem::shape() const
{
	QPainterPath paintPath;
    paintPath.addRect(getItemRect());
	return paintPath;
}
