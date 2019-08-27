/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: address.h
\brief  CWidgetAddress���Ķ����ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef ADDRESS_H
#define ADDRESS_H

#include "ui_address.h" // ͷ�ļ���������: address.ui  ---> ui_address.h


// ��������������ui�ļ��жԻ����������������鿴���е�����
class CWidgetAddress : public QWidget
{
    Q_OBJECT
public:
    CWidgetAddress(QWidget* pParent);
    ~CWidgetAddress();

Q_SIGNALS:

public slots:
    void slot_btnSaveClicked();

private:
    Ui::CWidgetAddressBase ui;
};
#endif  // ADDRESS_H