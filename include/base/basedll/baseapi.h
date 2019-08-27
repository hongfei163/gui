/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: baseapi.h
\brief ͨ��dll�ӿڶ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/10 
* please import basedll.dll
*/

#ifndef _BASEAPI_H
#define _BASEAPI_H

#include "base_export.h"

#include <QColor>
#include <QString>

namespace ns_train {

    // == ��ɫ���� =============================================================================================
    /**
    * @brief ������ɫ, ���ַ���ת��ΪQColor.
             ��ʽ:r,g,b[,a], alpha��ѡ

    * @param[in] strColor  ���������ַ���
    * @return �������õ���ɫ
    */
    BASE_API QColor parseColor(const QString& strColor);

    /**
    * @brief ��QColor��ʽ��δ�ַ���,�����ĸ�ʽ:r,g,b,a

    * @param[in] clr  ��ת������ɫ
    * @return �������õ���ɫ�ַ���
    */
    BASE_API QString getColorRgbValue(const QColor& clr);

    // == �ļ����� =============================================================================================

    /**
    * @brief ��ȡָ��path���ַ���, ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx"
             �ӿ��ڲ�����:
             1. ��"\\"ת��Ϊ"/"
             2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ�����磬 ���룺"$TRAINDEVHOME/src"��������"d:/xingdianketang/project/gui/src/"

    * @param[in] strPath ָ��·��
    * @return �ļ���, ȫ·��
    */
    BASE_API QString getPath(const QString& strPath);

    /**
    * @brief ��ȡָ��path���ڵ�ȫĿ¼��, ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx.yy"
             �ӿ��ڲ�����:
             1. ��"\\"ת��Ϊ"/"
             2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ�����磬 ���룺"$TRAINDEVHOME/src/a.txt"��������"d:/xingdianketang/project/gui/src/"

    * @param[in] strPath ָ��·��
    * @return �ļ�������Ŀ¼
    */
    BASE_API QString getDirectory(const QString& strPath);
    /**
    * @brief ��ȡָ���ļ��������ƣ�����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx.yy"
             �ӿ��ڲ�����:
             1. ��"\\"ת��Ϊ"/"
             2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ�����磬 ���룺"$TRAINDEVHOME/src/a.txt"��������"a.txt"

    * @param[in] strFilePath ָ���ļ���ȫ·����
    * @return �ļ���(a.txt)
    */
    BASE_API QString getFileName(const QString& strFilePath);

	/**
	* @brief ��ȡָ��strDirectory�ĵ�ǰ��Ŀ¼��, ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx/xxx/"
	�ӿ��ڲ�����:
	1. ��"\\"ת��Ϊ"/"
	2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ�����磬 ���룺"$TRAINDEVHOME/src/exchange"��������"exchange"

	* @param[in] strDirectory ָ��·��
	* @return ��ǰ��Ŀ¼��
	*/
	BASE_API QString getNameOfDirectory(const QString& strDirectory);

    /**
    * @brief ��ȡָ��Ŀ¼�µ������ļ���

    * @param[in] strPath ָ��·��,�ڲ��Ὣ"\\"ת��Ϊ"/"��
    *                    ��֧�ֻ�������������ϣ��ʹ�û�������������ʹ��getPath()����ת����
    * @param[in] nameFilters �ļ������˷�,����:"*.h"
    * @param[in] bRecursive true:�ݹ�. false:����Ŀ¼
    * @return �ļ����б�, ȫ·��
    */
    BASE_API QStringList getFileList(const QString& strPath, const QStringList& nameFilters, bool bRecursive);
	/**
	* @brief ��ȡָ���ļ�����ָ��Ŀ¼������·��, ���磬"d:/temp/file/a.txt",������ "d:/temp/"������·��Ϊ"/file/a.txt"��
	* @param[in] strFileName ָ���ļ���������·����
	* @param[in] strDirectory ָ��·����������·���������Բ��������ġ�/����
	* @return ����·��
	*/
	BASE_API QString getReleativePath(const QString& strFileName, const QString& strDirectory);

	/**
	* @brief ��ȡָ���ļ���md5�롣
	* @param[in] strFileName ָ���ļ���������·����
	* @return md5��
	*/
	BASE_API QByteArray getMd5(const QString& strFileName);

}
#endif  // _BASEAPI_H