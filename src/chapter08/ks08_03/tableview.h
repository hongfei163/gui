/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file tableview.h
\brief tableviewͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#pragma once

#include <QTableView>


class CTableView :public QTableView {
public:
    explicit CTableView(QWidget* parent) : QTableView(parent){}
    virtual ~CTableView(){}
protected:
    /*
     * @brief ��д���������갴���¼�
     * @param[in] event ���갴���¼�����
    */
    virtual void mousePressEvent(QMouseEvent* event) override;
private:
    QModelIndex m_indexLast;
};
