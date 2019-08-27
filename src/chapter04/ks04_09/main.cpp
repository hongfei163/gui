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

    system("pause");

    return 0;
}

/**
* @brief  ������ͨ��ʾ��Ϣ
* @return ��
*/
void example01() {
    //static StandardButton information(QWidget *parent, const QString &title,
    //    const QString &text, StandardButtons buttons = Ok,
    //    StandardButton defaultButton = NoButton);

    QMessageBox::StandardButton button
        = QMessageBox::information(NULL,
            QObject::tr("Qt Gui Application"),
            QObject::tr("This is a normal information."),
            QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::Discard),
            QMessageBox::Yes);
    if (QMessageBox::Discard == button) {
        cout << "infomation discarded." << endl;
    }
}
/**
* @brief  �������ش�����Ϣ
* @return ��
*/
void example02() {
    //static StandardButton critical(QWidget *parent, const QString &title,
    //    const QString &text, StandardButtons buttons = Ok,
    //    StandardButton defaultButton = NoButton);
    QMessageBox::StandardButton button =
        QMessageBox::critical(NULL,
            QObject::tr("Qt Gui Application"),
            QObject::tr("This is a critical information."),
            QMessageBox::StandardButtons(QMessageBox::Ok | QMessageBox::Discard),
            QMessageBox::Ok);
    if (QMessageBox::Ok == button) {
        cout << "i see the critical information and i will take further step to handle it."
            << endl;
    }
    else {
        cout << "it doesn't matter to me."
            << endl;
    }
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example03() {
    //static StandardButton question(QWidget *parent, const QString &title,
    //    const QString &text, StandardButtons buttons = StandardButtons(Yes | No),
    //    StandardButton defaultButton = NoButton);
    QMessageBox::StandardButton button = QMessageBox::question(NULL,
                                            QObject::tr("Qt Gui Application"),
                                            QObject::tr("Do you like this lesson?")
                                            );
            //                  QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No),
            //                QMessageBox::Yes);
    if (QMessageBox::Yes == button) {
        cout << "I like this lesson." << endl;
    }
    else {
        cout << "I don't agree." << endl;
    }

}

/**
* @brief  ����"����(About)"��Ϣ
* @return ��
*/
void example04() {
    QMessageBox::about(NULL,
        QObject::tr("Qt Gui Application"),
        "copyright: 2018~2019\r\nall rights reserved.");
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example05() {
    //static StandardButton warning(QWidget *parent, const QString &title,
    //    const QString &text, StandardButtons buttons = Ok,
    //    StandardButton defaultButton = NoButton);
    
    QMessageBox::StandardButton button =
        QMessageBox::warning(NULL,
            QObject::tr("Qt Gui Application"),
            QObject::tr("Something dangerous happeded, be careful!!!"));
}
