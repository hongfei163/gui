/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file editor.cpp
\brief CEditor实现文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/1
*/
#include "editor.h"

CEditor::CEditor(QWidget* parent) :
    QLabel (parent) {
    setMouseTracking(true);
    setAutoFillBackground(true);
}
void CEditor::paintEvent(QPaintEvent* event){
    QLabel::paintEvent(event);
}

void CEditor::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    if (text() == QString::fromLocal8Bit("否")) {
        setText(QString::fromLocal8Bit("是"));
    }
    else {
        setText(QString::fromLocal8Bit("否"));
    }
    emit sig_editFinished();
}
