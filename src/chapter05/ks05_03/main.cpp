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
#include <QTranslator>	// ���ʻ�
#include "qglobal.h"
#include <QLibraryInfo> // ���ʻ�

#include <iostream>


#include "dialog.h"
#include "simpledialog.h"


using std::cout;
using std::endl;

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
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/ks05_03.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks05_03.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}

    // ����simpledialog
    CSimpleDialog* pSimpleDialog = new CSimpleDialog(NULL);
    pSimpleDialog->show();
    

	CDialog dlg(NULL);

    QObject::connect(&dlg, &CDialog::sig_addressUpdated,
        pSimpleDialog, &CSimpleDialog::slot_updateAddress);

	dlg.exec();
    delete pSimpleDialog;
	return 0;
}
