/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: server.h
\brief  CServer

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/
#pragma once

#include <QObject>


QT_BEGIN_NAMESPACE
class QTcpServer;
QT_END_NAMESPACE

class CServer : public QObject 
{
    Q_OBJECT
public:
    CServer();
	~CServer();

    bool startListen();

public slots:
    void sendData();
private:
    QTcpServer * tcpServer = nullptr;

};