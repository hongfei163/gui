﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: city.cpp
\brief 城市类实现文件

\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/10
*/

#include "city.h"

CCity::CCity() {
	;
}

CCity::~CCity() { 
	;
}

ESerializeCode  CCity::serializeBinary(QDataStream& ds, QString* pError) const {
	Q_UNUSED(pError);

	ds << m_strName;

	return ESERIALIZECODE_OK;
}