/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: action_addline.h
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/3
*/

#ifndef ACTION_ADDLINE_H
#define ACTION_ADDLINE_H

#ifdef WIN32		// windows platform
#	if defined __ACTION_ADDLINE_SOURCE__
#		define EXPORT_ACTION_ADDLINE __declspec(dllexport)
#	else
#		define EXPORT_ACTION_ADDLINE __declspec(dllimport)
#	endif
#else				// other platform
#  define EXPORT_ACTION_ADDLINE
#endif // WIN32

#include "qglobal.h"
#include "ks12_02/action_interface.h"

QT_BEGIN_NAMESPACE
class QAction;
class QWidget;
class QGraphicsView;
QT_END_NAMESPACE

class CActionObject;
// ��ȡ����ָ���ĵ�������
extern "C"
{
    EXPORT_ACTION_ADDLINE CActionObjectInterface* createAction(int i);
};

class CActionAddLineObject : public CActionObjectInterface
{
    Q_OBJECT
public:
    CActionAddLineObject() :CActionObjectInterface(){ ; }
    ~CActionAddLineObject() {}
public:
public slots:
    void slot_addLine();
private:
};
#endif // ACTION_ADDLINE_H
