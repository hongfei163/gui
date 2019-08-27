/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: myclass.h
\brief exe+dll����ʾ�����������Ķ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9 
* please import ks04_19_dll.dll
*/

#ifndef _KS19_CONFIG_DLL_H
#define _KS19_CONFIG_DLL_H


// ��̬�⵼���궨��
#ifdef WIN32		// windows platform
#	if defined __KS04_19_CONFIG_DLL_SOURCE__
#		define KS04_19_CONFIG_Export __declspec(dllexport)
#	else
#		define KS04_19_CONFIG_Export __declspec(dllimport)
#	endif

#else				// other platform
#  define KS04_19_CONFIG_Export
#endif // WIN32

#include <qglobal.h>

class KS04_19_CONFIG_Export CConfig {
public:
    /**
    * @brief  ���캯��������Ϊ˽�е�Ŀ���Ƿ�ֹ����ʹ�ø��๹��������
    * @return ��
    */
    CConfig(){}
    /**
    * @brief  �����캯��������Ϊ˽�е�Ŀ���Ƿ�ֹ������delete����ɾ������������
    * @return ��
    */
	~CConfig(){}  
	/**
    * @brief  ����������ѡͼԪʱ����ײ�뾶
    * @param[in] dR  �뾶
    */
    void setSelectRadius(qreal dR) { m_dSelectRadius = dR; }
    /**
    * @brief  ��ȡ������ѡͼԪʱ����ײ�뾶
    * @return �뾶
    */
    qreal getSelectRadius() const { return m_dSelectRadius; }
private:    
   


 private:
   static CConfig s_config;	    /// ���ö���ʵ��
   qreal m_dSelectRadius;       /// ���������뾶

};


#endif  // _KS19_CONFIG_DLL_H