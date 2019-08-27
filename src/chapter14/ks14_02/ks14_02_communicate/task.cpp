/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: task.cpp
\brief  CTask

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/4
*/
//#include <QtNetwork>
//#include <QTcpSocket>
#include "task.h"

CTask::CTask()
{   

}

CTask::~CTask() {

}

ETASKTYPE CTask::parseTaskType(QDataStream& in) {
    ETASKTYPE taskType = ETASK_INVALID;

    qint32 iVal = -1;
    in >> iVal;

    taskType = static_cast<ETASKTYPE>(iVal);
    return taskType;
}

CTask* CTask::createTask(ETASKTYPE taskType) {
    switch (taskType) {
    case ETASK_HELLO:
        return new CHelloTask;
    case ETASK_SETONEDATA:
        return new CSetOneDataTask;
    case ETASK_GETONEDATA:
        return new CGetOneDataTask;
    case ETASK_ONEDATARETURNED:
        return new COneDataReturnedTask;
    default:
        break;
    }

    return NULL;
}

///////////////////////////////////////////////////////
void CHelloTask::sendFrame(QDataStream& out) {
    qint32 iTaskType = ETASK_HELLO;
    out << iTaskType;
    out << m_str;
}

void CHelloTask::parseFrame(QDataStream& inStream) {
    inStream >> m_str;
}

///////////////////////////////////////////////////////
void CSetOneDataTask::sendFrame(QDataStream& out) {
    qint32 iTaskType = taskType();
    out << iTaskType;
    out << m_dataId;
    out << m_dataValue;
}

void CSetOneDataTask::parseFrame(QDataStream& inStream) {
    inStream.setVersion(QDataStream::Qt_5_11);
    inStream >> m_dataId;
    inStream >> m_dataValue;
}



