/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: country.cpp
\brief ʡ��ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#include "city.h"
#include "province.h"


// domԪ�ر�ǩ������
static const char* c_tag_city = "city";

// domԪ��������������
static const char* c_attribute_name = "name";


CProvince::CProvince() {
	;
}

CProvince::~CProvince() {
	QList<CCity*>::iterator iteLst = m_lstCities.begin();
	while (iteLst != m_lstCities.end()) {
		if (NULL != *iteLst) {
			delete *iteLst;
		}
		iteLst++;
	}

	m_lstCities.clear();
}

int CProvince::addCity(CCity* pCity) {
	if ((NULL == pCity) || (m_lstCities.contains(pCity))) {
		return m_lstCities.size();
	}

	m_lstCities.push_back(pCity);
	return m_lstCities.size();
}

ESerializeCode  CProvince::serializeBinary(QDataStream& ds, QString* pError) const {
	ds << m_strName;
	quint16 nCount = m_lstCities.size(); // ��Ҫ��ȷָ���������ͣ�������ƽ̨ʱ���ܳ����⡣����int�ڸ���ƽ̨�Ͽ��ܳ��Ȳ�һ����
	ds << nCount;
	QList<CCity*>::ConstIterator iteLst = m_lstCities.constBegin(); // ��Ϊ������Ϊconst��������Ҫ����const���͵Ľӿ�
	while (iteLst != m_lstCities.end()) {
		(*iteLst)->serializeBinary(ds, pError);
		iteLst++;
	}

	return ESERIALIZECODE_OK;
}


ESerializeCode CProvince::deSerializeBinary(QDataStream& ds, QString* pError) {
	ds.setByteOrder(QDataStream::LittleEndian);
	ESerializeCode retcode = ESERIALIZECODE_OK;
	ds >> m_strName;
	quint16 nCount = 0; // ��Ҫ��ȷָ���������ͣ�������ƽ̨ʱ���ܳ����⡣����int�ڸ���ƽ̨�Ͽ��ܳ��Ȳ�һ����
	ds >> nCount;
	quint16 idx = 0;
	CCity* pCity = NULL;

	for (idx = 0; idx < nCount; idx++) {
		pCity = new CCity();
		pCity->deSerializeBinary(ds, pError);
		addCity(pCity);
	}

	return retcode;
}


ESerializeCode CProvince::serializeXML(QDomDocument& doc, QDomElement& eleProvince, QString* pError) const {

	eleProvince.setAttribute(c_attribute_name, m_strName);

	QList<CCity*>::ConstIterator iteLst = m_lstCities.constBegin(); // ��Ϊ������Ϊconst��������Ҫ����const���͵Ľӿ�
	ESerializeCode ret = ESERIALIZECODE_OK;
	while (iteLst != m_lstCities.end()) {
		QDomElement eleCity = doc.createElement(c_tag_city);
		ESerializeCode retcode = (*iteLst)->serializeXML(doc, eleCity, pError);
		if (ESERIALIZECODE_OK != retcode) {
			ret = retcode;
		}
		eleProvince.appendChild(eleCity);
		iteLst++;
	}


	return ESERIALIZECODE_OK;
}

ESerializeCode CProvince::deSerializeXML(const QDomElement& eleProvince, QString* pError) {
	ESerializeCode ret = ESERIALIZECODE_OK;
	ESerializeCode retcode = ESERIALIZECODE_OK;
	m_strName = eleProvince.attribute(c_attribute_name);
	// 
	QDomElement eleCity = eleProvince.firstChildElement();
	CCity* pCity = NULL;
	while (eleCity.isElement()) {
		if (eleCity.tagName() == c_tag_city) {
			pCity = new CCity();
			retcode = pCity->deSerializeXML(eleCity, pError);
			if (ESERIALIZECODE_OK != retcode) {
				ret = retcode;
			}
		}
		eleCity = eleCity.nextSiblingElement();
	}

	return ret;
}