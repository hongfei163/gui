/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: splashscreen.h
\brief 演示用头文件
  
\author 女儿叫老白   http://xingdianketang.cn/
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
    //进度条
    QProgressBar * m_pProgressBar;
};
