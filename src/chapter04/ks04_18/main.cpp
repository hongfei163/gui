/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief main()������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/

#include <QList>
#include "qglobal.h"

#include <iostream>

#include "base/basedll/baseapi.h"
#include "city.h"
#include "country.h"
#include "province.h"

using std::cout;
using std::endl;

void example01(bool);
void example02(void);
void example03(void);

void print(CCountry* pCountry);

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	bool bBinary = 1;

	example01(bBinary);

	if (bBinary) {
		example02();
	}
	else {
		example03();
	}
		
	system("pause");
	return 0;
}


/**
* @brief ��ʼ�����ݲ����л�.
* @param[in] bBinary true:����Ϊ������, false:����ΪXML
* @return void
*/
void example01(bool bBinary) {
	CProvince* pProvince = NULL;
	CCity* pCity = NULL;
	CCountry* pCountry = new CCountry(QString::fromLocal8Bit("�й�"));
	if (NULL == pCountry) {
		return;
	}

  
    pCountry->addCustomData("flag", QString::fromLocal8Bit("���Ǻ���"));
    pCountry->addCustomData(QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���¾�������"));

	// add province
	{
		pProvince = new CProvince();
		pCountry->addProvince(pProvince);
		pProvince->setCountry(pCountry);
		pProvince->setName(QString::fromLocal8Bit("ɽ��"));
		// add city
		pCity = new CCity();
		pCity->setName(QString::fromLocal8Bit("����"));
		pCity->setProvince(pProvince);
		pProvince->addCity(pCity);

		// add city
		pCity = new CCity();
		pCity->setName(QString::fromLocal8Bit("�ൺ"));
		pCity->setProvince(pProvince);
		pProvince->addCity(pCity);
	}
	// add province
	{
		pProvince = new CProvince();
		pCountry->addProvince(pProvince);
		pProvince->setCountry(pCountry);
		pProvince->setName(QString::fromLocal8Bit("�ӱ�"));
		// add city
		pCity = new CCity();
		pCity->setName(QString::fromLocal8Bit("������"));
		pCity->setProvince(pProvince);
		pProvince->addCity(pCity);

		// add city
		pCity = new CCity();
		pCity->setName(QString::fromLocal8Bit("�żҿ�"));
		pCity->setProvince(pProvince);
		pProvince->addCity(pCity);
	}

	cout << "----------------------------------------" << endl;
	cout << "save file content:" << endl;
	// ��ӡ����
	print(pCountry);

	// ���л�
	QString strFileName = (bBinary?
							ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_18/country.dat"):
							ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_18/country.xml"));
	if (bBinary) {
		pCountry->serializeBinary(strFileName, NULL);
	}
	else {
		pCountry->serializeXML(strFileName, NULL);
	}

	// �ͷ��ڴ�
	delete pCountry;
	
}


void print(CCountry* pCountry) {
	QList<CProvince*> lstProvinces;
	QList<CProvince*>::iterator iteProvince;
	QList<CCity*> lstCities;
	QList<CCity*>::iterator iteCity;
	if (NULL == pCountry) {
		return;
	}

	cout << pCountry->getName().toLocal8Bit().data() << endl;
    QStringList lst;
    pCountry->getAllCustomDataName(lst);
    QStringList::iterator iteName = lst.begin();
    QVariant var;
    while (iteName != lst.end()) {
        var = pCountry->getCustomData(*iteName);
        cout << (*iteName).toLocal8Bit().data() << ":" << var.toString().toLocal8Bit().data() << endl;
        iteName++;
    }

	pCountry->getProvinces(lstProvinces);
	iteProvince = lstProvinces.begin();
	while (iteProvince != lstProvinces.end()) {
		cout << "\tʡ(��):" << (*iteProvince)->getName().toLocal8Bit().data() << endl;
		(*iteProvince)->getCities(lstCities);
		iteCity = lstCities.begin();
		while (iteCity != lstCities.end()) {
			cout << "\t\t����:" << (*iteCity)->getName().toLocal8Bit().data() << endl;
			iteCity++;
		}
		iteProvince++;
	}

}

/**
* @brief ��ȡ�����ƣ������л�.
* @return void
*/
void example02(void) {
	CCountry* pCountry = new CCountry();
	QString strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_18/country.dat");
	pCountry->deSerializeBinary(strFileName, NULL);

	cout << "----------------------------------------" << endl;
	cout << "read file content:" << endl;

	// ��ӡ����
	print(pCountry);

}

/**
* @brief ��ȡXML�������л�.
* @return void
*/
void example03(void) {
	CCountry* pCountry = new CCountry();
	QString strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_18/country.xml");
	pCountry->deSerializeXML(strFileName, NULL);

	cout << "----------------------------------------" << endl;
	cout << "read file content:" << endl;

	// ��ӡ����
	print(pCountry);

}