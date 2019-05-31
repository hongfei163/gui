/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: inputthread.cpp
\brief  CInputThread        

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/4
*/
#include "inputthread.h"
#include <iostream>
#include <QTextStream>

void CInputThread::run()
{
    QTextStream qin(stdin, QIODevice::ReadOnly);
    //QTextStream qout(stdout, QIODevice::WriteOnly);
    while (true) {
        QString qstr;
        qin >> qstr;
        if (qstr == "exit") {
            exit();
            break; 
        }
        else {
            std::cout << "if you want to quit, please input:exit" 
                      << std::endl ;
          //  qout << "if you want to quit, please input:exit\n";
        }
        QThread::msleep(10);
    }
}