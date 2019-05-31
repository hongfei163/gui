/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: main.cpp
\brief QInputDialog的使用
            
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/

#include <QApplication>
#include <QInputDialog>
#include <QMessagebox>
#include <iostream>

void example01();
void example02();
void example03();
void example04();
void example05();

using std::cout;
using std::endl;
using std::cin;

//
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
    QApplication app(argc, argv);

	// example01 
	if (1) {
		example01();
	}

	// example02 
	if (1) {
		example02();
	}

    // example03 
    if (1) {
        example03();
    }

    // example04 
    if (1) {
        example04();
    }

    // example05 
    if (1) {
        example05();
    }

	return 0;
}

/**
* @brief  获取文本
* @return 无
*/
void example01(){
	
    QString str = QInputDialog::getText(NULL, 
                            QString::fromLocal8Bit("QInputDialog示例"), 
                            QString::fromLocal8Bit("获取文本"));
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        str);
}
/**
* @brief  获取多行文本
* @return 无
*/
void example02(){
    QString str = QInputDialog::getMultiLineText(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString::fromLocal8Bit("获取多行文本"));
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        str);
}

/**
* @brief  获取条目
* @return 无
*/
void example03() {
    QStringList lst;
    lst << QString::fromLocal8Bit("苹果")
        << QString::fromLocal8Bit("香蕉")
        << QString::fromLocal8Bit("orange")
        << QString::fromLocal8Bit("pear");
    QString str = QInputDialog::getItem(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString::fromLocal8Bit("获取条目"),
        lst);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        str);
}

/**
* @brief  获取整数
* @return 无
*/
void example04() {
    int i = QInputDialog::getInt(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString::fromLocal8Bit("获取整数"),
        200,
        100,
        1000,
        10);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString("%1").arg(i));
}

/**
* @brief  获取浮点数
* @return 无
*/
void example05() {
    double d = QInputDialog::getDouble(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString::fromLocal8Bit("获取浮点数"),
        200.5,
        100.05,
        999.99);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog示例"),
        QString("%1").arg(d));

}
