/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: client.h
\brief  Client�ඨ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#pragma once

#include "ui_client.h" // ͷ�ļ���������: client.ui  ---> ui_client.h
#include <QDataStream>
#include <QAbstractSocket>


QT_BEGIN_NAMESPACE
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

class Client : public QDialog
{
	Q_OBJECT
public:
    Client(QWidget* pParent);
	~Client();

private slots:
    void requestNewData();
    void readyToRead();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetDataButton();
    void sessionOpened();
private:
    void setupUi();
    void connectSignalAndSlots();
    void initialSession();
private:
    Ui::Client ui;
    QTcpSocket *tcpSocket;
    QDataStream in;
    QNetworkSession *networkSession;

};

