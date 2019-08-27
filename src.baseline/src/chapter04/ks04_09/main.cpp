/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief  QMessageBox��ʹ��
            
\author Ů�����ϰ�   http://xingdianketang.cn/
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
* @brief  ������ͨ��ʾ��Ϣ
* @return ��
*/
void example01(){
	
   

}
/**
* @brief  �������ش�����Ϣ
* @return ��
*/
void example02(){
  
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example03() {
   
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example04() {
    
}
