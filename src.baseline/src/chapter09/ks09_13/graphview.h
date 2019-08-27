/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: graphview.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QMouseEvent;
QT_END_NAMESPACE

class CGraphView : public QGraphicsView
{
	Q_OBJECT
public:
	CGraphView(QWidget* parent);
    ~CGraphView();

public:
    QPointF getMousePressPoint() { return m_ptView; }///��ȡ���굥����������
    void addEllipse();
    void addRect();

Q_SIGNALS:
    void viewMouseMove(const QPointF&);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void drawBackground(QPainter *painter, const QRectF &rect);

Q_SIGNALS:

private:
    QPointF m_ptView;
    QPointF m_ptScene;
};

#endif // TEXTEDIT_H