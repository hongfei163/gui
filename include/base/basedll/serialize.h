/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: serialize.h
\brief ���л������붨���ļ���

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10
* please import basedll.dll
*/

#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_


/**
* @brief ���л���������ö��
*
* ESerializeCode ö�١�
* ����˵�����л�ʱ���ִ�����ԭ��
*
*/
enum ESerializeCode
{
	ESERIALIZECODE_OK = 0,					/// ����
	ESERIALIZECODE_FILENOTFOND,				/// �ļ�������
	ESERIALIZECODE_DOC_ELEMENT_NOTFOUND,	/// docԪ�ز�����: �ļ��б�������<doc>Ԫ��
	ESERIALIZECODE_CONTENT_ELEMENT_NOTFOUND,/// contentԪ�ز�����: �ļ��б�������<content>Ԫ��
	ESERIALIZECODE_SETCONTENT_ERROR,		/// QDomDocument::setContent()����ʧ��
	ESERIALIZECODE_VERSION_NOTRECOGNIZE,	/// ����ʶ���İ汾��
	ESERIALIZECODE_OTHERERROR,					/// ��������

};


#endif  // _SERIALIZE_H_
