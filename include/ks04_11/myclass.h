/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�����������Ķ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_11_dll.dll
*/

#ifndef _MYCLASS_DLL_H
#define _MYCLASS_DLL_H

#include "ks04_11_export.h"
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
    KS04_11_Export QColor parseColor(const QString& strColor);

    /**
    * @brief ��QColor��ʽ��Ϊ�ַ���,�����ĸ�ʽ:r,g,b,a

    * @param[in] clr  ��ת������ɫ
    * @return �������õ���ɫ�ַ���
    */
    KS04_11_Export QString getColorRgbValue(const QColor& clr);

    // == �ļ����� =============================================================================================

    /**
    * @brief ��ȡָ��path���ַ���, 
	*		 ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx"
    *         �ӿ��ڲ�����:
    *           1. ��"\\"ת��Ϊ"/"
    *           2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ��
	*				���磬 ���룺"$TRAINDEVHOME/src/"��
	*					   ������"d:/xingdianketang/project/gui/src/"
    *			
    * @param[in] strPath ָ��·��
    * @return �ļ���, ȫ·����
	*		  ������������Ŀ¼����ô����ֵ�Ƿ���������б���ɴ�������������
	*		  Ҳ����˵������ʱ��������б�ܣ���ô����ֵҲ��������б�ܣ���֮�򲻴���
    */
    KS04_11_Export QString getPath(const QString& strPath);

    /**
    * @brief ��ȡָ��path���ڵ�ȫĿ¼��, 
	*		 ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx.yy"
    *        �ӿ��ڲ�����:
    *          1. ��"\\"ת��Ϊ"/"
    *          2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ��
	*			  ���磬 ���룺"$TRAINDEVHOME/src/a.txt"��
	*				     ������"d:/xingdianketang/project/gui/src/"
	*
    * @param[in] strPath ָ��·��(�������ļ���ȫ·��)��
	*					 ����:/usr/local/a.txt��Ҳ������Ŀ¼��/usr/local��
    * @return �ļ�������Ŀ¼
    */
    KS04_11_Export QString getDirectory(const QString& strPath);
    /**
    * @brief ��ȡָ���ļ��������ƣ�����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx.yy"
    *        �ӿ��ڲ�����:
    *          1. ��"\\"ת��Ϊ"/"
    *          2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ��
	*			  ���磬 ���룺"$TRAINDEVHOME/src/a.txt"��������"a.txt"
    *
    * @param[in] strFilePath ָ���ļ���ȫ·����
    * @return �ļ���(a.txt)
    */
    KS04_11_Export QString getFileName(const QString& strFilePath);

	/**
	* @brief ��ȡָ��strDirectory�ĵ�ǰ��Ŀ¼��, 
	*		 ����ʹ�û�����������ʽ����Ϊ:"$����������/xxx/xxx/xxx/"
	*		 �ӿ��ڲ�����:
	*			1. ��"\\"ת��Ϊ"/"
	*			2. �Զ������������滻Ϊʵ��·������������ʹ��$XXX�ĸ�ʽ��
	*			   ���磬 ���룺"$TRAINDEVHOME/src/exchange"��������"exchange"
	*
	* @param[in] strDirectory ָ��·��
	* @return ��ǰ��Ŀ¼��
	*/
	KS04_11_Export QString getNameOfDirectory(const QString& strDirectory);

    /**
    * @brief ��ȡָ��Ŀ¼�µ������ļ���

    * @param[in] strPath ָ��·��, �ڲ��Ὣ"\\"ת��Ϊ"/"��֧�ֻ�������������"$TRAINDEVHOME/temp"
    * @param[in] nameFilters �ļ������˷�,����:"*.h"
    * @param[in] bRecursive true:�ݹ�. false:����Ŀ¼
    * @return �ļ����б�, ȫ·��
    */
    KS04_11_Export QStringList getFileList(const QString& strPath, const QStringList& nameFilters, bool bRecursive);
	/**
	* @brief ��ȡָ���ļ�����ָ��Ŀ¼������·��, 
	*		 ���磬"d:/temp/file/a.txt",������ "d:/temp/"������·��Ϊ"/file/a.txt"��
	*
	* @param[in] strFileName ָ���ļ���������·����
	* @param[in] strDirectory ָ��·����������·���������Բ��������ġ�/����
	* @return ����·��,��������б�ܡ�
	*/
	KS04_11_Export QString getReleativePath(const QString& strFileName, const QString& strDirectory);

	/**
	* @brief ��ȡָ���ļ���md5�롣
	* @param[in] strFileName ָ���ļ���������·����
	* @return md5��
	*/
	KS04_11_Export QByteArray getMd5(const QString& strFileName);

}
#endif  // _MYCLASS_DLL_H