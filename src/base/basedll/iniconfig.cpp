/*! \file: iniconfig.h
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\brief ini��ʽ�����ļ�����ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include "iniconfig.h"

namespace ns_train {

static const int c_bufLen = 10240;
CIniConfig::CIniConfig() :m_bIsOpen(false)
{
}

CIniConfig::~CIniConfig()
{
}

bool CIniConfig::setFileName(const QString& strFileName)
{
    if (strFileName.length() == 0)
        return false;

    char pTmp[c_bufLen];
    QString tStr;

    m_yFile.setFileName(strFileName);

    if (!m_yFile.open(QFile::ReadOnly))		// �ļ��������򷵻�false
    {
        m_yFile.close();
        return false;
    }

    // �ļ�����=0�򷵻�false
    int t_nFileLen = m_yFile.size();

    if (t_nFileLen <= 0)
    {
        m_yFile.close();
        return false;
    }
    m_bIsOpen = true;
    m_arString.clear();

    // ���ļ����ݶ���������
    while (m_yFile.readLine(pTmp, c_bufLen) > 0)
    {
        tStr = pTmp;
        tStr = tStr.trimmed();

        m_arString.push_back(tStr);
    }
    m_yFile.close();

    return true;
}

bool CIniConfig::deleteSubKey(const QString& strKey, const QString& strSubKey)
{
    if (strKey.length() == 0 || strSubKey.length() == 0)
        return false;

    int nIndex = searchLine(strKey, strSubKey);

    if (nIndex > 0)
        m_arString.removeAt(nIndex);

    return writeToFile();
}

bool CIniConfig::deleteKey(const QString& strKey)
{
    if (strKey == NULL)
        return false;

    int nBegin = -1;
    int nEnd = -1;
    bool bFindKey = false;
    m_szTmp = "[";
    m_szTmp += strKey;
    m_szTmp += "]";

    for (int i = 0; i < m_arString.size(); ++i)
    {
        if (m_arString[i].left(1) == ";")			// ע��
            continue;

        if (!bFindKey)		// δ�ҵ�����
        {
            if (m_arString[i].indexOf(m_szTmp, Qt::CaseInsensitive) == 0)
            {
                bFindKey = true;
                nEnd = nBegin = i;//��������û���Ӽ�����ɾ���������ɹ���
            }
        }
        else			// �Ѿ��ҵ�����
        {
            if (m_arString[i].indexOf("[") == 0)				// �Ӽ�������
            {
                nEnd = i;
                break;
            }


            if (i == m_arString.size() - 1)
                nEnd = i + 1;

        }
    }

    if (nBegin >= 0 && nEnd >= 0)
    {
        for (int j = nBegin; j < nEnd; j++)
            m_arString.removeAt(nBegin);

        return writeToFile();
    }
    return false;
}

bool CIniConfig::deleteAll()
{
    if (m_bIsOpen)
    {
        m_yFile.open(QFile::WriteOnly | QFile::Truncate);
        m_yFile.close();
        m_arString.clear();
        return true;
    }
    else
        return false;
}

bool CIniConfig::getBool(const QString& strKey, const QString& strSubKey, bool i_bDefault, bool* o_bRet)
{
    QString t_strResult;

    if (o_bRet != NULL)
        *o_bRet = true;

    // ��ȡ�����ַ���
    if (!getValueString(searchLine(strKey, strSubKey), t_strResult))
    {
        if (o_bRet != NULL)
            *o_bRet = false;
    }

    // �������ַ���ת��Ϊ������
    if (t_strResult == "Y" || t_strResult == "y")
        return true;
    else if (t_strResult == "N" || t_strResult == "n")
        return false;
    else
    {
        if (o_bRet != NULL)
            *o_bRet = false;
        return i_bDefault;
    }
}

bool CIniConfig::setBool(const QString& strKey, const QString& strSubKey, bool i_bValue)
{
    if (strKey == NULL || strSubKey == NULL)
        return false;

    int nLine = searchLine(strKey, strSubKey);

    char  t_szBool[2];

    if (i_bValue)
        sprintf(t_szBool, "%s", "Y");
    else
        sprintf(t_szBool, "%s", "N");

    if (nLine > 0)							// �����������Ӽ�
    {
        if (!setValueString(nLine, t_szBool))
            return false;
    }
    else
    {
        if (nLine == (-m_arString.size() - 1))
            nLine = 0;
        addValueString(strKey, strSubKey, t_szBool, nLine);
    }

    return writeToFile();
}

int CIniConfig::getInt(const QString& strKey, const QString& strSubKey, int i_nDefault, bool* o_bRet)
{
    QString t_strResult;

    if (o_bRet != NULL)
        *o_bRet = true;

    // ��ȡ�����ַ���
    if (!getValueString(searchLine(strKey, strSubKey), t_strResult))
    {
        if (o_bRet != NULL)
            *o_bRet = false;
        return i_nDefault;
    }

    // �������ַ���ת��Ϊ������
    return atoi(t_strResult.toLocal8Bit().data());
}

bool CIniConfig::setInt(const QString& strKey, const QString& strSubKey, int i_nValue)
{
    if (strKey == NULL || strSubKey == NULL)
        return false;

    char  t_szInt[64];
    sprintf(t_szInt, "%d", i_nValue);

    int nLine = searchLine(strKey, strSubKey);

    if (nLine > 0)							// �����������Ӽ�
    {
        if (!setValueString(nLine, t_szInt))
            return false;
    }
    else
    {
        if (nLine == (-m_arString.size() - 1))
            nLine = 0;
        addValueString(strKey, strSubKey, t_szInt, nLine);
    }

    return writeToFile();
}

double CIniConfig::getReal(const QString& strKey, const QString& strSubKey, double i_fDefault, bool* o_bRet)
{
    QString t_strResult;

    if (o_bRet != NULL)
        *o_bRet = true;

    // ��ȡ�����ַ���
    if (!getValueString(searchLine(strKey, strSubKey), t_strResult))
    {
        if (o_bRet != NULL)
            *o_bRet = false;
        return i_fDefault;
    }

    // �������ַ���ת��Ϊ������
    return atof(t_strResult.toLocal8Bit().data());
}

bool CIniConfig::setReal(const QString& strKey, const QString& strSubKey, double i_fValue)
{
    if (strKey == NULL || strSubKey == NULL)
        return false;

    char  t_szReal[64];
    sprintf(t_szReal, "%.3f", i_fValue);

    int nLine = searchLine(strKey, strSubKey);

    if (nLine > 0)							// �����������Ӽ�
    {
        if (!setValueString(nLine, t_szReal))
            return false;
    }
    else
    {
        if (nLine == (-m_arString.size() - 1))
            nLine = 0;
        addValueString(strKey, strSubKey, t_szReal, nLine);
    }

    return writeToFile();
}

QString CIniConfig::getString(const QString& strKey, const QString& strSubKey, const QString& strDefault, bool* o_bRet)
{
    QString tStr;

    if (o_bRet != NULL)
        *o_bRet = true;

    // ��ȡ�����ַ���
    if (!getValueString(searchLine(strKey, strSubKey), tStr))
    {
        if (o_bRet != NULL)
            *o_bRet = false;
        return strDefault;
    }
    return tStr;
}
QString CIniConfig::getStringExt(const QString& strKey, const QString& strSubKey, const QString& strDefault, bool* o_bRet/*=NULL*/)
{
    QString tStr;

    if (o_bRet != NULL)
        *o_bRet = true;

    int nIndex = searchLine(strKey, strSubKey);
    // ��ȡ�����ַ���
    if (!getValueString(nIndex, tStr))
    {
        if (o_bRet != NULL)
            *o_bRet = false;
        return strDefault;
    }

    // ��ֵ�ٶ�һ��
    QString tNextLine = m_arString[nIndex];
    while (tNextLine.length() == (c_bufLen - 1))
    {
        tNextLine = m_arString[++nIndex];
        tStr += tNextLine;
    }

    return tStr;
}

bool CIniConfig::setString(const QString& strKey, const QString& strSubKey, const QString& strValue)
{
    if (strKey == NULL || strSubKey == NULL)
        return false;

    if (strValue.length() == 0)
        return deleteSubKey(strKey, strSubKey);

    int nLine = searchLine(strKey, strSubKey);

    if (nLine > 0)							// �����������Ӽ�
    {
        if (!setValueString(nLine, strValue))
            return false;
    }
    else
    {
        if (nLine == (-m_arString.size() - 1))
            nLine = 0;
        addValueString(strKey, strSubKey, strValue, nLine);
    }

    return writeToFile();
}

QString CIniConfig::getKeyList(const QString& strKey)
{
    bool bFindKey = false;
    m_szTmp = "[";
    m_szTmp += strKey;
    m_szTmp += "]";
    bool bFirstTime = true;

    QString tStr;
    for (int i = 0; i < m_arString.size(); ++i)
    {
        if (m_arString[i][0] == ';')			// ע��
            continue;

        if (!bFindKey)		// δ�ҵ�����
        {
            if (m_arString[i].indexOf(m_szTmp, Qt::CaseInsensitive) == 0)
                bFindKey = true;
        }
        else			// �Ѿ��ҵ�����
        {
            if (m_arString[i].indexOf("[") == 0)				// �Ӽ���������ͷ
                return tStr;

            if (bFirstTime)
            {
                tStr = m_arString[i];
                bFirstTime = false;
            }
            else
            {
                tStr += "\r\n";
                tStr += m_arString[i];
            }
        }
    }
    return tStr;
}

bool CIniConfig::setKeyList(const QString& strKey, const QString& i_pStr)
{
    m_szTmp = "[";
    m_szTmp += strKey;
    m_szTmp += "]";
    int tBeginPos = -1;
    QString tStr = i_pStr;

    for (int i = 0; i < m_arString.size(); ++i)
    {
        if (m_arString[i][0] == ';')			// ע��
            continue;

        if (m_arString[i].indexOf(m_szTmp, Qt::CaseInsensitive) == 0)
        {
            tBeginPos = i;
            break;
        }
    }

    if (tBeginPos < 0)	// δ�ҵ�����
    {
        m_arString.push_front(m_szTmp);
        tBeginPos = 1;
    }
    else
    {
        tBeginPos += 1;
        while (tBeginPos < m_arString.size() && m_arString[tBeginPos].indexOf("[") != 0)
        {
            m_arString.removeAt(tBeginPos);
        }
    }

    // ���봦��,
    QStringList strList = tStr.split("\n");
    QStringList::iterator iteStr = strList.begin();
    while (iteStr != strList.end()) {
        tStr = *iteStr;
        m_arString.insert(tBeginPos, tStr);
        iteStr++;
    }

    return writeToFile();
}

//=======================================================
// ˽�к���
//=======================================================
int CIniConfig::searchLine(const QString& strKey, const QString& strSubKey)
{
    int nRet = -m_arString.size() - 1;
    bool bFindKey = false;
    int nTmpPos = 0;
    QString tStr;
    m_szTmp = "[";
    m_szTmp += strKey;
    m_szTmp += "]";

    for (int i = 0; i < m_arString.size(); ++i)
    {
        if (m_arString[i][0] == ';')			// ע��
            continue;

        if (!bFindKey)		// δ�ҵ�����
        {
            if (m_arString[i].indexOf(m_szTmp, Qt::CaseInsensitive) == 0)
            {
                bFindKey = true;
                nRet = -i - 1;										// ������
            }
        }
        else			// �Ѿ��ҵ�����
        {
            nTmpPos = m_arString[i].indexOf("=");
            tStr = m_arString[i].left(nTmpPos);
            tStr = tStr.trimmed();

            if (tStr == strSubKey)		// �ҵ��Ӽ�
            {
                nRet = i;
                break;
            }

            if (m_arString[i][0] == '[')							// �Ӽ�������
                break;
        }
    }
    return nRet;
}

bool CIniConfig::writeToFile()
{
    if (!m_yFile.open(QFile::WriteOnly))
        return false;

    // ��������д���ļ�
    m_yFile.seek(0);
    QString str;
    for (int i = 0; i < m_arString.size(); ++i) {
        str = m_arString[i];
        if ((str.right(1) != '\r') && (str.right(1) != '\n')) {
            str += "\r\n";
        }
        m_yFile.write(str.toLocal8Bit().data());
    }
    m_yFile.close();
    return true;
}

bool CIniConfig::getValueString(int i_nIndex, QString& o_pValue)
{
    if (i_nIndex < 0 || i_nIndex >= m_arString.size())
        return false;

    int nBegin = m_arString[i_nIndex].indexOf("=") + 1;

    if (nBegin < 0)				// û��"="��������
        return false;

    o_pValue = m_arString[i_nIndex].mid(nBegin);
    o_pValue = o_pValue.trimmed();
    return true;
}

bool CIniConfig::setValueString(int i_nIndex, const QString& strValue)
{
    if (i_nIndex < 0 || i_nIndex >= m_arString.size())
        return false;

    int nBegin = m_arString[i_nIndex].indexOf("=") + 1;

    if (nBegin < 0)				// û��"="��������
        return false;

    QString tStr = m_arString[i_nIndex].mid(nBegin);
    m_arString[i_nIndex].replace(nBegin, tStr.length(), strValue);
    return true;
}

void CIniConfig::addValueString(const QString& strKey, const QString& strSubKey, const QString& strValue, int i_nRet)
{
    if (i_nRet == 0)			// ������
    {
        // ��������
        m_szTmp = "[";
        m_szTmp += strKey;
        m_szTmp += "]";
        m_arString.push_back("");
        m_arString.push_back(m_szTmp);

        // �����Ӽ�
        m_szTmp = strSubKey;
        m_szTmp += "=";
        m_szTmp += strValue;
        m_arString.push_back(m_szTmp);
    }
    else						// ���������Ӽ�
    {
        // �����Ӽ�
        m_szTmp = strSubKey;
        m_szTmp += "=";
        m_szTmp += strValue;
        m_arString.insert(-i_nRet, m_szTmp);
    }
}
}