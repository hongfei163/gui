/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: rectitem.h
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#ifndef RECTGRAPHITEM_H
#define RECTGRAPHITEM_H

#include "itembase.h"

class  CGraphRectItem : public CGraphItemBase
{
public:
    CGraphRectItem(QGraphicsItem * parent = 0);

    virtual int type() const { return QGraphicsItem::UserType+1; }

	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	/**
		 * @brief boundingRect()��ȡ���Ӿ���
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
    /**
    * @brief setWidth�����þ��ο�
    *
    * @param[in] dW  ��
    */
    void setWidth(qreal dW) { m_width = dW; }
    /**
    * @brief getWidth() ��ȡ���ο�
    *
    * @return ��
    */
    qreal getWidth() const { return m_width; }

    /**
    * @brief setHeight�����þ��θ�
    *
    * @param dH  ��
    */
    void setHeight(qreal dH) { m_height = dH; }
    /**
    * @brief getHeight() ��ȡ���θ�
    *
    * @return ��
    */
    qreal getHeight() const { return m_height; }

protected:
	/// ��������
	virtual ~CGraphRectItem();
private:
    qreal m_width;
    qreal m_height;
};


#endif  // RECTGRAPHITEM_H
