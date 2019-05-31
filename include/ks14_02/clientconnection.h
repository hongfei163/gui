/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: clientconnection.h
\brief  CClientConnection

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/
#pragma once

#include <QByteArray>
#include <QList>
#include <QMutex>
#include <QObject>

#include "task.h"
#include "ks14_02.h"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE


class KS14_02_API CClientConnection : public QObject
{
    Q_OBJECT
public:
    /**
    *	@brief 构造函数。
    *	@param[in|out] pSocket socket指针
    *	@param[in|out] parent 父指针
    *   @return 无
    */
    CClientConnection(QTcpSocket* pSocket, QObject *parent = nullptr);
	~CClientConnection();

    /**
    *	@brief 添加任务。该任务对象在sendDeal()内部将被释放。
    *	@param[in|out] pTask 任务指针
    *   @return void
    */
    void addTask(CTask* pTask);
 
    /**
    *	@brief 组帧并发送，内部调用takeOneTask,并将被发送的任务对象释放。
    *   @return void
    */
    void sendDeal();
    /**
    *	@brief 关闭连接。
    *   @return void
    */
    void disconnect();

protected:
    /**
    *	@brief 获取下一个任务，并将其从队列删除
    *   @return void
    */
    CTask* takeOneTask();
private:
    QTcpSocket* m_pClientSocket; /// 客户端连接
    QMutex      m_mtxTask;
    QMutex      m_mtxRecvBlock;
    QList<CTask*> m_tasks;
    QDataStream  m_outSream;    /// 发送流对象   
    QDataStream  m_inStream;    /// 接收流对象
};