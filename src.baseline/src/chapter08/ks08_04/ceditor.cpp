/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file ceditor.cpp
\brief CEditorʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/
#include <QtWidgets>

#include "ceditor.h"


CEditor::CEditor(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
}

void CEditor::paintEvent(QPaintEvent *e)
{
	QLabel::paintEvent(e);
    //QPainter painter(this);
	//painter.drawText(QPointF(0.f, 0.f), "")
    //myStarRating.paint(&painter, rect(), this->palette(),
    //                   StarRating::Editable);
}


void CEditor::mousePressEvent(QMouseEvent * /* event */)
{
	if (text() == "Y")
		setText("N");
	else
		setText("Y");
    emit editingFinished();
}
