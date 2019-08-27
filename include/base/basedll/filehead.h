/*! 
\file: filehead.h
\brief �ļ�ͷ������
\author Ů�����ϰ�@�����ع���
\Date : 2018
* please import basedll.dll
*/
#ifndef _FILEHEAD_H
#define _FILEHEAD_H

#include "qglobal.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �汾������¼
// 1.0 ��ʼ�汾
// 1.1 CCard������idֵ�����л�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


namespace ns_train {

/// �ļ�ͷ��
class SFileHead
{
public:
	SFileHead()	{
		m_nMainVersion = 0;
		m_nSubVersion = 0;
	}

	SFileHead(quint16 nMainVersion, quint16 nSubVersion)	{
		m_nMainVersion = nMainVersion;
		m_nSubVersion = nSubVersion;
	}

	/// �Ƿ���Ч
	bool isValid() const	{
		return (0 != m_nMainVersion) && (0 != m_nSubVersion);
	}

	/// ��ǰ�ļ�(����)�汾���Ƿ��ȴ����İ汾�ž�
	bool isEarlierVersion(quint16 nMainVersion, quint16 nSubVersion) const	{
		if ((m_nMainVersion < nMainVersion)
			|| (m_nMainVersion == nMainVersion && m_nSubVersion < nSubVersion))	{
			return true;
		}
		else	{
			return false;
		}
	}
	/// ��ǰ�ļ��汾���Ƿ��ȴ����İ汾����
	bool isLaterVersion(quint16 nMainVersion, quint16 nSubVersion) const	{
		if ((m_nMainVersion > nMainVersion)
			|| (m_nMainVersion == nMainVersion && m_nSubVersion >= nSubVersion))	{
			return true;
		}
		else	{
			return false;
		}
	}
	/// ��ǰ�ļ����汾���Ƿ��ȴ��������汾����
	bool isLaterMainVersion(quint16 nMainVersion) const	{
		if (m_nMainVersion > nMainVersion)	{
			return true;
		}
		else	{
			return false;
		}
	}
	/// ��ǰ�ļ��汾���Ƿ��봫���İ汾����ͬ
	bool isSameVersion(quint16 nMainVersion, quint16 nSubVersion) const	{
		if ((m_nMainVersion == nMainVersion)
			&& (m_nSubVersion == nSubVersion))
		{
			return true;
		}
		else	{
			return false;
		}
	}

	/// ���汾��ת��ΪQString�����ַ��������汾1.0��ת��Ϊ"1.0"
	QString toQString() const	{
		QString str = QString::number(m_nMainVersion).append(".").append(QString::number(m_nSubVersion));
		return str;
	}

	/// ��QString�����ַ���ת��Ϊ�汾�ţ����ַ���"1.0"��ת��Ϊ�汾1.0
	static SFileHead fromQString(QString str)	{
		SFileHead FileHead;
		if (str.contains('.'))	{
			qint32 index = str.indexOf('.');
			FileHead.m_nMainVersion = str.left(index).toUShort();
			FileHead.m_nSubVersion = str.right(str.length() - index - 1).toUShort();
		}
		else	{
			FileHead.m_nMainVersion = 0;
			FileHead.m_nSubVersion = 0;
		}
		return FileHead;
	}

	/// ��ֵ����
	SFileHead& operator = (const SFileHead& fileHead)	{
		if (this != &fileHead)	{
			this->m_nMainVersion = fileHead.m_nMainVersion;
			this->m_nSubVersion = fileHead.m_nSubVersion;
		}
		return *this;
	}
	/// �ж������Ƿ�����
	bool operator == (const SFileHead& r)	{
		if ((this->m_nMainVersion == r.m_nMainVersion) && (this->m_nSubVersion == r.m_nSubVersion))		{
			return true;
		}
		else		{
			return false;
		}
	}
	/// ��ȡ���汾��
	quint16 getMainVersion() const	{
		return m_nMainVersion;
	}

	/// ��ȡ�Ӱ汾��
	quint16 getSubVersion() const	{
		return m_nSubVersion;
	}

private:
	quint16	m_nMainVersion;		/// ���汾��
	quint16	m_nSubVersion;		/// �ΰ汾��
};

} // namespace ns_train

#endif	//FILEHEAD_H