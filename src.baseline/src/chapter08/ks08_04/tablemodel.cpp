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

CTableModel::CTableModel(QObject *parent):QStandardItemModel(parent)
{

}

CTableModel::CTableModel(int rows, int columns, QObject *parent)
	:QStandardItemModel(rows, columns, parent)
{
}

int CTableModel::rowCount(const QModelIndex &parent) const 
{
	return QStandardItemModel::rowCount(parent);
}

int CTableModel::columnCount(const QModelIndex &parent) const
{
	return QStandardItemModel::columnCount(parent);
}

QVariant CTableModel::headerData(int section, 
								Qt::Orientation orientation, 
								int role) const {
	return QStandardItemModel::headerData(section, orientation, role);
}

bool CTableModel::setHeaderData(int section, 
								Qt::Orientation orientation, 
								const QVariant &value,
								int role)
{
	return QStandardItemModel::setHeaderData(section, orientation, value, role);
}


Qt::ItemFlags CTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags itemFlags;
	if (0 == index.column()) {
		itemFlags &= (~Qt::ItemIsEditable);// Qt::ItemIsEditable��ʾ�ɱ༭
		return itemFlags;
	}
	else {
		return QStandardItemModel::flags(index);
	}
}

QVariant CTableModel::data(const QModelIndex &index, int role) const
{
	QVariant var;
	if (Qt::EditRole == role) {
		var = QStandardItemModel::data(index, role);
	}
	else if (Qt::DisplayRole == role) {
		var = QStandardItemModel::data(index, Qt::EditRole);
		if (index.column() == 0) { // ��0���������⴦��
			return var;
		}
		switch (index.row())
		{
		case EAttr_Checked:
			var = (var.toBool() ? "yes" : "no");
			break;
		case EAttr_LastOneFlag:
			var = (var.toInt() ? "Y" : "N");
			break;
		case Eattr_AnimateSpeed:
		{
			CTableModel::EAnimateSpeed animateSpeed = 
				static_cast<CTableModel::EAnimateSpeed>(var.toInt());
			switch (animateSpeed)
			{
			case EAnimateSpeed_Slow:
				var = QString::fromLocal8Bit("����");
				break;
			case EAnimateSpeed_Normal:
				var = QString::fromLocal8Bit("����");
				break;
			case EAnimateSpeed_Fast:
				var = QString::fromLocal8Bit("����");
				break;
			}
		}
			break;
		default:
			break;
		}
	}
	return var;
}

bool CTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (Qt::EditRole == role) {
		QStandardItemModel::setData(index,value, role);

		return true;
	}	
	return false;
}
