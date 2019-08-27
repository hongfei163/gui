/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: iniconfig.h
\brief ini��ʽ�����ļ�����ͷ�ļ�, ��ע�⣺�����������ļ�����GB2312���롣
       
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
* please import basedll.dll
*/

#ifndef _INICONFIG_H_
#define _INICONFIG_H_

#include <QFile>
#include <QString>
#include <QVector>

#include "base_export.h"

namespace ns_train {

// ini��ʽ�����ļ�������
//-----------------------------------------


class BASE_API CIniConfig
{
public:
	CIniConfig();
	~CIniConfig();

    /**
    * @brief ���������ļ����ļ�����ʹ��ȫ·������֧�ֻ�������.
    * @param[in] strFileName �ļ���
    * @return true:�ɹ�,false:ʧ��
    */
	bool  setFileName(const QString& strFileName);

    /**
    * @brief ɾ��ָ���Ӽ�
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @return true:�ɹ�,false:ʧ��
    */
	bool  deleteSubKey(const QString& strKey, const QString& strSubKey);
    /**
    * @brief ɾ��ָ������
    * @param[in] strKey ����
    * @return true:�ɹ�,false:ʧ��
    */
	bool  deleteKey(const QString& strKey);
    /**
    * @brief ɾ��ȫ����ֵ
    * @return true:�ɹ�,false:ʧ��
    */
	bool  deleteAll();

    /**
    * @brief ��ȡbool���͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_nDefault Ĭ��ֵ
    * @param[out] o_bRet true:�ɹ�, false:ʧ��
    * @return ����
    */
	bool  getBool(const QString& strKey, const QString& strSubKey, bool i_nDefault, bool* o_bRet=NULL);
    /**
    * @brief ��ȡint���͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_nDefault Ĭ��ֵ
    * @param[out] o_bRet true:�ɹ�, false:ʧ��
    * @return ����
    */
	int  getInt(const QString& strKey, const QString& strSubKey, int i_nDefault, bool* o_bRet=NULL);
    /**
    * @brief ��ȡ�������͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_fDefault Ĭ��ֵ
    * @param[out] o_bRet true:�ɹ�, false:ʧ��
    * @return ����
    */
	double  getReal(const QString& strKey, const QString& strSubKey, double i_fDefault, bool* o_bRet=NULL);
    /**
    * @brief ��ȡstring���͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] strDefault Ĭ��ֵ
    * @param[out] o_bRet true:�ɹ�, false:ʧ��
    * @return ����
    */
    QString getString(const QString& strKey, const QString& strSubKey, const QString& strDefault, bool* o_bRet=NULL);
    /**
    * @brief ��ȡstring���͵ļ�ֵ(��չ�ӿ�),֧�ֶ��ж�ȡ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] strDefault Ĭ��ֵ
    * @param[out] o_bRet true:�ɹ�, false:ʧ��
    * @return ����
    */
    QString getStringExt(const QString& strKey, const QString& strSubKey, const QString& strDefault, bool* o_bRet=NULL);
    /**
    * @brief ����bool���͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_nValue �Ӽ���ֵ
     * @return true:�ɹ�, false:ʧ��
    */	
    bool  setBool(const QString& strKey, const QString& strSubKey, bool i_nValue);
    /**
    * @brief ����int���͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_nValue �Ӽ���ֵ
     * @return true:�ɹ�, false:ʧ��
    */	
    bool  setInt(const QString& strKey, const QString& strSubKey, int i_nValue);
    /**
    * @brief ���ø������͵ļ�ֵ
    * @param[in] strKey ����
    * @param[in] strSubKey �Ӽ�
    * @param[in] i_fValue �Ӽ���ֵ
     * @return true:�ɹ�, false:ʧ��
    */	
	bool  setReal(const QString& strKey, const QString& strSubKey, double i_fValue);
    /**
    * @brief �����ַ������͵ļ�ֵ, ���磬�����ļ���������:
    *           [config]
    *           x=xx
    *           y=yy
    *           z=zz
    * @param[in] strKey ����=config
    * @param[in] strSubKey �Ӽ�=x
    * @param[in] strValue �Ӽ���ֵ, Ϊ""��ʾɾ�����ӽ���
     * @return true:�ɹ�, false:ʧ��
    */	
    bool  setString(const QString& strKey, const QString& strSubKey, const QString& strValue);

    /**
    * @brief ��ȡ��ֵ�б�, �����紫��("config"")���õ�, "x=xx\ny=yy\nz=zz"
    * @param[in] strKey ����
    * @return ��ֵ�б�
    */
    QString getKeyList(const QString& strKey);

    /**
    * @brief ���ü�ֵ�б�, �����紫��("config", "x=xx\ny=yy\nz=zz")
    *           ִ�к��Ľ���:
    *           [config]
    *           x=xx
    *           y=yy
    *           z=zz
    * @param[in] strKey ����
    * @param[in] str �Ӽ�ֵֵ�б�,\n�ָ�������: "x=xx\ny=yy\nz=zz"  
    * @return ������true:�ɹ�, false:ʧ��
    */	
    bool setKeyList(const QString& strKey, const QString& Str);

private:
	int searchLine(const QString& strKey, const QString& strSubKey);
	bool writeToFile();

	bool getValueString(int i_nIndex, QString& o_pValue);
	bool setValueString(int i_nIndex, const QString& strValue);
	void addValueString(const QString& strKey, const QString& strSubKey, const QString& strValue, int i_nRet);

	QFile				m_yFile;    // �ļ�����
	QVector<QString>	m_arString;
	bool				m_bIsOpen;  // �����ļ��Ƿ��Ѵ���
    QString				m_szTmp;
};

}

#endif  // for _INICONFIG_H_
