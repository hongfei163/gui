/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: country.h
\brief �����ඨ���ļ���
       
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
*/

#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include <QList>
#include <QString>

class CProvince;


// ������
//-----------------------------------------
class CCountry
{
public:
	CCountry();
	CCountry(const QString& str) :m_strName(str) { ; }
	~CCountry();

    /**
    * @brief ���ù�������.
    * @param[in] strName ��������
    * @return void
    */
	void  setName(const QString& str) {m_strName = str;}

    /**
    * @brief ��ȡ��������.
    * @return ��������
    */
	QString  getName(void) const {return m_strName;}   
   
    /**
    * @brief ���ù������ڴ�������
    * @param[in] str �������ڴ�������
    * @return void
    */
	void  setContinent(const QString& str) {m_strContinent = str;}

    /**
    * @brief ��ȡ�������ڴ�������
    * @return �������ڴ�������
    */
	QString  getContinent(void) const {return m_strContinent;}

	/**
	* @brief ����ʡ
	* @param[in] pProvince ʡ
	* @return ���Ӻ���ʡ����
	*/
	int addProvince(CProvince* pProvince);

	/**
	* @brief ��ȡʡ�б�
	* @param[out] lstProvinces ʡ�б�
	* @return ����ʡ����
	*/
	int getProvinces(QList<CProvince*>& lstProvinces) const { lstProvinces = m_lstProvinces; return lstProvinces.size(); }
private:	
    QString	m_strName;
    QString	m_strContinent;	
	QList<CProvince*> m_lstProvinces;
};


#endif  // for _COUNTRY_H_
