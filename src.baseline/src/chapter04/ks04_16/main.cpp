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

#include <iostream>

#include "qglobal.h"
#include "country.h"
#include "province.h"
#include "city.h"

using std::cout;
using std::endl;

void example01(void);
void print(CCountry* pCountry);
void serialize(QList<CCountry*>& lstCountries);

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	if (true) {
		example01();
	}
		
	return 0;
}


/**
* @brief ��ʼ�����ݲ����л�.
* @return void
*/
void example01(void) {
	CProvince* pProvince = NULL;
	CCity* pCity = NULL;
	CCountry* pCountry = new CCountry(QString::fromLocal8Bit("�й�"));
	if (NULL == pCountry) {
		return;
	}
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

	// ��ӡ����
	print(pCountry);

	// todo, ���л�

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

void serialize(QList<CCountry*>& /*lstCountries*/) {

}
