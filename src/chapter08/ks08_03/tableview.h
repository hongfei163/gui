/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file tableview.h
\brief tableview头文件
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
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
     * @brief 重写父类的鼠标按下事件
     * @param[in] event 鼠标按下事件对象
    */
    virtual void mousePressEvent(QMouseEvent* event) override;
private:
    QModelIndex m_indexLast;
};
