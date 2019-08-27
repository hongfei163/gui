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
#include <QColor>
#include <QFont>
#include <QPointF>
#include <QVariant>

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
	if (0) {
		example02();
	}

    // example03 
    if (0) {
        example03();
    }

    // example04
    if (1) {
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
	// ����
    QVariant var1(1);
    cout << "this is an integer:" << var1.toInt() << endl;

    // �޷�������
    uint uVal = 599;
    QVariant var2(uVal);
    cout << "this is an unsigned integer:" << var2.toUInt() << endl;

    // ˫���ȸ�����
    qreal dVal = 100.23456;
    QVariant var3(dVal);
    cout << "this is a double:" << var3.toDouble() << endl;
    cout << "this is a double:" << var3.toString().toLocal8Bit().data() << endl;

    // �ַ���
    QString str("I'm a string!");
    QVariant var4(str);
    cout << "this is a string:" << var4.toString().toLocal8Bit().data() << endl;
    //qDebug() << var4;
	
    // QPointF
    QPointF pt(100.34, 200.1);
    QVariant var5(pt);
    cout << "this is a QPointF:" << var5.toPointF().x() << ", " << var5.toPointF().y() << endl;
}
/**
* @brief  QVariant::value<>()��ʹ��
* @return ��
*/
void example02(){

    // QVariant �� QColor ����ת��
    QColor clr1(Qt::darkMagenta);
    QVariant var1(clr1);
    cout << "clr1:" << clr1.redF() << ", " << clr1.greenF() << ", " << clr1.blueF() << endl;

    // ��var1��ԭΪQColor
    QColor clr2 = var1.value<QColor>();
    cout << "clr2:" << clr2.redF() << ", " << clr2.greenF() << ", " << clr2.blueF() << endl;


    // QVariant �� QFont ����ת��
    QFont ft1(QString::fromLocal8Bit("����"));
    ft1.setPointSizeF(12.6);
    QVariant var2(ft1);
    QFont ft2 = var2.value<QFont>();
    cout << "font, family:"
        << ft2.family().toLocal8Bit().data()
        << ", point size = "
        << ft2.pointSizeF()
        << endl;
}

/**
* @brief  QVariantList��ʹ��
* @return ��
*/
void example03() {
    // ����
    QVariant var1(1);

    // �޷�������
    uint uVal = 599;
    QVariant var2(uVal);

    // ˫���ȸ�����
    qreal dVal = 100.23456;
    QVariant var3(dVal);

    // �ַ���
    QString str("I'm a string!");
    QVariant var4(str);

    // QPointF
    QPointF pt(100.34, 200.1);
    QVariant var5(pt);

    QVariantList lst;
    lst << var1 << var2 << var3 << var4 << var5;

    QVariant var;
    QVariantList::iterator iteLst = lst.begin();
    for (; iteLst != lst.end(); iteLst++) {
        var = *iteLst;
        cout << "type is " << var.typeName() << ", value is ";
        switch (var.type()) {
        case QVariant::Int:
            cout << var.toInt() << endl;
            break;
        case QVariant::UInt:
             cout << var.toUInt() << endl;
            break;
        case QVariant::Double:
            cout << var.toDouble() << endl;
            break;
        case QVariant::String:
            cout << var.toString().toLocal8Bit().data() << endl;
            break;
        case QVariant::PointF:
            cout << "x = " << var.toPointF().x() << ", y = " << var.toPointF().y() << endl;
            break;
       default:
            cout << "default"<< endl;
            break;
        }
    }
}

/**
* @brief  QVariant::nameToType(), QVariant::typeToName()
* @return ��
*/
void example04() {

    cout << QVariant::typeToName(QVariant::Int) << endl;   // "int"
    cout << QVariant::typeToName(QVariant::PointF) << endl; // "QPointF"

    qreal dVal = 100.23456;
    QVariant var3(dVal);
    cout << QVariant::nameToType(var3.typeName()) << endl; // 6

}
