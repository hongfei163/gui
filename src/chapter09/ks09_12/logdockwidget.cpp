/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: logdockwidget.cpp
\brief ��־������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/01
*/

#include <QListWidget>
#include <QTableWidget>
#include <QHeaderView>

#include "logdockwidget.h"
#include "logevt.h"


const int maxLogNum = 1000;	// ��־������ʾ��������־��Ŀ

/**
* @brief ���캯��
* @param[in] title	��־�������ı���
* @param[in] parent ��־�������ĸ�����
* @param[in] flags	��־�������ı�־
*/
CLogDockWidget::CLogDockWidget(const QString &title, QWidget *parent/* = 0*/, Qt::WindowFlags flags/* = 0*/) : QDockWidget(title, parent, flags), m_pTableWidget(NULL)
{
	Q_UNUSED(title);
	Q_UNUSED(parent);
	Q_UNUSED(flags);
	m_pTableWidget = new QTableWidget(this);
	m_pTableWidget->setColumnCount(3);
	QFont font = m_pTableWidget->horizontalHeader()->font();	// ���ñ�ͷ�����Ӵ�
	font.setBold(true);
	m_pTableWidget->horizontalHeader()->setFont(font);
	m_pTableWidget->horizontalHeader()->setFixedHeight(25); //���ñ�ͷ�ĸ߶�
	m_pTableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	m_pTableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("ʱ��") << QString::fromLocal8Bit("����"));
	m_pTableWidget->setColumnWidth(0, 100);
	m_pTableWidget->setColumnWidth(1, 100);
	m_pTableWidget->horizontalHeader()->setStretchLastSection(true);
	m_pTableWidget->setShowGrid(false); //���ò���ʾ������
	m_pTableWidget->verticalHeader()->setHidden(true);	// ���ô�ֱ��ͷ���ɼ�
	m_pTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //���ñ�ͷ����ɫ
	setWidget(m_pTableWidget);
}

//! ��������
CLogDockWidget::~CLogDockWidget()
{

}

/**
* @brief ����־����������ʾ��־
* @param[in] QEvent	��־�¼�
*/
void CLogDockWidget::customEvent(QEvent* e)
{
	CLogEvt* pLogEvt = dynamic_cast<CLogEvt*>(e);
	
	if (NULL != pLogEvt)
	{
		SLog log = pLogEvt->getLog();

		int rowIndex = m_pTableWidget->rowCount();
		while (rowIndex >= maxLogNum)
		{//ɾ��������
			m_pTableWidget->removeRow(rowIndex - 1);
			rowIndex--;
		}		
		//��������Զ�ӵ���ǰ��
		m_pTableWidget->insertRow(0);
		m_pTableWidget->setItem(0, 0, new QTableWidgetItem(SLog::translateLevel(log.level)));
		m_pTableWidget->setItem(0, 1, new QTableWidgetItem(log.time.toString()));
		m_pTableWidget->setItem(0, 2, new QTableWidgetItem(log.msg));
	}
}