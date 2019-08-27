/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: dialog.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8 
*/

#pragma once

#include "ui_dialog.h"
#include <QDialog>


class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* parent);
	~CDialog(){;}
private slots:
    /*
     * @brief ����������ťʱ��Ӧ�Ĳۺ���
     * @param[in] b true:toogled(��ťΪ����״̬), false:not toogled(��ťΪ̧��״̬)
    */
    void slot_popup(bool b);

    /*
     * @brief ���Ͽ���ֵ�ı�ʱ��Ӧ�Ĳۺ���
     * @param[in] idx ��ǰ��ѡ�е������±�
    */
    void slot_cbRoleChanged(int idx);

private:
	Ui::CDialog ui;
};


