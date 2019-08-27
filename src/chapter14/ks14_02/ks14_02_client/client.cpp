/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: dialog.cpp
\brief  CDialog

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include "client.h"
#include <QtWidgets>
#include <QtNetwork>
#include "task.h"
#include "clientconnection.h"


Client::Client(QWidget* pParent) 
    : QDialog(pParent)
    , m_pTcpSocket(new QTcpSocket(this))
    , networkSession(NULL)
    , m_pClientConnection(new CClientConnection(m_pTcpSocket, this))
{
    setupUi();
   
    connectSignalAndSlots();
 
    initialSession();
}

Client::~Client()
{
    m_pClientConnection->disconnect();
}

void Client::setupUi()
{
    ui.setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(QGuiApplication::applicationDisplayName());

    // ���һ�����
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        ui.hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui.hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        ui.hostCombo->addItem(QString("localhost"));

    // ���ұ���ip�б�
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // �ѷ�localhost��ip��ַ���ӵ�����
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            ui.hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    // ��localhost��ַ���ӵ�����
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            ui.hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    // ������Ч����
    ui.portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    ui.portLineEdit->setFocus();

    // ���ı���ǩ�Ŀ��ݼ���������Ӧ�Ŀؼ�(�������˿ں�)
    ui.hostLabel->setBuddy(ui.hostCombo);
    ui.portLabel->setBuddy(ui.portLineEdit);

    ui.btnConnect->setDefault(true);
    ui.btnGetData->setEnabled(false);
    ui.hostCombo->setEditable(true);

    m_inStream.setDevice(m_pTcpSocket);
    m_inStream.setVersion(QDataStream::Qt_5_11);

}
void Client::connectSignalAndSlots()
{
    connect(ui.btnConnect, &QAbstractButton::clicked,
        this, &Client::slot_connectToServer);
    connect(ui.btnSetData, &QAbstractButton::clicked,
        this, &Client::slot_SetOneData);
    connect(ui.btnGetData, &QAbstractButton::clicked,
        this, &Client::slot_GetOneData);
    connect(ui.btnQuit, &QAbstractButton::clicked, this, &QWidget::close);

    connect(m_pTcpSocket, &QIODevice::readyRead, this, &Client::slot_readyToRead);

    connect(m_pTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Client::slot_displayError);

}
void Client::initialSession()
{
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // ��ȡ��������
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // ����û�б������������ã�����ϵͳĬ��ֵ
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, &QNetworkSession::opened, this, &Client::slot_sessionOpened);

        ui.btnGetData->setEnabled(false);
        ui.statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
}


void Client::slot_SetOneData()
{
    CSetOneDataTask* pSetOneDataTask =  new CSetOneDataTask();
    pSetOneDataTask->setDataId(ui.leSetDataId->text().toInt());
    pSetOneDataTask->setDataValue(ui.leSetDataValue->text().toDouble());

    m_pClientConnection->addTask(pSetOneDataTask);
    m_pClientConnection->sendDeal();
}
void Client::slot_GetOneData()
{
    CGetOneDataTask* pGetOneDataTask = new CGetOneDataTask();
    pGetOneDataTask->setDataId(ui.leGetDataId->text().toInt());

    m_pClientConnection->addTask(pGetOneDataTask);
    m_pClientConnection->sendDeal();
}
void Client::slot_connectToServer()
{
    ui.btnGetData->setEnabled(false);
    m_pTcpSocket->abort();
    
    m_pTcpSocket->connectToHost(ui.hostCombo->currentText(),
        ui.portLineEdit->text().toInt());
}
void Client::slot_readyToRead()
{
    m_inStream.startTransaction();

    ETASKTYPE taskType = CTask::parseTaskType(m_inStream);
    CTask* pTask = CTask::createTask(taskType);
    if (NULL == pTask){
        m_inStream.rollbackTransaction();
        return;
    }

    pTask->parseFrame(m_inStream);

    if (!m_inStream.commitTransaction()) {
        delete pTask;  
        return;
    }        

    CHelloTask* pHelloTask = NULL;
    COneDataReturnedTask* pOneDataReturnedTask = NULL;
    QString str;
    QString strInfo;
    QTime tm = QTime::currentTime();
    strInfo.sprintf("%02d:%02d:%02d:", tm.hour(), tm.minute(), tm.second());

    switch (taskType)   {
    case ETASK_HELLO:
        pHelloTask = dynamic_cast<CHelloTask*>(pTask);
        if (NULL != pHelloTask) {
            str = pHelloTask->getString();
        }
        break;
    case ETASK_ONEDATARETURNED:
        str = "OneDataReturned From Server.";
        pOneDataReturnedTask = dynamic_cast<COneDataReturnedTask*>(pTask);
        if (NULL != pOneDataReturnedTask) {
            qint32 id = pOneDataReturnedTask->getDataId();
            qreal value = pOneDataReturnedTask->getDataValue();
            str = QString("%1").arg(id);
            ui.leGetDataId->setText(str);
            str = QString("%1").arg(value);
             ui.leGetDataValue->setText(str);
        }
        break;
    default:
        break;
    }
    
    strInfo += str;
    ui.statusLabel->setText(strInfo);
    ui.btnGetData->setEnabled(true);

    delete pTask;
}

void Client::slot_displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"), QString::fromLocal8Bit("�޷����ӵ�������������ע���������˿ں��Ƿ���ȷ."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"),
            QString::fromLocal8Bit("���ӱ��Է��رա���ȷ�Ϸ����˴�������״̬���������������ơ��˿ںš�"));
        break;
    default:
        QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"),
            QString::fromLocal8Bit("���г�����������Ϣ:%1.")
            .arg(m_pTcpSocket->errorString()));
    }

    ui.btnConnect->setEnabled(true);
}

void Client::slot_sessionOpened()
{
    // ������������
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice) {
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    }
    else {
        id = config.identifier();
    }
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    ui.statusLabel->setText(QString::fromLocal8Bit("The Server Needs to be run."));

}



