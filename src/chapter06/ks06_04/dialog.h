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

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>


class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* parent);
	~CDialog(){;}
private:
    /*
     * @brief ��ʼ��
     * @return void
    */
    void initialize();

private slots:
    /*
     * @brief ��ѡ�е���Ŀ�ƶ����Ҳ��б�
     * @return void
    */
    void slot_move2Right();
    /*
     * @brief ��ѡ�е���Ŀ�ƶ��������б�
     * @return void
    */
    void slot_move2Left();
    /*
     * @brief ���Ҳ��б���������
     * @return void
    */
    void slot_ascending();
    /*
     * @brief ���Ҳ��б���������
     * @return void
    */
    void slot_descending();
    /*
     * @brief �����������
     * @param[in] pItem ����������
     * @return void
    */
    void slot_leftItemClicked(QListWidgetItem* pItem);
    /*
     * @brief �������˫��
     * @param[in] pItem ��˫������
     * @return void
    */
    void slot_leftItemDoubleClicked(QListWidgetItem *pItem);
    /*
     * @brief ����ѡ�е�����仯
     * @param[in] current ��ѡ�е���
     * @param[in] previous ֮ǰѡ�е���
     * @return void
    */
    void slot_leftCurrentItemChanged(QListWidgetItem *current,
                                     QListWidgetItem *previous);
private:
	Ui::CDialog ui;
};

#endif 
