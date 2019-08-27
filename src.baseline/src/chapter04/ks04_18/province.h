/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: province.h
\brief ʡ(��)�ඨ���ļ���
       
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#ifndef _PROVINCE_H_
#define _PROVINCE_H_

#include <QDomDocument>
#include <QList>
#include <QString>

#include "base/basedll/serialize.h"

class CCity;
class CCountry;

// ʡ(��)��
//-----------------------------------------
class CProvince
{
public:
	CProvince();
	~CProvince();

    /**
    * @brief ����ʡ(��)����.
    * @param[in] strName ʡ(��)����
    * @return void
    */
	void  setName(const QString& str) {m_strName = str;}

    /**
    * @brief ��ȡʡ(��)����.
    * @return ʡ(��)����
    */
	QString  getName(void) const {return m_strName;}
   
   
    /**
    * @brief ����ʡ(��)���ڹ���
    * @param[in] pCountry ʡ(��)���ڹ���
    * @return void
    */
	void  setCountry(CCountry* pCountry) {m_pCountry = pCountry;}

    /**
    * @brief ��ȡʡ(��)���ڹ���
    * @return ʡ(��)���ڹ���
    */
	CCountry*  getCountry(void) const {return m_pCountry;}

    /**
    * @brief ���ӳ���
    * @param[in] pCity ����
    * @return ���Ӻ��ĳ��и���
    */
	int addCity(CCity* pCity);

    /**
    * @brief ���ӳ���
    * @param[out] lstCities �����б�
    * @return ���г��и���
    */
	int getCities(QList<CCity*>& lstCities) const { lstCities = m_lstCities; return lstCities.size(); }
	
	/**
	* @brief ���������������ж����Ʒ�ʽ���л��ĺ�����
	* @param[in] ds �ļ���������
	* @param[in|out] pError ������Ϣ��
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* pError) const;
	/**
	* @brief ���������������ж����Ʒ�ʽ���л��ĺ�����
	*        �򿪵��ļ��뱣��ʱ������ͬ��ByteOrder(���ӿ��ڲ��Ѿ�����QDataStream::setByteOrder)��
	* @param[in] ds �ļ���������
	* @param[in|out] pError ������Ϣ��
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode deSerializeBinary(QDataStream& ds, QString* pError);
	/**
	* @brief �����������������ı���ʽ���л��ĺ�����
	* @param[in|out] doc QDomDocument��������Ҫ�ⲿ����
	* @param[in] eleProvince ʡԪ�ض���
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode serializeXML(QDomDocument& doc, QDomElement& eleProvince, QString* pError) const;

	/**
	* @brief �����������������ı���ʽ���л��ĺ�����
	* @param[in] eleProvince ʡԪ�ض���
	* @return ESerializeCodeö��ֵ��
	*/
	ESerializeCode deSerializeXML(const QDomElement& eleProvince, QString* pError = NULL);
private:	
    QString	m_strName;
	CCountry* m_pCountry;
	QList<CCity*> m_lstCities;
};



#endif  // for _PROVINCE_H_
