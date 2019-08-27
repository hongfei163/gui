/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�����������Ķ���ͷ�ļ�
 
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
*/

#ifndef _MYCLASS_DLL_H
#define _MYCLASS_DLL_H
#include <QDebug>
#include <QString>

class CMyClass
{
public:
	// ���캯��
	CMyClass(): m_id(0){}

	// ��������
	~CMyClass(){}


	/**
	* @brief  ����id
	* @param[in] id id
	*/
	void setId(int id) { m_id = id; }
	/**
	* @brief  ��ȡid
	* @return id
	*/
	int getId() const { return m_id; }

	/**
	* @brief  ��������
	* @param[in] name ����
	*/
	void setName(const QString& str) { m_strName = str; }
	/**
	* @brief  ��ȡ����
	* @return ����
	*/
	QString getName() const { return m_strName; }
private:
	int m_id;
	QString m_strName;   
};
QDebug operator<<(QDebug debug, const CMyClass &mc);


#endif  // _MYCLASS_DLL_H