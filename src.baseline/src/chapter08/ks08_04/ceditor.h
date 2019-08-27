/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file ceditor.h
\brief CEditorͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#ifndef CEDITOR_H
#define CEDITOR_H

#include <QLabel>


class CEditor : public QLabel
{
    Q_OBJECT

public:
	explicit  CEditor(QWidget *parent = 0);

signals:
    void editingFinished();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:

};

#endif
