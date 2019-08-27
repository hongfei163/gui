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

#include <QDebug>
#include <QDir>
#include <QFile>
//#include "qglobal.h"

#include <iostream>

#include "ks04_11/myclass.h"

using std::cin;
using std::endl;
void pauseOnce();
void initialize(void);
void example01(void);
void example02(void);
void example03(void);
void example04(void);

// ��ͣһ��
void pauseOnce()
{
	char c = '\0';
	cin >> c;
   // system("pause");
}

int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

    // �ı��ļ���ʼ��
    initialize();


    // �ı��ļ���ȡ
    if (1) {
        example01();
    }

    // �ı��ļ�,׷��д��
    if (0) {
        example02();
    }

    // �ı��ļ�,�ڿ�ͷд��
    if (0) {
        example03();
    }

    // �ļ��������������ƶ���ɾ��
    if (1) {
        example04();
    }
    
    pauseOnce();

	return 0;
}


/**
* @brief �ı��ļ���ʼ��
*
* @return void
*/
void initialize(void)
{
    QString strFileName;
    strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/example01.txt");
	QString strDir = ns_train::getDirectory(strFileName);
	QDir dir;
	dir.mkpath(strDir);

    QFile file(strFileName);
    // �򿪷�ʽ��ֻ�����ı���ʽ
    if (!file.open(QFile::Truncate | QFile::WriteOnly | QFile::Text)) {
        qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        return;
    }
    // ���������ļ�������
    QString strContent;
    strContent += "i have an apple, here you are.\n";
    strContent += "i have a pear, here you are.\n";
    strContent += "i have an orange, here you are.\n";
	if (1) {
		file.write(strContent.toLocal8Bit());
	} 
	else {
		QTextStream out(&file);
		out << strContent;
	}

    qDebug("File created, this is the content:\n");
	qDebug() << strContent;
	
    file.close();
}

/**
* @brief �ı��ļ���ȡ
*
* @return void
*/
void example01()
{
    QString strFileName;
    strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/example01.txt");

    QFile file(strFileName);
    // �򿪷�ʽ��ֻ�����ı���ʽ
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        return;
    }
    // ���������ļ�������
    QString strContent = file.readAll();
    qDebug("=====================================\n");
    qDebug("File Opened, this is the content:\n");
    qDebug() << strContent;
    
    
    // ���ļ��α��Ƶ��ļ���ͷ�������Ļ��������α��Ѿ��ƶ����ļ�β����ִ�к����Ĵ��뽫�޷���ȡ�����ݡ�
    file.seek(0);

    // ���д�ӡ
    qDebug("\n\n=====================================\n");
    qDebug("All the lines:\n");
    if (true) {
		const int c_maxNumber = 10240;
		char buf[c_maxNumber];
		qint64 nRead = 0;
		qDebug("File Opened, this is the lines:");
		while (!file.atEnd()) {
			nRead = file.readLine(buf, c_maxNumber);
			strContent = buf;
			strContent.remove("\r");
			strContent.remove("\n");
			qDebug("%s", strContent.toLocal8Bit().data());
		}
	}
	else {
		QTextStream in(&file);
		while (!in.atEnd()) {
			QString line = in.readLine();
			qDebug("%s", line.toLocal8Bit().data());
		}
	}
    file.close(); // ǧ����Ҫ���ǹر��ļ�Ŷ

}

/**
* @brief �ı��ļ���׷��д��
*
* @return void
*/
void example02()
{
    QString strFileName;
    strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/example01.txt");

    QFile file(strFileName);
    // �򿪷�ʽ��ֻ�����ı���ʽ
    //if (!file.open(QFile::ReadWrite | QFile::Text)) {
    if (!file.open(QFile::ReadWrite | QFile::Append | QFile::Text)) {
        qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        return;
    }
	qDebug("\n\n=====================================\n");
	qDebug("File Opened, this is the content:\n");
	file.seek(0);// ʹ��QFile::Append�����ļ������α�Ĭ�����ļ�β��
	QString strContent = file.readAll();// readAll()�����ļ����α굽���ļ�β��
    qDebug() << strContent;

    QString strNew = "i got another apple.";
    file.write(strNew.toLocal8Bit());

     // ���������ļ�������
	qDebug("\n\n=====================================\n");
	qDebug("File appended, this is the content:\n");
 	file.seek(0);
    strContent = file.readAll();// readAll()�����ļ����α굽���ļ�β��
    qDebug() << strContent;

    file.close();

}


/**
* @brief �ı��ļ����ڿ�ͷд��
*
* @return void
*/
void example03()
{
    QString strFileName;
    strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/example01.txt");

    QFile file(strFileName);
    // �򿪷�ʽ��ֻ�����ı���ʽ
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug("open failed! file name is:%s", strFileName.toLocal8Bit().data());
        return;
    }
    // ���������ļ�������
	qDebug("\n\n=====================================\n");
	qDebug("File Opened, this is the content:\n");
    QString strContent = file.readAll();
    qDebug() << strContent;

	qDebug("\n\n=====================================\n");
    QString strNew = "add new line at the first line\n";
    strContent = strNew + strContent;
    
    file.resize(0); // ���ļ���������

    file.write(strContent.toLocal8Bit());

    file.seek(0);   // ���ļ��α��Ƶ��ļ���ͷ�������Ļ��������α��Ѿ��ƶ����ļ�β����ִ�к����Ĵ��뽫�޷���ȡ�����ݡ�
	strContent = file.readAll();
    qDebug() << strContent;

    file.close();

}


/**
* @brief �ļ��������������ƶ���ɾ��
*
* @return void
*/
void example04()
{
    QString strFileName;
    strFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/example01.txt");

    QFile file;
    file.setFileName(strFileName);
    if (!file.exists()) {
        return;
    }
    QDir dir;
    QString strDirectory;
    // ����
    QString strNewFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/copy.txt");
    strDirectory  = ns_train::getDirectory(strNewFileName);
    dir.mkpath(strDirectory); // ��ע��makepath()��makedir()������
    file.copy(strNewFileName);
    pauseOnce();

    // ����
    strNewFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/new.txt");
    strDirectory = ns_train::getDirectory(strNewFileName);
    dir.mkpath(strDirectory);
    file.rename(strNewFileName);
    pauseOnce();

    // �ƶ�
    strNewFileName = ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_12/move/dir/new.txt");
    strDirectory = ns_train::getDirectory(strNewFileName);
    dir.mkpath(strDirectory);
    file.rename(strNewFileName);
    pauseOnce();

    // ɾ��
    file.remove();

    file.close();

}
