/*! * Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief	  QVector��ʹ��
		  	

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

//#include "qglobal.h"
#include <QVector>

#include <iostream>
#include <algorithm>

#include "myclass.h"

void example01();
void example02();
void example03();

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
* @brief  ��QVector���ӳ�Ա��������
* @return ��
*/
void example01(){
	
	// ���ӳ�Ա
	QVector<quint32> vecId;
	QVector<quint32>::iterator iteVec = vecId.begin();
	vecId.push_back(2011);
	vecId.push_back(2033);
	vecId.push_back(2033);
	vecId.push_back(2042);
	vecId.push_back(2045);
	// push_front
	vecId.push_front(2046);


	// ������Ա-ʹ���±�
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using idx......" << endl;
	int idxVec = 0;
	for (idxVec = 0; idxVec < vecId.size(); idxVec++) {
		cout << "    vecId[" << idxVec << "] =" << vecId[idxVec] << endl;
	}

	// ������Ա-ʹ�õ�����(����)
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using iterator......" << endl;
	iteVec = vecId.begin();
	idxVec = 0;
	for (iteVec = vecId.begin(); iteVec != vecId.end(); iteVec++) {
		cout << "    " << *iteVec << endl;
	}	

	// ������Ա-ʹ�õ�����(����)
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using reverse iterator......" << endl;
	QVector<quint32>::reverse_iterator reverseIteVec = vecId.rbegin();
	for (reverseIteVec = vecId.rbegin(); reverseIteVec != vecId.rend(); reverseIteVec++) {
		cout << "    " << *reverseIteVec << endl;
	}	

	// ����&����
	iteVec = std::find(vecId.begin(), vecId.end(), 2042);
	if (iteVec != vecId.end())	{ // ��2042֮ǰ��������:10000.
		vecId.insert(iteVec, 10000); // insert before
		cout << endl << "-------------- QVector ---------------" << endl;
		cout << "insert 10000 before 2042 in vector." << endl;
	}
	// ������Ա
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using idx......" << endl;
	for (idxVec = 0; idxVec < vecId.size(); idxVec++) {
		cout << "    vecId[" << idxVec << "] =" << vecId[idxVec] << endl;
	}

	// ����&ɾ��
	iteVec = std::find(vecId.begin(), vecId.end(), 2042);
	if (iteVec != vecId.end())	{
		cout << "erase 2042 from vector." << endl;
		vecId.erase(iteVec);
	}
	// ������Ա
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using idx......" << endl;
	for (idxVec = 0; idxVec < vecId.size(); idxVec++) {
		cout << "    vecId[" << idxVec << "] =" << vecId[idxVec] << endl;
	}


	// ����&ɾ��
	for (iteVec=vecId.begin(); iteVec != vecId.end(); )	{
		if ((*iteVec) == 2033)	{
			cout << "find 2033 in vector." << endl;
			iteVec = vecId.erase(iteVec); // erase()�ӿڻ᷵��ɾ��������һ������λ��
		} else {
			iteVec++;
		}
	}
	// ������Ա
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using idx......" << endl;
	for (idxVec = 0; idxVec < vecId.size(); idxVec++) {
		cout << "    vecId[" << idxVec << "] =" << vecId[idxVec] << endl;
	}

}
/**
* @brief  ʹ���Զ���������
* @return ��
*/
void example02(){
	// ���ӳ�Ա
	QVector<CMyClass> vecObj;
	CMyClass myclass1(2011, "lisa");
	CMyClass myclass2(2012, "mike");
	CMyClass myclass3(2012, "mike");
	CMyClass myclass4(2013, "john");
	CMyClass myclass5(2013, "ping");
	CMyClass myclass6(2025, "ping");

	// ����������������������ͨ�����Ұ���Ԥ��ִ�У���ҪΪCMyClass���ṩ�������캯��
	vecObj.push_back(myclass1);
	vecObj.push_back(myclass2);
	vecObj.push_back(myclass3);
	vecObj.push_back(myclass4);
	vecObj.push_back(myclass5);
	vecObj.push_back(myclass6);

	// ������Ա��ʹ���±�
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using idx......" << endl;
	int idxVec = 0;
	for (idxVec = 0; idxVec < vecObj.size(); idxVec++) {
		cout << "    vecObj[" << idxVec << "] : id = " << vecObj[idxVec].getId() << ", name = " << vecObj[idxVec].getName().toLocal8Bit().data() << endl;
	}

	// ������Ա��ʹ�õ�����
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members using iterator......" << endl;
	QVector<CMyClass>::iterator iteVec = vecObj.begin();
	idxVec = 0;
	for (iteVec = vecObj.begin(); iteVec != vecObj.end(); iteVec++) {
		cout << "    vecObj[" << idxVec++ << "] : id = " << (*iteVec).getId() << ", name = " << (*iteVec).getName().toLocal8Bit().data() << endl;
	}

	// ����
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "begin find member in QVector......" << endl;
	CMyClass myclassx(2013, "john");
	QVector<CMyClass>::iterator iteVecMy = std::find(vecObj.begin(), vecObj.end(), myclassx);
	if (iteVecMy != vecObj.end()) {
		cout << "find myclassx in vector." << endl;
	}
	else {
		cout << "cannot find myclassx in vector" << endl;
	}
}

/**
* @brief  ʹ���Զ���������ָ��
* @return ��
*/
void example03() {
	// ���ӳ�Ա
	QVector<CMyClass*> vecObj;
	CMyClass* pMyclass1 = new CMyClass(2011, "lisa");
	CMyClass* pMyclass2 = new CMyClass(2012, "mike");
	CMyClass* pMyclass3 = new CMyClass(2012, "mike");
	CMyClass* pMyclass4 = new CMyClass(2013, "john");
	CMyClass* pMyclass5 = new CMyClass(2013, "ping");
	CMyClass* pMyclass6 = new CMyClass(2025, "ping");

	// ����ΪCMyClass���ṩ�������캯��
	vecObj.push_back(pMyclass1);
	vecObj.push_back(pMyclass2);
	vecObj.push_back(pMyclass3);
	vecObj.push_back(pMyclass4);
	vecObj.push_back(pMyclass5);
	vecObj.push_back(pMyclass6);

	// ������Ա
	cout << endl << "-------------- QVector ---------------" << endl;
	cout << "print members in custom defined class using idx......" << endl;
	int idxVec = 0;
	for (idxVec = 0; idxVec < vecObj.size(); idxVec++) {
		cout << "    vecObj[" << idxVec << "] : id = " << vecObj[idxVec]->getId() << ", name = " << vecObj[idxVec]->getName().toLocal8Bit().data() << endl;
	}

	// �˳�ǰҪ�ͷ��ڴ�
	// ����1��ʹ���±�����
	if (0)	{
		cout << endl << "-------------- QVector ---------------" << endl;
		cout << "desctruct members before exit......" << endl;
		idxVec = 0;
		for (idxVec = 0; idxVec < vecObj.size(); idxVec++) {
			cout << "    deleting " << idxVec << ", id = " << vecObj[idxVec]->getId() << ", name = " << vecObj[idxVec]->getName().toLocal8Bit().data() << endl;
			delete vecObj[idxVec];
		}
	}
	else
	{
		cout << endl << "-------------- QVector ---------------" << endl;
		cout << "desctruct members before exit......" << endl;
		// ����2��ʹ�õ���������
		QVector<CMyClass*>::iterator iteVec = vecObj.begin();
		idxVec = 0;
		for (iteVec = vecObj.begin(); iteVec != vecObj.end(); iteVec++) {
			if (NULL != *iteVec) {
				cout << "    deleting element:" << idxVec++ << ", id = " << (*iteVec)->getId() << ", name = " << (*iteVec)->getName().toLocal8Bit().data() << endl;
				delete (*iteVec);
			}
		}
	}


	vecObj.clear();
}
