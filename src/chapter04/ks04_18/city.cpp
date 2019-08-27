/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: city.cpp
\brief ������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#include "city.h"
#include "base/basedll/filehead.h"

// domԪ�ر�ǩ������
static const char* c_tag_card = "card";

// domԪ��������������
static const char* c_attribute_name = "name";
static const char* c_attribute_string = "string";

////////////////////////////////////////////////////////////////////////////////////
// CCard
ESerializeCode CCard::serializeBinary(QDataStream& ds, QString* /*pError*/) const {
    ds << m_str;
    ds << m_id;
    return ESERIALIZECODE_OK;
}


ESerializeCode CCard::deSerializeBinary(QDataStream& ds, const ns_train::SFileHead* pFileHead, QString* /*pError*/) {
    ds >> m_str;
    if (pFileHead->isLaterVersion(1, 1)) {
        ds >> m_id;
    }
    return ESERIALIZECODE_OK;
}

ESerializeCode CCard::serializeXML(QDomDocument& /*doc*/, QDomElement& eleCard, QString* /*pError*/) const {
	eleCard.setAttribute(c_attribute_name, m_str);

	return ESERIALIZECODE_OK;
}

/**
* @brief �����������������ı���ʽ���л��ĺ�����
* @param[in] eleCity ����Ԫ�ض���
* @param[in] pError ������Ϣ��
* @return ESerializeCodeö��ֵ��
*/
ESerializeCode CCard::deSerializeXML(const QDomElement& eleCard, const  ns_train::SFileHead* /*pFileHead*/, QString* /*pError*/) {
	m_str = eleCard.attribute(c_attribute_name);
	return ESERIALIZECODE_OK;
}

////////////////////////////////////////////////////////////////////////////////////
// CCity
CCity::CCity() :m_pCard(NULL) {
	;
}

CCity::~CCity() {
	if (NULL != m_pCard) {
		delete m_pCard;
	}
}

ESerializeCode  CCity::serializeBinary(QDataStream& ds, QString* pError) const {
	Q_UNUSED(pError);

	ds << m_strName;
	quint8 byValue = ((NULL != m_pCard) ? true : false);
	ds << byValue;
	if (NULL != m_pCard) {
		m_pCard->serializeBinary(ds, pError);
	}
	return ESERIALIZECODE_OK;
}

ESerializeCode CCity::deSerializeBinary(QDataStream& ds, const ns_train::SFileHead* pFileHead, QString* pError) {
	Q_UNUSED(pError);
	ds.setByteOrder(QDataStream::LittleEndian);
	ESerializeCode retcode = ESERIALIZECODE_OK;
	ds >> m_strName;
	
	quint8 byValue = 0;
	ds >> byValue;

	if (byValue) {
		if (NULL == m_pCard) {
			m_pCard = new CCard();
		}
		m_pCard->deSerializeBinary(ds, pFileHead, pError);
	}
	return retcode;
}


ESerializeCode CCity::serializeXML(QDomDocument& doc, QDomElement& eleCity, QString* pError) const {

	eleCity.setAttribute(c_attribute_name, m_strName);

	ESerializeCode ret = ESERIALIZECODE_OK;
	if (NULL != m_pCard) {
		QDomElement eleCard = doc.createElement(c_tag_card);
		ret = m_pCard->serializeXML(doc, eleCard, pError);
		eleCity.appendChild(eleCard);
	}


	return ret;
}

ESerializeCode CCity::deSerializeXML(const QDomElement& eleCity, const ns_train::SFileHead* pFileHead, QString* pError) {
	
	ESerializeCode ret = ESERIALIZECODE_OK;
	m_strName = eleCity.attribute(c_attribute_name);
	// 
	QDomElement eleCard = eleCity.firstChildElement();
	if (eleCard.isElement()) {
		if (eleCard.tagName() == c_tag_card) {
			if (NULL == m_pCard) {
				m_pCard = new CCard();
			}
			ret = m_pCard->deSerializeXML(eleCard, pFileHead, pError);
		}
	}
	return ret;
}