/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief      QMap��ʹ��
            --���ӳ�Ա
            --����
            --����
            --ɾ��

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

//#include "qglobal.h"
#include <QMap>
#include <QPair>
#include <QString>

#include <iostream>

#include "myclass.h"

void example01();
void example02();
void example03();

void printByIterator(const QMap<uint, QString>& mapObj);

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

	char ch = '\0';
	cin >> ch;

	return 0;
}

/**
* @brief  ��QMap���ӳ�Ա��������
* @return ��
*/
void example01(){
	
	// ���ӳ�Ա
	QMap<uint, QString> mapObj;
	mapObj[1] = "BeiJing";
	mapObj[2] = "ShangHia";
	mapObj[3] = "GuangZhou";
	mapObj[4] = "ShenZhen";

    mapObj.insert(5, "XiaMen");
    	
	// ������Ա-ʹ�õ�����(����)
	//printByIterator(mapObj);
	cout << endl << "-------------- QMap ---------------" << endl;
	cout << "print members using iterator......" << endl;
	QMap<uint, QString>::iterator iteMap = mapObj.begin();
	for (iteMap = mapObj.begin(); iteMap != mapObj.end(); iteMap++) {
		cout << "-- key = " << iteMap.key() << ", value = " << iteMap.value().toLocal8Bit().data() << endl;
	}

	// ����
	//QMap<uint, QString>::iterator iteMap;
	// ������ = map����.find(key);
	iteMap = mapObj.find(5);
	if (iteMap != mapObj.end())	{
		cout << endl << "-------------- QMap ---------------" << endl;
		// ������.key()��ʾ��; ������.value()��ʾ��Ӧ��ֵ
		cout << "find member where key = 5, and value = " << iteMap.value().toLocal8Bit().data() << endl;
	} else {
		cout << "cannot find member from map where key = 5." << endl;
    }

	// ɾ��
	cout << endl << "-------------- QMap ---------------" << endl;
	if (iteMap != mapObj.end())	{
		cout << "erase it from map." << endl;
		mapObj.erase(iteMap);
	} 

	// ������Ա-ʹ�õ�����(����)
	printByIterator(mapObj);    


}
/**
* @brief  ʹ���Զ���������
* @return ��
*/
void example02(){
	// ���ӳ�Ա
	QMap<CMyClass, uint> mapObj;
	CMyClass myclass1(2011, "lisa");
	CMyClass myclass2(2012, "mike");
	CMyClass myclass3(2012, "mike");
	CMyClass myclass4(2013, "john");
	CMyClass myclass5(2013, "ping");
	CMyClass myclass6(2025, "ping");
	// ����������������������ͨ�����Ұ���Ԥ��ִ�У���ҪΪCMyClass���ṩ�������캯����������operator<��������
    mapObj[myclass1] = 1;
    mapObj[myclass2] = 2;
    mapObj[myclass3] = 3;
    mapObj[myclass4] = 4;
    mapObj[myclass5] = 5;
    mapObj[myclass6] = 6;
    
	// ������Ա
	cout << endl << "-------------- QMap ---------------" << endl;
    QMap<CMyClass, uint>::iterator iteMap;
    for (iteMap = mapObj.begin(); iteMap != mapObj.end(); iteMap++) {
        cout << "key = ("<< iteMap.key().getId() << ", " << iteMap.key().getName().toLocal8Bit().data() << "), value = "<< iteMap.value() << endl;
    }

	// ����&ɾ��
	cout << endl << "-------------- QMap ---------------" << endl;
	cout << "begin find member in QMap......" << endl;
	CMyClass myclassx(2013, "john");
	iteMap = mapObj.find(myclassx);
	if (iteMap != mapObj.end()) {
		cout << "find myclassx in map. key = (" << iteMap.key().getId() << ", " << iteMap.key().getName().toLocal8Bit().data() <<"), value = "  << iteMap.value() << endl;
        mapObj.erase(iteMap); // ɾ��
	}
	else {
		cout << "cannot find myclassx in map" << endl;
	}

	cout << endl << "-------------- QMap ---------------" << endl;
	cout << endl << "after erase:" << endl;
    for (iteMap = mapObj.begin(); iteMap != mapObj.end(); iteMap++) {
        cout << "key = (" << iteMap.key().getId() << ", " << iteMap.key().getName().toLocal8Bit().data() << "), value = " << iteMap.value() << endl;
    }
}

/**
* @brief  QMap��value���б����͡�
* @return ��
*/
void example03() {

    // ���ӳ�Ա
    QMap<uint, QStringList> mapObj;
   
    QMap<uint, QStringList>::iterator iteMap;
    
    iteMap = mapObj.find(1);
    if (iteMap == mapObj.end())
    {
        cout << "not found!" << endl;
		if (0) {
			mapObj[1].push_back("hello");// �еı�����ִ�и��д���ʱ����
		}
		else
		{
			// �еı�����������ֱ�Ӷ�δ��ʼ����value������
			// ��Ӧ����������3�д��룺�ȶ���һ��QStringList����lst�������ݲ���lst,Ȼ����lst��Ϊvalue��д��QMap
			QStringList lst;
			lst.push_back("hello");
			mapObj[1] = lst;
		}

    }
    else {
        mapObj[1].push_back("hello");
    } 
}
void printByIterator(const QMap<uint, QString>& mapObj)
{
	cout << endl << "-------------- QMap ---------------" << endl;
	cout << "print members using iterator......" << endl;
	QMap<uint, QString>::const_iterator iteMap = mapObj.constBegin();
	for (iteMap = mapObj.constBegin(); iteMap != mapObj.constEnd(); iteMap++) {
		cout << "-- key = " << iteMap.key() << ", value = " << iteMap.value().toLocal8Bit().data() << endl;
	}
}

