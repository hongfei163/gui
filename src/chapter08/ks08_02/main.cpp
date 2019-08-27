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

#include <QApplication>
#include <QStandardItemModel>
#include <QTreeView>
#include <QHeaderView>

#include <iostream>
#include "base/basedll/baseapi.h"

#include "qglobal.h"
#include "country.h"
#include "province.h"
#include "city.h"


CCountry* createCountry(void);

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

    QApplication app(argc, argv);

    // ����ģ���е�����
    CCountry* pCountry = createCountry();
    if (nullptr == pCountry){
        return 1;
    }

    // ������������ָ��pCountry�е�����
    QList<CProvince*> lstProvinces;
    QList<CCity*> lstCities;

    pCountry->getProvinces(lstProvinces);

    // ����ģ�ͣ�������һЩ����
    QStandardItemModel model;
    QTreeView treeView;
    treeView.setModel(&model);
    treeView.setRootIsDecorated(true); // ����֧�Ƿ���չ��
    treeView.header()->setFirstSectionMovable(false);// false:���в��������ƶ�,true:���������ƶ�
    treeView.header()->setStretchLastSection(true); // ������һ������Ϊ�Զ�����,true:�Զ�����,false:���Զ����졣

    treeView.setWindowTitle("normal tree view");
    treeView.show();

    // ���������ӵ�ģ�ͣ�����������
    // �õ����ڵ�
    QStandardItem* pItemRoot = model.invisibleRootItem();
    // �õ����ڵ�������
    QModelIndex indexRoot = pItemRoot->index();
    // ����country�ڵ�
    QStandardItem* pItemCountry = new QStandardItem(pCountry->getName());
    // ��country�ڵ���Ϊ���ڵ����ӽڵ�
    pItemRoot->appendRow(pItemCountry);
    // ����country�����塢��ɫ
    QFont ft(QString::fromLocal8Bit("����"), 16);
    ft.setBold(true);
    pItemCountry->setData(ft, Qt::FontRole);
    pItemCountry->setData(QColor(Qt::red), Qt::TextColorRole);
    QImage image(":/images/china.png");
    pItemCountry->setData(image.scaled(QSize(24, 24)), Qt::DecorationRole);

    // ���� pItemRoot �������Ա���ʾʡ�ĸ���
    const int COLUMNCOUNT = 2;
    pItemRoot->setColumnCount(COLUMNCOUNT);
    // ��������������֮���������ñ����и��е����ݡ����в�����ʱ������������Ч��
    model.setHeaderData(1, Qt::Horizontal, "sub item count", Qt::DisplayRole);

    // ��Country�ڵ����ڵ��еĵ�1����ʾʡ�ĸ���
    model.setData(model.index(0, 1, indexRoot), lstProvinces.size());

    // ����������ʡ�����������ڵ�
    QStandardItem* pItemProvince = nullptr;
    QStandardItem* pItemCity = nullptr;
    int idProvince = 0;
    QList<CProvince*>::iterator iteProvince = lstProvinces.begin();
    QList<CCity*>::iterator iteCity;
    while (iteProvince != lstProvinces.end()) {
        // ����ʡ�ڵ㣬�����ӵ����ҽڵ����¼�
        pItemProvince = new QStandardItem((*iteProvince)->getName());
        pItemCountry->appendRow(pItemProvince);

        pItemCountry->setColumnCount(COLUMNCOUNT);

        (*iteProvince)->getCities(lstCities);
        // ����Province�ڵ��ĵ�0�е��ı���ɫΪ��ɫ
        model.setData(model.index(idProvince, 0, pItemCountry->index()),
                      QColor(Qt::blue),
                      Qt::TextColorRole);

        // ����Country�ڵ���1������Ϊ���и���
        model.setData(model.index(idProvince, 1, pItemCountry->index()),
                      lstCities.size());

        // �������г���
        iteCity = lstCities.begin();
        while (iteCity != lstCities.end()) {
            // �������нڵ�
            pItemCity = new QStandardItem((*iteCity)->getName());
            // ���ӳ��нڵ�
            pItemProvince->appendRow(pItemCity);

            iteCity++;
        }

        idProvince++;

        iteProvince++;
    }
    return app.exec();
}


/**
* @brief����CCountry����.
* @return CCountry����ָ��
*/
CCountry* createCountry(void) {
	CProvince* pProvince = NULL;
	CCity* pCity = NULL;
	CCountry* pCountry = new CCountry(QString::fromLocal8Bit("�й�"));
	if (NULL == pCountry) {
		return NULL;
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

		// add city
		pCity = new CCity();
		pCity->setName(QString::fromLocal8Bit("����"));
		pCity->setProvince(pProvince);
		pProvince->addCity(pCity);
	}

	// ���ع�����CCountry����
	return pCountry;
	
}
