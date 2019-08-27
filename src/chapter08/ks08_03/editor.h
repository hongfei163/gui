/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file editor.h
\brief CEditorͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#pragma once

#include <QLabel>

class CEditor : public QLabel {
    Q_OBJECT
public:
    explicit CEditor(QWidget* parent=nullptr);
signals:
    void sig_editFinished();
protected:
    /*
     * @brief ��д������ paintEvent()
     * @param[in] event �����¼�
     * @return void
    */
    virtual void paintEvent(QPaintEvent* event) override;

    /*
     * @brief ��д������ mousePressEvent()
     * @param[in] event �����¼�
     * @return void
    */
    virtual void mousePressEvent(QMouseEvent* event) override;



};
