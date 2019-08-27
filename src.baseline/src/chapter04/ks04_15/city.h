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

class CProvince;

// ������
//-----------------------------------------
class CCity
{
public:
	CCity();
	~CCity();

    /**
    * @brief ���ó�������.
    * @param[in] strName ��������
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

private:	
    QString	m_strName;
	CProvince*	m_pProvince;
};



#endif  // for _CITY_H_
