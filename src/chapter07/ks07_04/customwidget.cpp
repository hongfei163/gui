/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: customwidget.cpp
\brief	
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9 

*/
#include "customwidget.h"
#include <QLabel>
#include <QLineF>
#include <QMovie>
#include <QPainter>
#include <QPaintEvent>
#include <QPointF>


CCustomWidget::CCustomWidget(QWidget* parent) : QWidget(parent)
{
	
}




void CCustomWidget::paintEvent(QPaintEvent *event)
{	
	QWidget::paintEvent(event);
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	
	// 画笔
	QPen pn;
	pn.setColor(Qt::blue);		// 蓝色画笔
	pn.setStyle(Qt::DashLine);	// 线型-划线
	pn.setWidthF(10);			// 宽度-10
	pn.setCapStyle(Qt::RoundCap);// 顶端-圆形
	pn.setJoinStyle(Qt::RoundJoin);// 拐点-圆形
	painter.setPen(pn);

	// 帽子-直线
	QLine line;
	
    QVector<QPoint>::iterator ite = m_points.begin();

    for (; ite != m_points.end() && (ite+1)!=m_points.end(); ite+=2)   {
        line.setP1(*ite);
        line.setP2(*(ite + 1));
        painter.drawLine(line);
    }

	painter.end();
}

void CCustomWidget::mousePressEvent(QMouseEvent *event)
{

}

void CCustomWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pt = event->pos();
    m_points.push_back(pt);
    update();
}
