/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: sync.cpp
\brief �ļ�ͬ����ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
*/
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QDomDocument>

#include "myclass.h"
#include "sync.h"

//////////////////////////////////////////////////////////////////////////////
CSyncConfig::CSyncConfig()
{

}
CSyncConfig::CSyncConfig(const CSyncConfig& right) {
	setSourceDirectory(right.getSourceDirectory());
	setDestDirectory(right.getDestDirectory());
	setDirectoryFilters(right.getDirectoryFilters());
	setFileFilters(right.getFileFilters());
}
CSyncConfig::~CSyncConfig() {

}

CSyncConfig& CSyncConfig::operator=(const CSyncConfig& right) {
	if (this == (&right)) {
		return *this;
	}
	setSourceDirectory(right.getSourceDirectory());
	setDestDirectory(right.getDestDirectory());
	setDirectoryFilters(right.getDirectoryFilters());
	setFileFilters(right.getFileFilters());
	return *this;
}
bool CSyncConfig::isFilteredDirectory(const QString& strDirectory, bool bSource) const {
	bool bFiltered = false;
	Q_UNUSED(bSource);
	QString strDirName = ns_train::getNameOfDirectory(strDirectory);
	if (m_lstDirFilter.contains(strDirName)) {
		return true;
	}
	return bFiltered;
}

bool CSyncConfig::isFilteredFile(const QString& strFileName, bool bSource) const {
	Q_UNUSED(bSource);

	bool bFiltered = false;
	QString strFile = ns_train::getFileName(strFileName);
	QStringList::const_iterator iteLst = m_lstFileFilter.begin();
	QString str;
	for (; iteLst != m_lstFileFilter.end(); iteLst++) {
		str = *iteLst;
		if (str.indexOf("*") >= 0) {
			QRegExp re(str);
			if (strFile.contains(re)) { 
				return true; 
			}
		} 
		else {
			if (strFile == str) {
				return true;
			}
		}
	}

	return bFiltered;

}


//////////////////////////////////////////////////////////////////////////////
CSync::CSync() {
	
	readConfig();

}

CSync::~CSync() {

}

void CSync::clear(){
	m_lst.clear();
}

void CSync::readConfig() {
	
	clear();
	QString strPath = QCoreApplication::applicationDirPath();
	strPath = ns_train::getPath(strPath);
 	if (!strPath.endsWith("/")) {
		strPath += "/";
	}

	QString strFileName = strPath+"syncdir.xml";
	QFile file(strFileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return ;
	}

	QDomDocument document;
	QString error;
	int row = 0, column = 0;

	if (!document.setContent(&file, false, &error, &row, &column))
	{
		return ;
	}
	QDomElement rootDoc = document.firstChildElement();
	if (rootDoc.nodeName() != "sync") {
		return;
	}
	QDomElement eleConfig = rootDoc.firstChildElement();
	QString strName;
	QString strValue;
	while (eleConfig.isElement()) {
		strName = eleConfig.tagName();
		if (strName != "config") {
			eleConfig = eleConfig.nextSiblingElement();
			continue;
		}
		CSyncConfig syncConfig;
		strName = "src";
		strValue = eleConfig.attribute(strName);
		syncConfig.setSourceDirectory(ns_train::getPath(strValue));

		strName = "dst";
		strValue = eleConfig.attribute(strName);
		syncConfig.setDestDirectory(ns_train::getPath(strValue));

		QDomElement ele = eleConfig.firstChildElement();
		while (ele.isElement()) {
			strName = ele.tagName();
			if (strName == "dir") {
				QStringList lstFilter;
				QDomElement eleDir = ele.firstChildElement();
				while (eleDir.isElement()) {
					strName = eleDir.tagName();
					if (strName == "filter") {
						strValue = eleDir.attribute("name");
						lstFilter << strValue;
					}
					eleDir = eleDir.nextSiblingElement();
				}
				syncConfig.setDirectoryFilters(lstFilter);
			}
			else if (strName == "file") {
				QStringList lstFilter;
				QDomElement eleFile = ele.firstChildElement();
				while (eleFile.isElement()) {
					strName = eleFile.tagName();
					if (strName == "filter") {
						strValue = eleFile.attribute("name");
						lstFilter << strValue;
					}
					eleFile = eleFile.nextSiblingElement();
				}
				syncConfig.setFileFilters(lstFilter);
			}
			ele = ele.nextSiblingElement();
		}
		m_lst.push_back(syncConfig);
		eleConfig = eleConfig.nextSiblingElement();
	}

	file.close();

}

bool CSync::exec() {
	QList<CSyncConfig>::iterator iteLst = m_lst.begin();
	QString strReleativePath;
	QString strSourcePath;
	QString strDestPath;
	QString strDirectory;
	QString strSrcFilePath;
	QString strDstFilePath;
	QByteArray srcMd5;
	QByteArray dstMd5;
	QString strPath;
	QDir dir;
	for (; iteLst != m_lst.end(); iteLst++ ){
		strSourcePath = (*iteLst).getSourceDirectory();
		strDestPath = (*iteLst).getDestDirectory();
		QStringList lstFiles = getSyncFileList(strSourcePath, *iteLst, true);
		QStringList::iterator iteFile = lstFiles.begin();
		for (; iteFile != lstFiles.end(); iteFile++) {
			// ��ȡ����·��
			strSrcFilePath = *iteFile;
			strReleativePath = ns_train::getReleativePath(strSrcFilePath, strSourcePath);
			// �õ�Ŀ��·��
			strDstFilePath = strDestPath + strReleativePath;
			// ��ȡsource md5��
			srcMd5 = ns_train::getMd5(strSrcFilePath);
			dstMd5 = ns_train::getMd5(strDstFilePath);
			if (srcMd5 != dstMd5) {
				QFile file(strSrcFilePath);
				strPath = ns_train::getDirectory(strDstFilePath);
				dir.setPath(strPath);
				if (!dir.exists()) {
					dir.mkpath(strPath);
				}
				QFile dstFile(strDstFilePath);
				dstFile.remove();
				file.copy(strDstFilePath);
			}
		}
	}

	return true;
}

QStringList CSync::getSyncFileList(const QString& strDirectory, const CSyncConfig& syncConfig, bool bSource) {
	QStringList strAllFileList;
	QStringList strList;
	QStringList namedFilters;
	QString strFileName;
	QString strPath = ns_train::getPath(strDirectory);
	QDir dir;
	dir.setPath(strPath);
	//namedFilters << "*(*.*)";
	QFileInfoList fileInfoList = dir.entryInfoList(namedFilters, QDir::Dirs | QDir::Files | QDir::NoSymLinks);
	QFileInfoList::iterator iteFileInfo = fileInfoList.begin();
	QFileInfo fileInfo;
	for (iteFileInfo = fileInfoList.begin(); iteFileInfo != fileInfoList.end(); iteFileInfo++) {
		fileInfo = *iteFileInfo;
		strFileName = fileInfo.fileName();
		if ((strFileName == ".") || (strFileName == "..")) { // ������Ŀ¼���ϼ�Ŀ¼ָʾ����
			continue;
		}
		if (fileInfo.isDir()) {
			strFileName = fileInfo.filePath();
			if (!syncConfig.isFilteredDirectory(strFileName, bSource)) {
				strList = getSyncFileList(strFileName, syncConfig, bSource);
				strAllFileList += strList;
			}
		}
		else if (fileInfo.isFile()) {
			if (!syncConfig.isFilteredFile(fileInfo.absoluteFilePath(), bSource)) {
				strAllFileList += ns_train::getPath(fileInfo.absoluteFilePath());
			}
		}
	}
	return strAllFileList;
}