/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: main.cpp
\brief QInputDialog的使用
            
\author 女儿叫老白   http://xingdianketang.cn/
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
	
 
}
/**
* @brief  获取多行文本
* @return 无
*/
void example02(){
 
}

/**
* @brief  获取条目
* @return 无
*/
void example03() {
   
}

/**
* @brief  获取整数
* @return 无
*/
void example04() {
  
}

/**
* @brief  获取浮点数
* @return 无
*/
void example05() {
   

}
