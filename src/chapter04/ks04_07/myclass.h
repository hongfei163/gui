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

#include <QString>

class CMyClass
{
public:
	// ���캯��
	CMyClass(): m_id(0), m_pStrName(NULL){}
	// ���캯��
	CMyClass(int id, const QString& name): m_id(id), m_pStrName(new QString(name)){}

	// �������캯��
	CMyClass(const CMyClass& right);

	// ��������
	~CMyClass();

	// ���ز�����operator<
	bool operator<(const CMyClass& right) const;

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
	void setName(const QString& str);
	/**
	* @brief  ��ȡ����
	* @return ����
	*/
	QString getName() const;
private:
	/// ��ʼ��������
	void 	initial();

	int m_id;
	QString* m_pStrName;
};


#endif  // _MYCLASS_DLL_H