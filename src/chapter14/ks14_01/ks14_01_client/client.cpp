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

#include <QtWidgets>
#include <QtNetwork>
#include "client.h"


Client::Client(QWidget* pParent) : QDialog(pParent), tcpSocket(new QTcpSocket(this)), networkSession(NULL)
{
    setupUi();

    connectSignalAndSlots();
 
    initialSession();

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

    ui.btnGetData->setDefault(true);
    ui.btnGetData->setEnabled(false);
    ui.hostCombo->setEditable(true);

    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_11);

}
void Client::connectSignalAndSlots()
{
    connect(ui.hostCombo, &QComboBox::editTextChanged,
        this, &Client::enableGetDataButton);
    connect(ui.portLineEdit, &QLineEdit::textChanged,
        this, &Client::enableGetDataButton);
    connect(ui.btnGetData, &QAbstractButton::clicked,
        this, &Client::requestNewData);
    connect(ui.btnQuit, &QAbstractButton::clicked, this, &QWidget::close);

    connect(tcpSocket, &QIODevice::readyRead, this, &Client::readyToRead);

    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Client::displayError);

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
        connect(networkSession, &QNetworkSession::opened, this, &Client::sessionOpened);

        ui.btnGetData->setEnabled(false);
        ui.statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
}

Client::~Client()
{
	
}
void Client::requestNewData()
{
    ui.btnGetData->setEnabled(false);
    tcpSocket->abort();
    
    tcpSocket->connectToHost(ui.hostCombo->currentText(),
        ui.portLineEdit->text().toInt());
}

void Client::readyToRead()
{
    in.startTransaction();

    QTime tm;
    QString str;
    in >> tm;
    in >> str;

    if (!in.commitTransaction())
        return;

    QString strInfo;
    strInfo.sprintf("%02d:%02d:", tm.minute(), tm.second());
    strInfo += str;
    ui.statusLabel->setText(strInfo);
    ui.btnGetData->setEnabled(true);
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
    //    QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"), QString::fromLocal8Bit("�޷����ӵ�������������ע���������˿ں��Ƿ���ȷ."));
         QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"), QString::fromLocal8Bit(""));
       break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"),
            QString::fromLocal8Bit("���ӱ��Է��رա���ȷ�Ϸ����˴�������״̬���������������ơ��˿ںš�"));
        break;
    default:
        QMessageBox::information(this, QString::fromLocal8Bit("�ͻ���"),
            QString::fromLocal8Bit("���г�����������Ϣ:%1.")
            .arg(tcpSocket->errorString()));
    }

    ui.btnGetData->setEnabled(true);
}

void Client::enableGetDataButton()
{
    ui.btnGetData->setEnabled((!networkSession || networkSession->isOpen()) &&
        !ui.hostCombo->currentText().isEmpty() &&
        !ui.portLineEdit->text().isEmpty());

}

void Client::sessionOpened()
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

    enableGetDataButton();
}



