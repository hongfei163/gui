/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file main.cpp
\brief delegate example main()����
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/


#include <QApplication>
#include <QFile>
#include <QHeaderView>

#include "delegate.h"
#include "tablemodel.h"
#include "treeview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CTableModel model(CTableModel::Eattr_Max, 2);
	CTreeView treeView;
	treeView.setAlternatingRowColors(true);
	treeView.setModel(&model); // ��ģ����ͼ��������
	
	QFile file(":/qss/treeview.qss");
	bool bok = file.open(QFile::ReadOnly);
	if (bok) {
		QString styleSheet = QString::fromLatin1(file.readAll());
		treeView.setStyleSheet(styleSheet);
	}
   // tableView.horizontalHeader()->setStretchLastSection(true);

    CDelegate delegate;
	treeView.setItemDelegate(&delegate); // Ϊ��ͼ���ô���
	QModelIndex index;

    for (int row = 0; row < CTableModel::Eattr_Max; ++row) {
		// ����д��0��
        index = model.index(row, 0, QModelIndex());
		if (CTableModel::EAttr_Id == row) {
			model.setData(index, "Id");
		}
		else if (CTableModel::EAttr_Descrition == row)	{
			model.setData(index, QString::fromLocal8Bit("����"));
		}
		else if (CTableModel::EAttr_Checked == row)	{
			model.setData(index, QString::fromLocal8Bit("��֤��־"));
		}
		else if (CTableModel::EAttr_LastOneFlag == row)	{
			model.setData(index, QString::fromLocal8Bit("�Ƿ�����һ��"));
		}
		else if (CTableModel::Eattr_Animate == row)	{
			model.setData(index, QString::fromLocal8Bit("����"));
			model.insertRows(0, 2, index);		// ����������������
			model.insertColumns(0, 2, index);	// ��������(������������ֵ)
			model.setData(model.index(CTableModel::Eattr_AnimateSpeed, 0, index), QString::fromLocal8Bit("�ٶ�"));
			model.setData(model.index(CTableModel::Eattr_AnimateType, 0, index), QString::fromLocal8Bit("����"));
		}
		
		// ����д��1��
		index = model.index(row, 1, QModelIndex());
		if (CTableModel::EAttr_Id == row) {
			model.setData(index, 0);
		}
		else if (CTableModel::EAttr_Descrition == row) {
			model.setData(index, QString::fromLocal8Bit("��ע"));
		}
		else if (CTableModel::EAttr_Checked == row) {
			model.setData(index, false);
		}
		else if (CTableModel::EAttr_LastOneFlag == row) {
			model.setData(index, QVariant(static_cast<int>(Qt::Checked)));
		}
		else if (CTableModel::Eattr_Animate == row) {
			index = model.index(row, 0, QModelIndex());
			model.setData(model.index(0, 1,index), QVariant(static_cast<int>(CTableModel::EAnimateSpeed_Normal)));
			model.setData(model.index(1, 1, index), 1);
		}
    }
	// tmp
	//for (int row = 0; row < CTableModel::Eattr_Max; ++row) {
	//	index = model.index(row, 1);
	//	tableView.openPersistentEditor(index);
	//}
	treeView.setWindowTitle(QObject::tr("Delegate Example"));
	treeView.show();
    return app.exec(); // ��app��������
}


