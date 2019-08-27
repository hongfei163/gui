/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: logevt.cpp
\brief ��־������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/01
*/

#include "logevt.h"
#include <QObject>


CLogEvt::CLogEvt(ELogEvt nType) : QEvent((QEvent::Type)nType)
{
}

CLogEvt::~CLogEvt()
{
}

SLog CLogEvt::getLog() const
{
	return m_log;
}

void CLogEvt::setLog(const SLog& log)
{
	m_log = log;
}

////////////////////////////////////////////////////////
QString SLog::translateLevel(ELogLevel level)
{
	switch (level)
	{
	case ELogLevel_Error:
		return QObject::tr("Error");
		break;
	case ELogLevel_Warning:
		return QObject::tr("Warning");
		break;
	case ELogLevel_Normal:
		return QObject::tr("Normal");
		break;
	default:
		break;
	}

	return QString::null;
}