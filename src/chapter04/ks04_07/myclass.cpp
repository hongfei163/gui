﻿/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: myclass.cpp

\brief	


\author 女儿叫老白   http://xingdianketang.cn/

\Date 2018/9 

*/
#include "myclass.h"


///////////////////////////////////////////////////////////////////
// CMyClass
CMyClass::CMyClass(const CMyClass& right) {
	initial(); // 必须调用该接口

	setId(right.getId());
	setName(right.getName());
}
void 	CMyClass::initial(){
	m_id = 0;
	m_pStrName = NULL;
}

CMyClass::~CMyClass() {
	if (NULL != m_pStrName) {
		delete m_pStrName;
		m_pStrName = NULL;
	}
}

void CMyClass::setName(const QString& str) {

	if (NULL == m_pStrName) {
		m_pStrName = new QString();
	}
	if (NULL == m_pStrName) {
		return;
	}

	*m_pStrName = str; 
}

QString CMyClass::getName() const { 
	return ((NULL == m_pStrName) ? QString() : *m_pStrName);
}
// a<b = false
// b<a = true
bool CMyClass::operator<(const CMyClass& right) const {
    if (getId() < right.getId()) {
        return true;
    }
    else if ((getId() == right.getId()) && (getName() < right.getName())) {
        return true;
    }
    else {
        return false;
    }
}

