/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file tablemodel.cpp
\brief  Tableģ������ʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#include "tablemodel.h"

CTableModel::CTableModel(QObject *parent):
    QStandardItemModel(parent) {

}

CTableModel::CTableModel(int rows, int columns, QObject *parent):
                        QStandardItemModel(rows, columns, parent){

}


Qt::ItemFlags CTableModel::flags(const QModelIndex &index) const {
    // ֻ�е�1���������༭
    Qt::ItemFlags itemFlags;
    if (1 != index.column()){
        itemFlags &= (~Qt::ItemIsEditable); // Qt::ItemIsEditable��ʾ�ɱ༭��
                                            // ~Qt::ItemIsEditable��ʾȡ���������ɱ༭��
        return itemFlags;
    }
    else {
        return QStandardItemModel::flags(index);
    }
}


QVariant CTableModel::data(const QModelIndex &index,
                            int role) const {

    QVariant var;
    if (Qt::EditRole == role)
    {
        return QStandardItemModel::data(index, role);
    }
    else if (Qt::DisplayRole != role) {
        return QStandardItemModel::data(index, role);
    }

    var = data(index, Qt::EditRole);
    if (0 == index.column()){
        return var;
    }

    switch (index.row()){

    case CTableModel::EAttr_Checked:
        var = (var.toBool() ? "no" : "yes"); // 0:yes, 1:no
        break;
    case CTableModel::EAttr_LastOneFlag:
        var = (var.toInt() ? true : false);
        break;
    case CTableModel::Eattr_AnimateSpeed:
    {
        CTableModel::EAnimateSpeed eSpeed =
                static_cast<CTableModel::EAnimateSpeed>(var.toInt());
        switch (eSpeed) {
        case CTableModel::EAnimateSpeed_Slow:
            var = QString::fromLocal8Bit("����");
            break;
        case CTableModel::EAnimateSpeed_Normal:
            var = QString::fromLocal8Bit("����");
            break;
        case CTableModel::EAnimateSpeed_Fast:
            var = QString::fromLocal8Bit("����");
            break;
        default:
            break;
        }
    }
        break;
    default:
        break;
    }

    return var;
}


bool CTableModel::setData(const QModelIndex &index,
             const QVariant &value,
             int role) {
    if (Qt::EditRole == role) {
        return QStandardItemModel::setData(index, value, role);
    }
    else {
        return false;
    }
}



