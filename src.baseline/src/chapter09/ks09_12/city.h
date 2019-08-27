/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: city.h
\brief �����ඨ���ļ���
       
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#ifndef _CITY_H_
#define _CITY_H_

#include<QString>

#include "serialize.h"

class CProvince;

// ��Ƭ��
class CCard {
public:
	CCard(){}
	~CCard(){}
	
	/**
	* @brief ������Ƭ�ַ���.
	* @param[in] str ��Ƭ�ַ���.
	* @return void
	*/
	void  setName(const QString& str) { m_str = str; }

	/**
	* @brief ��ȡ��������.
	* @return ��������
	*/
	QString  getName(void)const { return m_str; }
	/**
	* @brief ���������������ж����Ʒ�ʽ���л��ĺ�����
	* @param[in] ds �ļ���������
	* @param[in|out] pError ������Ϣ��
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* /*pError*/) const {
		ds << m_str;
		return ESERIALIZECODE_OK;
	}

private:
	QString m_str;
};
// ������
//-----------------------------------------
class CCity
{
public:
	CCity();
	~CCity();

    /**
    * @brief ���ó�������.
    * @param[in] str ��������
    * @return void
    */
	void  setName(const QString& str) {m_strName = str;}

    /**
    * @brief ��ȡ��������.
    * @return ��������
    */
	QString  getName(void)const {return m_strName;}
 
    /**
    * @brief ���ó�������ʡ(��)
    * @param[in] pProvince ��������ʡ(��)
    * @return void
    */
	void  setProvince(CProvince* pProvince) { m_pProvince = pProvince;}

    /**
    * @brief ��ȡ��������ʡ(��)
    * @return ��������ʡ(��)
    */
	CProvince*  getProvince(void) const {return m_pProvince;}
	/**
	* @brief ���������������ж����Ʒ�ʽ���л��ĺ��������ӿ��ڲ��Ѿ�����QDataStream::setByteOrder(QDataStream::LittleEndian)��
	* @param[in] ds �ļ���������
	* @param[in|out] pError ������Ϣ��
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* pError) const;
 
    /**
    * @brief ���ó�����Ƭ
    * @param[in] pCard ��������Ƭ
    * @return void
    */
	void  setCard(CCard* pCard) { m_pCard = pCard;}

    /**
    * @brief ��ȡ������Ƭ
    * @return ������Ƭ
    */
	CCard*  getCard(void) const {return m_pCard;}

private:	
    QString	m_strName;
	CProvince*	m_pProvince;
	CCard* m_pCard;
};



#endif  // for _CITY_H_
