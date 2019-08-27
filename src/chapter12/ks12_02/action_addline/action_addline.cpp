/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: action_addline.cpp
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/3
*/

#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QWidget>

#include "action_addline.h"

extern "C"
{
	/// ����action
    CActionObjectInterface* createAction(int i)
	{
        CActionAddLineObject* pObject1 = new CActionAddLineObject;
        CActionObjectInterface* pObject = pObject1;
        QAction* pAction = NULL;
        pAction = new QAction(QObject::tr("addline"), pObject);
        pAction->setStatusTip(QObject::tr("add line"));
        pObject->setAction(pAction);
        QObject::connect(pAction, &QAction::triggered, pObject1, &CActionAddLineObject::slot_addLine);
        return pObject;
	}
};

void CActionAddLineObject::slot_addLine()
{
    static double s_PosX = 0.f;
    static double s_PosY = 0.f;
    QGraphicsView* pView = getView();
    QGraphicsScene* pScene = pView->scene();
    QGraphicsLineItem* pItem = new QGraphicsLineItem();
    pItem->setLine(s_PosX, s_PosY, 100., 100.f);
    pScene->addItem(pItem);

    s_PosX += 60.f;
    s_PosY += 30.f;
}