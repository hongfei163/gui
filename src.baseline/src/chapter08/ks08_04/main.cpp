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
#include <QHeaderView>

#include "delegate.h"
#include "tablemodel.h"
#include "tableview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CTableModel model(CTableModel::Eattr_Max, 2);
	CTableView tableView;

	tableView.setAlternatingRowColors(true);
	tableView.setModel(&model); // ��ģ����ͼ��������
	tableView.horizontalHeader()->setStretchLastSection(true);

    CDelegate delegate;
    tableView.setItemDelegate(&delegate); // Ϊ��ͼ���ô���
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
		else if (CTableModel::Eattr_AnimateSpeed == row)	{
			model.setData(index, QString::fromLocal8Bit("�����ٶ�"));			
		}
		
		// ����д��1��
		index = model.index(row, 1, QModelIndex());
		if (CTableModel::EAttr_Id == row) {
			model.setData(index,0);
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
		else if (CTableModel::Eattr_AnimateSpeed == row) {
			model.setData(index, QVariant(static_cast<int>(CTableModel::EAnimateSpeed_Normal)));
		}
    }

	tableView.setWindowTitle(QObject::tr("Delegate Example"));
    tableView.show();
    return app.exec(); // ��app��������
}


