/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: logevt.h
\brief ��־�����ඨ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/01
*/

#ifndef GPLOGEVT_H
#define GPLOGEVT_H

#include <QEvent>
#include <QTime>


/// ��־����ö��
enum ELogLevel
{
	ELogLevel_Error = 1,	/// ����
	ELogLevel_Warning,		/// ����
	ELogLevel_Normal,		/// һ��
};

/// ��־�ṹ
struct SLog
{
	ELogLevel level;		/// ��־����
	QString		msg;		/// ��־����
	QTime		time;		/// ������־ʱ��
	static QString translateLevel(ELogLevel level);
};

enum ELogEvt
{
	ELogEvt_LogOut = QEvent::User + 1,
};

class CLogEvt : public QEvent
{
public:
	/**
	* @brief ���캯��
	* @param[in] nType �¼�����
	*/
	CLogEvt(ELogEvt nType = ELogEvt_LogOut);
	
	/// ��������
	virtual ~CLogEvt();

	/**
	* @brief ��ȡ��־
	* @return ��־
	*/
	SLog getLog() const;

	/**
	* @brief ������־
	* @param[in] log ��־
	*/
	void setLog(const SLog& log);
private:
	SLog m_log;
};

#endif //GPLOGEVT_H