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
	void openFile(const QString &fileName);

protected:
    /*
     * @brief ��ʼ������
    */
	void initialDialog();
private:
    /*
     * @brief ��ʼ�������ӿؼ�
    */
    void initialControls();
    /*
     * @brief �����źŲ�
    */
	void connectSignalsAndSlots();
    /*
     * @brief ����movie(gif)���û������ķ�Χ
    */
    void changeFrameSliderMaxMin();

private slots:
    /*
     * @brief ����gif�ļ��ۺ���
    */
	void slot_open();
    /*
     * @brief ��ͣ�ۺ���
     * @param[in] b true:��ͣ, false:����
    */
    void slot_pause(bool b);
    /*
     * @brief ���°�ť��״̬�����簴ť��ʹ��״̬(enable/disable)
    */
	void slot_updateButtons();
    /*
     * @brief ���ݶ��������ٶȣ����»������Ļ���λ��
    */
    void slot_updateFrameSlider();
    /*
     * @brief ���ݻ������Ļ���λ�ø��¶����Ĳ��Ž���
     * @param[in] value ��ǰ��������
    */
    void slot_gotoFrame(int value);
private:
	Ui::CDialog ui;
	QString m_currentDirectory;
	QMovie* m_movie;
};


