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

#include "tablemodel.h"
#include "delegate.h"
#include "tableview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CTableModel model(CTableModel::Eattr_Max, 2, nullptr);
    CTableView tableView(nullptr);

    tableView.setAlternatingRowColors(true);//
    tableView.horizontalHeader()->setStretchLastSection(true);
    tableView.setModel(&model);

    CDelegate delegate;
    tableView.setItemDelegate(&delegate);

    // Ϊģ����������
    QModelIndex index;
    QModelIndex indexRoot = model.invisibleRootItem()->index();
    for (int row=0; row<CTableModel::Eattr_Max; row++){
        // �����õ�0��
        index = model.index(row, 0, indexRoot);
        if (CTableModel::EAttr_Id == row){
            model.setData(index, "id");
        }
        else if (CTableModel::EAttr_Descrition == row ){
            model.setData(index, QString::fromLocal8Bit("����"));
        }
        else if (CTableModel::EAttr_Checked == row ){
            model.setData(index, QString::fromLocal8Bit("��֤"));
        }
        else if (CTableModel::EAttr_LastOneFlag == row ){
            model.setData(index, QString::fromLocal8Bit("������һ��"));
        }
        else if (CTableModel::Eattr_AnimateSpeed == row ){
            model.setData(index, QString::fromLocal8Bit("�����ٶ�"));
        }
        // �����õ�1��
        index = model.index(row, 1, indexRoot);
        if (CTableModel::EAttr_Id == row){
            model.setData(index, 0);
        }
        else if (CTableModel::EAttr_Descrition == row ){
            model.setData(index, QString::fromLocal8Bit("��ע"));
        }
        else if (CTableModel::EAttr_Checked == row ){
            model.setData(index, 0);// 0:yes, 1:no
        }
        else if (CTableModel::EAttr_LastOneFlag == row ){
            model.setData(index, true);
        }
        else if (CTableModel::Eattr_AnimateSpeed == row ){
            model.setData(index, static_cast<int>(CTableModel::EAnimateSpeed_Slow));
        }
    }

    tableView.setWindowTitle("Delegate Example");
    tableView.show();
    return app.exec(); // ��app��������
}





