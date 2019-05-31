/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: clientthread.cpp
\brief  CClientConnection

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/4
*/
#include "clientconnection.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "task.h"
/////////////////////////////////////////////////////////////////
CClientConnection::CClientConnection(QTcpSocket* pClientSocket, QObject *parent)
    : QObject(parent)
    , m_pClientSocket(pClientSocket)  {

    m_inStream.setDevice(m_pClientSocket);
    m_inStream.setVersion(QDataStream::Qt_5_11); 

    m_outSream.setDevice(m_pClientSocket);
    m_outSream.setVersion(QDataStream::Qt_5_11);
}

CClientConnection::~CClientConnection() {
}

void CClientConnection::sendDeal() {
    CTask * pTask = takeOneTask();
    if (NULL != pTask) {
        pTask->sendFrame(m_outSream);
        delete pTask;
    }
}
void CClientConnection::disconnect()
{
    if (NULL != m_pClientSocket) {
        m_pClientSocket->disconnectFromHost();
        m_pClientSocket->waitForDisconnected();
    }
}
void CClientConnection::addTask(CTask* pTask) {
    QMutexLocker locker(&m_mtxTask);
    m_tasks.append(pTask);
}
CTask * CClientConnection::takeOneTask()
{
    CTask * pTask = NULL;
    QMutexLocker locker(&m_mtxTask);
    if (m_tasks.size() > 0) {
        pTask = m_tasks[0];
        m_tasks.removeAt(0);
    }
    return pTask;
}