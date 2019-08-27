/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief QList��ʹ��

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

//#include "qglobal.h"
#include <QString>
#include <QList>

#include <iostream>
#include <algorithm>

#include "myclass.h"

void example01();
void example02();
void example03();

void printByIndex(const QList<quint16>& lst);
void printByIterator(const QList<quint16>& lst);
void printByIteratorReverse(const QList<quint16>& lst);

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
	if (1) {
		example03();
	}

	char ch = '\0';
	cin >> ch;

	return 0;
}

/**
* @brief  ��QList���ӳ�Ա��������
* @return ��
*/
void example01(){
	
	// ���ӳ�Ա
	QList<quint16> lstObj;
	lstObj.push_back(2011);
	lstObj.push_back(2033);
	lstObj.push_back(2033);
	lstObj.push_back(2042);
	lstObj.push_back(2045);
	// push_front
	lstObj.push_front(2046);


	// ������Ա-ʹ���±�
	printByIndex(lstObj);

	// ������Ա-ʹ�õ�����(����)
	printByIterator(lstObj);

	// ������Ա-ʹ�õ�����(����)
	printByIteratorReverse(lstObj);

	// ����&����
	QList<quint16>::iterator iteList;
	iteList = std::find(lstObj.begin(), lstObj.end(), 2042);
	if (iteList != lstObj.end())	{
		lstObj.insert(iteList, 10000); // insert before
		cout << endl << "-------------- QList ---------------" << endl;
		cout << "insert 10000 before 2042 in list." << endl;
	}
	// ������Ա
	int idxList = 0;
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using idx......" << endl;
	for (idxList = 0; idxList < lstObj.size(); idxList++) {
		cout << "    lstObj[" << idxList << "] =" << lstObj[idxList] << endl;
	}

	// ����&ɾ��
	iteList = std::find(lstObj.begin(), lstObj.end(), 2042);
	if (iteList != lstObj.end())	{
		cout << "erase 2042 from list." << endl;
		lstObj.erase(iteList);
	}
	// ������Ա
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using idx......" << endl;
	for (idxList = 0; idxList < lstObj.size(); idxList++) {
		cout << "    lstObj[" << idxList << "] =" << lstObj[idxList] << endl;
	}


	// ����&ɾ��
	for (iteList=lstObj.begin(); iteList != lstObj.end(); )
	{
		if ((*iteList) == 2033)	{
			cout << "find 2033 in list.erasing..." << endl;
			iteList = lstObj.erase(iteList); // erase()�ӿڻ᷵��ɾ��������һ������λ��
		} else {
			iteList++;
		}
	}
	// ������Ա
	printByIndex(lstObj);
	printByIterator(lstObj);
}
/**
* @brief  ʹ���Զ���������
* @return ��
*/
void example02(){
	// ���ӳ�Ա
	QList<CMyClass> lstObj;
	CMyClass myclass1(2011, "lisa");
	CMyClass myclass2(2012, "mike");
	CMyClass myclass3(2012, "mike");
	CMyClass myclass4(2013, "john");
	CMyClass myclass5(2013, "ping");
	CMyClass myclass6(2025, "ping");

	// ����������������������ͨ�����Ұ���Ԥ��ִ�У���ҪΪCMyClass���ṩ�������캯��
	lstObj.push_back(myclass1);
	lstObj.push_back(myclass2);
	lstObj.push_back(myclass3);
	lstObj.push_back(myclass4);
	lstObj.push_back(myclass5);
	lstObj.push_back(myclass6);

	// ������Ա
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using idx......" << endl;
	int idxList = 0;
	for (idxList = 0; idxList < lstObj.size(); idxList++) {
		cout << "    lstObj[" << idxList << "] : id = " << lstObj[idxList].getId() << ", name = " << lstObj[idxList].getName().toLocal8Bit().data() << endl;
	}

	// ����
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "begin find member in QList......" << endl;
	CMyClass myclassx(2013, "john");
	QList<CMyClass>::iterator iteList = std::find(lstObj.begin(), lstObj.end(), myclassx);
	if (iteList != lstObj.end()) {
		cout << "find myclassx in list." << endl;
	}
	else {
		cout << "cannot find myclassx in list" << endl;
	}
}

/**
* @brief  ʹ���Զ�����ָ��
* @return ��
*/
void example03() {
	// ���ӳ�Ա
	QList<CMyClass*> lstObj;
	CMyClass* pMyclass1 = new CMyClass(2011, "lisa");
	CMyClass* pMyclass2 = new CMyClass(2012, "mike");
	CMyClass* pMyclass3 = new CMyClass(2012, "mike");
	CMyClass* pMyclass4 = new CMyClass(2013, "john");
	CMyClass* pMyclass5 = new CMyClass(2013, "ping");
	CMyClass* pMyclass6 = new CMyClass(2025, "ping");

	// ����ΪCMyClass���ṩ�������캯��
	lstObj.push_back(pMyclass1);
	lstObj.push_back(pMyclass2);
	lstObj.push_back(pMyclass3);
	lstObj.push_back(pMyclass4);
	lstObj.push_back(pMyclass5);
	lstObj.push_back(pMyclass6);

	// ������Ա
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members in custom defined class using idx......" << endl;
	int idxList = 0;
	for (idxList = 0; idxList < lstObj.size(); idxList++) {
		cout << "    lstObj[" << idxList << "] : id = " << lstObj[idxList]->getId() << ", name = " << lstObj[idxList]->getName().toLocal8Bit().data() << endl;
	}

	// �˳�ǰҪ�ͷ��ڴ�
	// ����1��ʹ���±�����
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "desctruct members before exit......" << endl;
	idxList = 0;
	if (false) {
		for (idxList = 0; idxList < lstObj.size(); idxList++) {
			cout << "    deleting " << idxList << ", id = " << lstObj[idxList]->getId() << ", name = " << lstObj[idxList]->getName().toLocal8Bit().data() << endl;
			delete lstObj[idxList];
		}
	}
	else
	{
		// ����2��ʹ�õ���������
		QList<CMyClass*>::iterator iteList = lstObj.begin();
		for (iteList = lstObj.begin(); iteList != lstObj.end(); iteList++, idxList++) {
			if (NULL != *iteList) {
				delete *iteList;
			}
		}
	}

	lstObj.clear();
}

void printByIterator(const QList<quint16>& lstObj){
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using iterator......" << endl;
	QList<quint16>::const_iterator iteList = lstObj.constBegin();
	for (iteList = lstObj.constBegin(); iteList != lstObj.constEnd(); iteList++) {
		cout << "    " << *iteList << endl;
	}
}


void printByIteratorReverse(const QList<quint16>& lstObj){
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using iterator reverse......" << endl;
	QList<quint16>::const_reverse_iterator iteList;
	for (iteList = lstObj.crbegin(); iteList != lstObj.crend(); iteList++) {
		cout << "    " << *iteList << endl;
	}
}

void printByIndex(const QList<quint16>& lstObj){
	cout << endl << "-------------- QList ---------------" << endl;
	cout << "print members using idx......" << endl;
	int idxList = 0;
	for (idxList = 0; idxList < lstObj.size(); idxList++) {
		cout << "    lstObj[" << idxList << "] =" << lstObj[idxList] << endl;
	}
}