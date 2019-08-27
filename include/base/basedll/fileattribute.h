/*! \file: fileattribute.h
	\brief �ļ����Եķ����ඨ��
	\author Ů�����ϰ�@�����ع���
	\Date : 2018/1/10
* please import basedll.dll
*/
#ifndef _FILEATTR_H
#define _FILEATTR_H


#include <QString>
#include "qglobal.h"

#include "base_export.h"
#include "base/basedll/serialize.h"


class QDomElement;

namespace ns_train {
	
static const quint16 c_MainVersion = 1;		/// ͼ��ƽ̨��ǰͼ�ε����汾��
static const quint16 c_SubVersion = 12;		/// ͼ��ƽ̨��ǰͼ�εĴΰ汾��

const quint16 c_MD5_Length = 16;			/// md5���ĳ��ȣ���λ���ֽڡ�
/// �ļ�������
struct BASE_API SFileAttr
{
	quint16	mainVer;						/// ���汾��
	quint16	subVer;							/// �ΰ汾��
	quint8	md5[c_MD5_Length];				/// ���ļ���md5��, �����Ƹ�ʽʹ�ã��ı���ʽ���ø����ԡ�

	SFileAttr(){ mainVer = 1; subVer = 0; memset(md5, 0, c_MD5_Length); }
};
/// ���л��ļ����Զ�������(������)
BASE_API QDataStream& operator<<(QDataStream& stream, const SFileAttr& attrs);
/// �����л��ļ����Զ�������(������)
BASE_API QDataStream& operator>>(QDataStream& stream, SFileAttr& attrs);
/// ���л��ļ��Ļ�������(XML)
BASE_API QDomElement& operator<<(QDomElement& ele, const SFileAttr& attrs);
/// �����л��ļ��Ļ�������(XML)
BASE_API QDomElement& operator>>(QDomElement& ele, SFileAttr& attrs);

//����ȡ�ļ�������-�����Ʒ�ʽ
/**
* @param[in] fileName	�ļ�ȫ·����
* @param[out] attrs		����
* @retval ESerializeCode
*/
BASE_API ESerializeCode readInfoFromBinary(const QString& fileName, SFileAttr& attrs);

//����ȡ�ļ�������-xml��ʽ
/**
* @param[in] fileName	�ļ�ȫ·����
* @param[out] attrs		����
* @retval ESerializeCode
*/
BASE_API ESerializeCode readInfoFromXML(const QString& fileName, SFileAttr& attrs);

BASE_API  quint16 getMainVersion() {
    return c_MainVersion;
}
} // namespace iesgp

#endif //_FILEATTR_H
