/*! \file: sync.h
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\brief �ļ�ͬ���ඨ��ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef _SYNC_H
#define _SYNC_H

#include <QString>
#include <QList>

class CSyncConfig {
public:
	CSyncConfig();
	CSyncConfig(const CSyncConfig& right);
	~CSyncConfig();

	CSyncConfig& operator=(const CSyncConfig& right);

	/**
	* @brief ����Դ·��
	* @param[in] strSrc Դ·��
	* @return void
	*/
	void setSourceDirectory(const QString& strSrc) { m_strSrcDir = strSrc; }
	/**
	* @brief ��ȡԴ·��, �Ѿ�ת��Ϊunix������/xx/xx/xx.txt�����Ҳ���������б��"/"
	* @return Դ·��
	*/	
	QString getSourceDirectory() const { return m_strSrcDir; }

	/**
	* @brief ����Ŀ��·��
	* @param[in] strDst Ŀ��·��
	* @return void
	*/
	void setDestDirectory(const QString& strDst) { m_strDstDir = strDst; }
	/**
	* @brief ��ȡԴ·��, �Ѿ�ת��Ϊunix������/xx/xx/xx.txt�����Ҳ���������б��"/"
	* @return Ŀ��·��
	*/
	QString getDestDirectory() const { return m_strDstDir; }

	/**
	* @brief ����·�������б�
	* @param[in] lstDirFilter ·�������б�
	* @return void
	*/
	void setDirectoryFilters(const QStringList& lstDirFilter) { m_lstDirFilter = lstDirFilter; }
	/**
	* @brief ��ȡ·�������б�
	* @return ·�������б�
	*/
	QStringList getDirectoryFilters()  const { return m_lstDirFilter; }

	/**
	* @brief �����ļ������б�
	* @param[in] lstFileFilter �ļ������б�
	* @return void
	*/
	void setFileFilters(const QStringList& lstFileFilter) { m_lstFileFilter = lstFileFilter; }

	/**
	* @brief ��ȡ�ļ������б�
	* @return �ļ������б�
	*/
	QStringList getFileFilters() const { return m_lstFileFilter; }

	/**
	* @brief ָ��·���Ƿ񱻹���
	* @param[in] strDirectory ָ��·��(����·��)
	* @param[in] bSource true:Դ·���е�·����false:Ŀ��·���е�·��
	* @return true:·�������ˡ� false:·��δ���ˣ���Ҫ��������
	*/	
	bool isFilteredDirectory(const QString& strDirectory, bool bSource) const;
	/**
	* @brief ָ���ļ��Ƿ񱻹���
	* @param[in] strFileName ָ���ļ���������·����
	* @param[in] bSource true:Դ·���е��ļ���false:Ŀ��·���е��ļ�
	* @return true:�ļ������ˡ� false:�ļ�δ���ˣ���Ҫ��������
	*/		
	bool isFilteredFile(const QString& strFileName, bool bSource) const;
private:
	QString m_strSrcDir;
	QString m_strDstDir;
	QStringList m_lstDirFilter;
	QStringList m_lstFileFilter;
};

class CSync {
public:
	CSync();
	~CSync();

public:
	/**
	* @brief ִ��ͬ��
	* @return true:�ɹ���false:ʧ��
	*/
	bool exec();

private:
	/**
	* @brief ��ȡ����
	* @return void
	*/
	void readConfig();
	
	/**
	* @brief ��������
	* @return void
	*/	
	void clear();

	/**
	* @brief ��ȡָ����Ŀ¼�Ĵ������ļ��б������б��Ѿ��������ˣ���������Ŀ¼���ļ��ų����⡣
	* @param[in] strDirectory ָ��·��
	* @param[in]  syncConfig ͬ��������
	* @param[in] bSource true:ָ��·����Դ·����false:ָ��·����Ŀ��·��
	* @return �������ļ��б�
	*/	
	QStringList getSyncFileList(const QString& strDirectory, const CSyncConfig& syncConfig, bool bSource);

private:
	QList<CSyncConfig> m_lst;
};

#endif  // _MYCLASS_DLL_H