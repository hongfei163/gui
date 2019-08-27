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
    :CGraphItemBase(parent)
{
}


CGraphEllipseItem::~CGraphEllipseItem()
{
}

void CGraphEllipseItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget/* = 0*/)
{
	Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->drawEllipse(boundingRect());	
}

QRectF  CGraphEllipseItem::getItemRect() const
{
    QRectF rct(-getWidth()/2, -getHeight()/2, getWidth(), getHeight());
    return rct;
}

QRectF CGraphEllipseItem::boundingRect() const
{
    QRectF boundRt(-getWidth() / 2 - 2, -getHeight() / 2 - 2, getWidth() + 4, getHeight() + 4);
    return boundRt;
}
QPainterPath CGraphEllipseItem::shape() const
{
	QPainterPath paintPath;
    paintPath.addRect(getItemRect());
	return paintPath;
}
