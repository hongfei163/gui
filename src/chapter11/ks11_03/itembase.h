/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: itembase.h
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#ifndef ITEMBASE_H
#define ITEMBASE_H

#include <QGraphicsItem>

class  CGraphItemBase : public QGraphicsItem
{
public:
    CGraphItemBase(QGraphicsItem * parent = 0):QGraphicsItem(parent) { ; }
    virtual int type() const { return QGraphicsItem::UserType; }

    /**
    * @brief ��ȡ���ξ���(ͼԪ����ϵ)
    * @return ���ξ���
    */
    virtual QRectF  getItemRect() const =0 ;
    
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
    virtual ~CGraphItemBase() { ; }
private:
    qreal m_width;
    qreal m_height;
};


#endif  // ELLIPSEGRAPHITEM_H
