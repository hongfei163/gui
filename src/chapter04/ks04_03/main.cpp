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
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include <iostream>

bool example01(const QString& strInput, QString& strDir, QString& strFileName);
QString example02(int level, const QString& strPerson, const QString& strComputer, const QString& strInfo);
QString example03(const QRectF& rect);
QString example04(const QString& strTemplateName, int nTerminalCount);
void example05();
void example06();


using std::cout;
using std::cin;
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
	strPath += "/system/lang";					// $TRAINDEVHOME/system/lang/ks03_01.qm
	QScopedPointer<QTranslator> gpTranslator(new QTranslator(QCoreApplication::instance()));
	if (gpTranslator->load("ks04_03.qm", strPath))
	{
		QCoreApplication::installTranslator(gpTranslator.take());
	}

	// example01, ������Ŀ¼�л�ȡĿ¼�����ļ���
	if (false) {
		QString strInput = "d:\\project\\gui\\src\\chapter01\\ks01_01\\ks01_01.pro";
		bool bok;
		QString strDir;
		QString strFileName;
		bok = example01(strInput, strDir, strFileName);
	}

	// example02, ��֯��־��Ϣ
	if (false) {
		QString strWholeInfo = example02(3, "Lisa", "adm01", "modified data at 12:00PM.");
	}

	// example03, ʹ��arg()�ӿڶ���Ϣ��ʽ��, �������ε����ꡢ����
	if (false) {
		QRectF rct(20.f, 30.f, 50.f, 60.f);
		example03(rct);
	}

	// example04, ʹ��arg()�ӿڶ���Ϣ��ʽ��, ������
	if (false) {
		example04(QString::fromLocal8Bit("���϶�·��"), 2);
	}


	// example05, �������ض��ָ������ɵ��ַ���
	if (false) {
		example05();
	}

	// example06, �ַ�������ֵ���໥ת��
	if (true) {
		example06();
	}


	char ch = '\0';
	cin >> ch;

	return 0;
}

/**
* @brief  ������Ŀ¼�л�ȡĿ¼�����ļ���
* @param[in] strInput  �ļ�ȫ·��
* @param[out] strDir	�ļ�����Ŀ¼
* @param[out] strFileName  �ļ���(����Ŀ¼)
* @return true:�ɹ�, false:ʧ��
*/
bool example01(const QString& strInput, QString& strDir, QString& strFileName){
	
	if (0 == strInput.length())
		return false;

	QString str = strInput;		// str = "d:\\project\\gui\\src\\chapter01\\ks01_01\\ks01_01.pro";

	// ���Ƚ��ָ���ͳһ������ͳһ����windows��linux��Ŀ¼
	str.replace("\\", "/");		// str=d:/project/gui/src/chapter01/ks01_01/ks01_01.pro
	
	int idx = str.lastIndexOf("/");
	strDir = str.left(idx);		// strDir=d:/project/gui/src/chapter01/ks01_01


	strFileName = str.right(str.length()-(idx+1));	// ��idx+1��Ŀ���Ǻ����ļ���ǰ����"/"
								// strFileName = ks01_01.pro

	return true;
}

/**
* @brief  ��֯��־��Ϣ
* @param[in] level  ��־�ȼ�
* @param[in] strPerson	��Ա��Ϣ
* @param[in] strComputer  ������Ϣ
* @param[in] strInfo  ��־����
* @return ƴ�Ӻ�����־
*/
QString example02(int level, const QString& strPerson, const QString& strComputer, const QString& strInfo){
	QString str;
	str.sprintf("---- level=%02d, Person:", level);	// str = "---- level=01, Person:"
	str += strPerson;								// str = "---- level=01, Person:Lisa"
	str += ", Computer:";							// str = "---- level=01, Person:Lisa, Computer:"
	str += strComputer;								// str = "---- level=01, Person:Lisa, Computer:adm01"
	str += ", info=";								// str = "---- level=01, Person:Lisa, Computer:adm01, info="
	str += strInfo;									// str = "---- level=01, Person:Lisa, Computer:adm01, info=xxxxxx";
	return str;
}


/**
* @brief  ʹ��arg()�ӿڶ���Ϣ��ʽ��,�������ε����ꡢ����
* @param[in] rect  ����
* @return ���ε����ꡢ����
*/
QString example03(const QRectF& rect){
	QString strRect = QString("%1,%2,%3,%4").arg(rect.x()).arg(rect.y()).arg(rect.width()).arg(rect.height());
	return strRect;
}
/**
* @brief  ʹ��arg()�ӿڶ���Ϣ��ʽ��,������
* @param[in] strTemplateName  ģ������
* @param[in] nTerminalCount  ���Ӹ���
* @return ��ʽ��������Ϣ
*/
QString example04(const QString& strTemplateName, int nTerminalCount){
	QString strInfo = QObject::tr("template name:%1 already has terminal count=%2.").arg(strTemplateName).arg(nTerminalCount);
	cout << strInfo.toLocal8Bit().data() << endl;
	return strInfo;
}

/**
* @brief  �������ض��ָ������ɵ��ַ���
* @return ��ʽ��������Ϣ
*/
void example05(){
	QString str = QString::fromLocal8Bit("�����ع���, Ů�����ϰ�, C++|Qt");
	
	// ɾ�������Ŀո�
	str = str.trimmed();	

	QStringList strList = str.split(",");	// strList[0] : "�����ع���"
											// strList[1] : "Ů�����ϰ�"
											// strList[2] : "C++|Qt"

	cout << "����:" << strList[0].toLocal8Bit().data() << endl;
	cout << "����:" << strList[1].toLocal8Bit().data() << endl;

	// ��"|"����","
	QString strCategory = strList[2];		// strCategory : "C++|Qt"
	strCategory.replace("|", ",");			// strCategory : "C++,Qt"
	cout << "����:" << strCategory.toLocal8Bit().data() << endl;
}

/**
* @brief  �ַ��������ֻ���ת��
* @return ��
*/
void example06(){

	QString str1 = "2147483648"; // int32����ֵ��2147483647
	int nInt32 = str1.toInt();
	uint uInt32 = str1.toUInt();
	cout << "int32 data = " << nInt32 << endl;
	cout << "uInt32 data = " << uInt32 << endl;

	QString str2;
	nInt32 = 2147483647;
	str1.sprintf("%d", nInt32);
	cout << "new int32 data = " << str1.toLocal8Bit().data() << endl;

	str2.sprintf("%d", uInt32);
	cout << "new uint32 data = " << str2.toLocal8Bit().data() << endl;

	str2.sprintf("%u", uInt32);
	cout << "new uint32 data = " << str2.toLocal8Bit().data() << endl;

	str1 = QString("%1").arg(nInt32);
	cout << "another new int32 data = " << str1.toLocal8Bit().data() << endl;

	QString str3 = "200.f";
	float f = str3.toFloat();
	cout << "float data = " << f << endl;

	str3 = "200";
	f = str3.toFloat();
	cout << "float data = " << f << endl;

	QString str4 = "3.1415926535897932";
	qreal d = str4.toDouble();
	QString strData;
	strData = QString::number(d);
	cout << "double data = " << strData.toLocal8Bit().data() << endl;
	strData = QString::number(d, 'g', 16); // ��Ҫ��ȷָ�����ȣ�����Ĭ��ֻ��6λС����
	cout << "double data = " << strData.toLocal8Bit().data() << endl;

}

