/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: splashscreen.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/7 
*/

#pragma once

#include <QSplashScreen>

QT_BEGIN_NAMESPACE
class QProgressBar;
QT_END_NAMESPACE


class CSplashScreen : public QSplashScreen
{
	Q_OBJECT
public:
    CSplashScreen(const QPixmap &pixmap = QPixmap());
	~CSplashScreen(){;}

public Q_SLOTS:
    void setProgress(quint32);

private:
    //������
    QProgressBar * m_pProgressBar;
};
