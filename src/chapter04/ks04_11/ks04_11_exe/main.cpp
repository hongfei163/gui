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
#include <QStringList>
#include <QDir>

#include <iostream>

#include "qglobal.h"
#include "ks04_11/myclass.h"


using std::cout;
using std::endl;

void example01(void);
void example02(void);

/////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

    if (0) {
        example01();
    }

    if (1) {
        example02();
    }
	return 0;
}


/**
* @brief example01, ����dll�еĽӿ�

* @return void
*/
void example01(void) {
    QString strPath = "d:\\temp_D";
    QStringList strFilters;
    strFilters << "*.gdf" << "*.xml";

    QStringList strList = ns_train::getFileList(strPath, strFilters, true);

}

/**
* @brief ʾ��1, �򵥽���QDir��ʹ��

* @return void
*/
void example02(void) {

    QString strPath = "$TRAINDEVHOME/src/";
    strPath = ns_train::getPath(strPath);
	strPath = ns_train::getDirectory(strPath);
    QDir dir(strPath);
    QString absPath = dir.absolutePath();	// ����·���ľ���·���ַ���
    QString cancPath = dir.canonicalPath(); // ����·���Ĺ淶·�����ַ���

	strPath = "../../../../test/chapter04/ks04_11/a.txt";
    strPath = ns_train::getPath(strPath);
	dir.setPath(strPath);
	//dir.mkdir(strPath);		// ���ϲ�·��������ʱ��mkdir()ʧ��
	absPath = dir.absolutePath();
	strPath = ns_train::getDirectory(absPath);
	dir.mkpath(strPath);	// ���ϲ�·��������ʱ��mkpath()�Զ��������еĸ�Ŀ¼���Ρ�
	cancPath = dir.canonicalPath(); // ��a.txt������ʱ��canonicalPath()���ؿա�

}
