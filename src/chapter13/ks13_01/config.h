/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: config.h
\brief exe+dll����ʾ�����������Ķ���ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/3
* 
*/

#ifndef _KS12_03_CONFIG_H
#define _KS12_03_CONFIG_H

#include <qglobal.h>
#include <QMutex>

class CConfig {
public:
    /**
    * @brief  �����������ʽӿ�
    * @return ��������������
    */
    static CConfig& instance();
    /**
    * @brief  ���ý�ʦ����
    * @param[in] n  ��ʦ����
    */
    void setTeacherNumber(quint16 n);
    /**
    * @brief  ��ȡ��ʦ����
    * @return ��ʦ����
    */
    quint16 getTeacherNumber();

    /**
    * @brief  ����ѧԱ����
    * @param[in] n  ѧԱ����
    */
    void setStudentNumber(quint16 n);
    /**
    * @brief  ��ȡѧԱ����
    * @return ѧԱ����
    */
    quint16 getStudentNumber();
private:    
    /**
    * @brief  ���캯��������Ϊ˽�е�Ŀ���Ƿ�ֹ����ʹ�ø��๹��������
    * @return ��
    */
    CConfig():m_nTeacherNumber(0), m_nStudentNumber(0){}

    /**
    * @brief  �������캯��������Ϊ˽�е�Ŀ���Ƿ�ֹ����������Ĭ�ϵĿ�������
    *         ������ʽ���������Ķ�����
    * @return ��
    */
    CConfig(const CConfig&);
    
    /**
    * @brief  �����캯��������Ϊ˽�е�Ŀ���Ƿ�ֹ������delete����ɾ������������
    * @return ��
    */
    ~CConfig() {}


 private:
   static CConfig m_config;     /// ��̬����
   qint16 m_nTeacherNumber;     /// ��ʦ����
   qint16 m_nStudentNumber;     /// ѧԱ����
   QMutex m_mtx;                /// ������

};


#endif  // _KS12_03_CONFIG_H