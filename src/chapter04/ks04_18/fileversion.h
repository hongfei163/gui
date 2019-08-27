/*! \file: fileversion.h
	\brief �ļ�ͷ������
	\author Ů�����ϰ�@�����ع���
	\Date : 2018
* please import basedll.dll
*/
#pragma once

#include "qglobal.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �汾������¼
// 1.0 ��ʼ�汾
// 1.1 CCard������idֵ�����л�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



static const quint16 c_MainVersion= 1;		/// ��ǰ�ļ������汾��
static const quint16 c_SubVersion = 1;		/// ��ǰ�ļ��Ĵΰ汾��

/// ��ȡ��ǰϵͳ�����汾�ţ�ʹ�ñ����򱣴��ļ�ʱ�İ汾�ţ�
static quint16 getSystemMainVersion() {
	return c_MainVersion;
}
/// ��ȡ��ǰϵͳ�Ĵΰ汾�ţ�ʹ�ñ����򱣴��ļ�ʱ�İ汾�ţ�
static quint16 getSystemSubVersion() {
	return c_SubVersion;
}
