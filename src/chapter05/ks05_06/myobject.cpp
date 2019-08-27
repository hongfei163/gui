﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: myobject.cpp
\brief  CMyObject类的实现文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/9
*/
#include <QDebug>

#include "myobject.h"

CMyObject::CMyObject() {	

}

CMyObject::~CMyObject() {

}


void CMyObject::slot_addressSaved(const QString& strAddress) {

    QString str = "--------------------";
    qDebug() << str;

    str = "The new address is:";
    str += strAddress;
    qDebug() << str;

}
