/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: main.cpp
\brief      QVariant的使用
            
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/

#include <QApplication>
#include <QMessageBox>
#include <iostream>

void example01();
void example02();
void example03();
void example04();

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


	return 0;
}

/**
* @brief  弹出提示信息
* @return 无
*/
void example01(){
	
    QMessageBox::information(NULL, 
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a normal information"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);

}
/**
* @brief  弹出严重错误信息
* @return 无
*/
void example02(){
    QMessageBox::critical(NULL,
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a critical information"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);
}

/**
* @brief  弹出提问信息
* @return 无
*/
void example03() {
    QMessageBox::StandardButton btn = QMessageBox::question(NULL,
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a question information\nPlease make your choice:"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);

    if (QMessageBox::Yes == btn) {
        cout << "button 'Yes' selected." << endl;
    }
    else {
        cout << "button 'No' selected." << endl;
    }
}

/**
* @brief  弹出关于信息
* @return 无
*/
void example04() {
    QMessageBox::about(NULL,
        QObject::tr("Qt Gui Application"),
        QObject::tr("This is an about information"));
}
