/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: ellipseitem.h
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#ifndef ELLIPSEGRAPHITEM_H
#define ELLIPSEGRAPHITEM_H

#include "itembase.h"

class  CGraphEllipseItem : public CGraphItemBase
{
public:
    CGraphEllipseItem(QGraphicsItem * parent = 0);
    virtual int type() const { return QGraphicsItem::UserType + 2; }

	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	/**
		 * @brief boundingRect()��ȡ���Ӿ���(ͼԪ����ϵ)
		 * @return ���Ӿ���
	*/
	virtual QRectF  boundingRect() const;
    /**
    * @brief ��ȡ���ξ���(ͼԪ����ϵ)
    * @return ���ξ���
    */
    virtual QRectF  getItemRect() const;
    /**
		 * @brief ��ȡ��״
		 * ����������ײ����
		 * @return ��״
	*/
	virtual QPainterPath  shape() const;


protected:
	/// ��������
	virtual ~CGraphEllipseItem();
private:
};


#endif  // ELLIPSEGRAPHITEM_H
