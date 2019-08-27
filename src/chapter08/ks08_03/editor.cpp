/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file editor.cpp
\brief CEditorʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
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
    if (text() == QString::fromLocal8Bit("��")) {
        setText(QString::fromLocal8Bit("��"));
    }
    else {
        setText(QString::fromLocal8Bit("��"));
    }
    emit sig_editFinished();
}
