/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file tablemodel.h
\brief  Tableģ������ͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#pragma once

#include <QStandardItemModel>

class CTableModel : public QStandardItemModel {
    Q_OBJECT
public:
    /// �����������ĺ���
    enum EAttrIndex {
        EAttr_Id = 0,       /// id
        EAttr_Descrition,	// ����
        EAttr_Checked,		// �Ƿ�����֤
        EAttr_LastOneFlag,	// �Ƿ�����һ��
        Eattr_AnimateSpeed,	// �ٶ�

        Eattr_Max,
    };
    /// �ٶ�ö��ֵ
    enum EAnimateSpeed {
        EAnimateSpeed_Slow = 0, // ����
        EAnimateSpeed_Normal,	// ����
        EAnimateSpeed_Fast,		// ����

        EAnimateSpeed_Max,
    };
public:
    explicit CTableModel(QObject *parent = nullptr);
    CTableModel(int rows, int columns, QObject *parent = nullptr);
    virtual ~CTableModel(){}

    /**
    * @brief  ��ȡĳ�������ı�־
    * @param[in] index ����������
    * @return ָ���������ı�־
    */
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    /**
    * @brief  ��ȡָ����������
    * @param[in] index ����������
    * @param[in] role ��ɫ����setData(). ȡֵ��Χ��Qt::EditRole, Qt::DispalyRole.
    * @return ָ�������ݡ�
    */
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;
    /**
    * @brief  ����ָ����������
    * @param[in] index ����������
    * @param[in] value ����
    * @param[in] role ��ɫ
    * @return true:�ɹ�, false:ʧ�ܡ�
    */
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role = Qt::EditRole) override;
};




