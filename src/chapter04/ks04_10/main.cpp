/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief QInputDialog��ʹ��
            
\author Ů�����ϰ�   http://xingdianketang.cn/
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
	if (0) {
		example01();
	}

	// example02 
	if (0) {
		example02();
	}

    // example03 
    if (0) {
        example03();
    }

    // example04 
    if (0) {
        example04();
    }

    // example05 
    if (1) {
        example05();
    }

	return 0;
}

/**
* @brief  ��ȡ�ı�
* @return ��
*/
void example01(){
    QString str = QInputDialog::getText(NULL,
                                        QString::fromLocal8Bit("QInputDialog ʾ��"),
                                        QString::fromLocal8Bit("�������ı�"));
    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("���������ı���"),
                             str);

    str = QInputDialog::getText(NULL,
                                QString::fromLocal8Bit("QInputDialog ʾ��"),
                                QString::fromLocal8Bit("����������"),
                                QLineEdit::Password);
    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("��������������"),
                             QString::fromLocal8Bit("�Ҳ�������!"));
 
}
/**
* @brief  ��ȡ�����ı�
* @return ��
*/
void example02(){
    QString str = QInputDialog::getMultiLineText(NULL,
                                                 QString::fromLocal8Bit("QInputDialog ʾ��"),
                                                 QString::fromLocal8Bit("�����������ı�"));

    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("���������ı���:"),
                            str);
    // �������ı�����
    QStringList lst = str.split("\n");
    QStringList::iterator iteLst = lst.begin();
    while (iteLst != lst.end()) {
        str = *iteLst;
        QMessageBox::information(NULL,
                                 QString::fromLocal8Bit("���������ı���:"),
                                str);

        iteLst++;
    }
}

/**
* @brief  ��ȡ��Ŀ
* @return ��
*/
void example03() {
    QStringList lst;
    lst << QString::fromLocal8Bit("ƻ��")
        << QString::fromLocal8Bit("�㽶")
        << QString::fromLocal8Bit("orange")
        << QString::fromLocal8Bit("pear");

    QString str =
        QInputDialog::getItem(NULL,
            QString::fromLocal8Bit("QInputDialog ʾ��"),
            QString::fromLocal8Bit("��ѡ����ϲ����ˮ��"),
            lst,
            2,
            true);

    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("����ѡ����:"),
                             str);

}

/**
* @brief  ��ȡ����
* @return ��
*/
void example04() {
    int i = QInputDialog::getInt(NULL,
        QString::fromLocal8Bit("QInputDialog ʾ��"),
        QString::fromLocal8Bit("����������:"),
        20,
        -100,
        200,
        10);

    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog ʾ��"),
        QString::fromLocal8Bit("��������������:%1").arg(i));
}

/**
* @brief  ��ȡ������
* @return ��
*/
void example05() {
    double d = QInputDialog::getDouble(NULL,
        QString::fromLocal8Bit("QInputDialog ʾ��"),
        QString::fromLocal8Bit("��ȡ������"),
        100.32,
        -12.4,
        999.5,
        3);

    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialog ʾ��"),
        QString("%1").arg(d));
}
