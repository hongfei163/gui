/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: client.h
\brief  Client类定义头文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/

#pragma once

#include "ui_client.h" // 头文件名称来自: client.ui  ---> ui_client.h
#include <QDataStream>
#include <QAbstractSocket>


QT_BEGIN_NAMESPACE
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

class CClientConnection;

class Client : public QDialog
{
	Q_OBJECT
public:
    Client(QWidget* pParent);
	~Client();

private slots:
    void slot_connectToServer();
    void slot_SetOneData();
    void slot_GetOneData();
    void slot_readyToRead();
    void slot_displayError(QAbstractSocket::SocketError socketError);
    void slot_sessionOpened();
private:
    void setupUi();
    void connectSignalAndSlots();
    void initialSession();
private:
    Ui::Client ui;
    QTcpSocket * m_pTcpSocket;
    QDataStream m_inStream;
    QNetworkSession *networkSession;
    CClientConnection* m_pClientConnection;
};

