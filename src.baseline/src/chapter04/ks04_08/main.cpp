/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief      QVariant��ʹ��
            
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include "qglobal.h"

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


	// example01 
	if (0) {
		example01();
	}

	// example02 
	if (1) {
		example02();
	}

    // example03 
    if (0) {
        example03();
    }

    // example03 
    if (0) {
        example04();
    }

	char ch = '\0';
	cin >> ch;

	return 0;
}

/**
* @brief  ����Qt����QVariant����ת��
* @return ��
*/
void example01(){
	
	
}
/**
* @brief  QVariant::value<>()��ʹ��
* @return ��
*/
void example02(){
	
}

/**
* @brief  QVariantList��ʹ��
* @return ��
*/
void example03() {


}

/**
* @brief  QVariant::nameToType(), QVariant::typeToName()
* @return ��
*/
void example04() {



}
