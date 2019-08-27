/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: logdockwidget.h
\brief ��־�����ඨ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/01
*/

#ifndef LOGDOCKWIDGET_H
#define LOGDOCKWIDGET_H

#include <QDockWidget>


class QTableWidget;

class CLogDockWidget : public QDockWidget
{
public:
	CLogDockWidget(const QString &title, QWidget *parent = 0, Qt::WindowFlags flags = 0);
	virtual ~CLogDockWidget();

protected:
	void customEvent(QEvent* e) Q_DECL_OVERRIDE;

private:
	QTableWidget *m_pTableWidget;
};

#endif		// LOGDOCKWIDGET_H