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

//#include "qglobal.h"
#include <QString>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include <iostream>


void example01();
void example02();
void example03();

using std::cin;
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	QApplication app(argc, argv);

	// ���ʻ�
	// ��װqt�Դ������ķ���
	const QString localSysName = QLocale::system().name();
	QScopedPointer<QTranslator> qtTranslator(new QTranslator(QCoreApplication::instance()));
	if (qtTranslator->load(QStringLiteral("qt_") + localSysName,
		QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		QCoreApplication::installTranslator(qtTranslator.take());
	}

	// ��װ������Ŀ�ķ����ļ�
	QString strPath = qgetenv("TRAINDEVHOME");	// ��ȡ����������ָ����·��
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/ks03_01.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks04_02.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}

	// example01 
	if (false) {
		example01();
	}

	// example02 
	if (false) {
		example02();
	}
	
	// example03 
	if (false) {
		example03();
	}

	char ch = '\0';
	cin >> ch;

	return 0;
}

/**
* @brief  qDebug()<< ��ʽ������Ϣ
*		  ����ֱ����<<����������Ҫ��������Ϣ������qDebug()��
* @return ��
*/
void example01(){
	
	

}

/**
* @brief  ʹ��qDebug("%")��ʽ��������Ϣ
* @return ��
*/
void example02(){
	
	
}


/**
* @brief  ���Զ�����������qDebug
* @param[in] mc �Զ�����
* @return 
*/
void example03(){
	
}
