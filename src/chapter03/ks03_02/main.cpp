/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: main.cpp
\brief main()������ʵ���ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/ 
\Date 2018/8
*/
#include <QApplication>
#include <QTranslator>		// ���ʻ�
#include <QLibraryInfo> 	// ���ʻ�

#include <iostream>
#include <QDebug>

#include "qglobal.h"
#include "dialog.h"

#include "base/commstr.h"

using std::cout;
using std::endl;

class CMyClass {
public:
	void sayHello();
};

void CMyClass::sayHello(){
	qDebug() << CCommonString::tr("i am not derived from QObject.");
}
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	QApplication app(argc, argv);
	// ��װqt�Դ������ķ���
	const QString localSysName = QLocale::system().name();  // ��ȡ����ϵͳ�����Ի���
	QScopedPointer<QTranslator> qtTranslator(new QTranslator(QCoreApplication::instance()));
	if (qtTranslator->load(QStringLiteral("qt_") + localSysName,
		QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		QCoreApplication::installTranslator(qtTranslator.take());
	}
	QString strPath = qgetenv("TRAINDEVHOME");  // ��ȡ����������ָ����·��
	strPath += "/system/lang";       // $TRAINDEVHOME/system/lang/ks03_01.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks03_02.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}
	CMyClass myclass;
	
	myclass.sayHello();

	CDialog dlg(NULL);
	dlg.exec();
	//cout << "������ɶҲû��." << endl;
	return 0;
}
