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

#include <QCoreApplication>
#include <QDebug>
#include <QDomDocument>
#include <QFile>
#include "qglobal.h"
#include <QString>
#include <QTextStream>


#include "myclass.h"

void example01();
void example02();


int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	QCoreApplication app(argc, argv);
   

	if (1) {
		example01();
	}

	if (1) {
		example02();
	}
	
	system("pause");

	return 0;
}

/**
* @brief ����xml��ʽ�ļ�ʾ������
*        xml�ļ�����
*        <doc>
*           <courses institution="�����ع���"  teacher="Ů�����ϰ�" serie="C++��ƽ̨�����ɻ�ϵ��" count="7">
*               <lesson id="1" url="" fee="����" >C++�����ռ�<lesson/>
*               <lesson id="2" url="" fee="����" >C++��ƽ̨�����еı�������<lesson/>
*               <lesson id="3" url="" >Qt����������-GUI��Ʒ����<lesson/>
*               <lesson id="4" url=""  >C++��ƽ̨����ģ�鿪��<lesson/>
*           </courses>
*        </doc>
*/
void example01() {
	QString strPath = QCoreApplication::applicationDirPath();
	strPath = ns_train::getPath(strPath);
	if (!strPath.endsWith("/")) {
		strPath += "/";
	}

	QString strFileName = strPath + "test04_13.xml"; // ��������Ŀ¼�µ�xml�ļ�
	QFile file(strFileName);
	if (!file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate))	{ // QFile::Truncate,��Ҫ����ԭ��������
		return ;
	}

	QTextStream out(&file);
	out.setCodec("GB2312");

	QDomDocument document;
    QDomProcessingInstruction instruction;  //���Ӵ���ָ��
    instruction = document.createProcessingInstruction("xml",
        "version=\"1.0\" encoding=\"GB2312\""); // ��ע���˴��ı�������������Դ�����ļ��ı��뱣��һ�¡�

    document.appendChild(instruction);
	// doc
	QDomElement rootDoc = document.createElement("doc");
	document.appendChild(rootDoc);
	
	// ����������Ŀ����������example02()��
	QDomElement eleConfig = document.createElement("config");
	eleConfig.setAttribute("id", 5);
	rootDoc.appendChild(eleConfig);

	QString strName;
	QString strValue;
	// courses
	QDomElement eleCourses = document.createElement("courses");
	rootDoc.appendChild(eleCourses);

	strName = "institution";
	strValue = QString::fromLocal8Bit("�����ع���");
    eleCourses.setAttribute(strName, strValue);

	strName = "teacher";
	strValue = QString::fromLocal8Bit("Ů�����ϰ�");
    eleCourses.setAttribute(strName, strValue);

	strName = "count";
	strValue = QString("%1").arg(4);
    eleCourses.setAttribute(strName, strValue);

	// lesson
	QDomElement eleLesson = document.createElement("lesson"); 

	strName = "id";
	strValue = QString("%1").arg(1);
    eleLesson.setAttribute(strName, strValue);

	strName = "url";
	strValue = "https://study.163.com/instructor/1143174933.htm";
    eleLesson.setAttribute(strName, strValue);

    strName = "fee";
    strValue = QString::fromLocal8Bit("����");
    eleLesson.setAttribute(strName, strValue);

    QDomText dtText = document.createTextNode(QString::fromLocal8Bit("C++�����ռ�"));
    eleLesson.appendChild(dtText);
    eleCourses.appendChild(eleLesson);

    // lesson
    eleLesson = document.createElement("lesson"); 
    
    strName = "id";
    strValue = QString("%1").arg(2);
    eleLesson.setAttribute(strName, strValue);

    strName = "url";
    strValue = "https://study.163.com/instructor/1143174933.htm";
    eleLesson.setAttribute(strName, strValue);

    strName = "fee";
    strValue = QString::fromLocal8Bit("����");
    eleLesson.setAttribute(strName, strValue);

    dtText = document.createTextNode(QString::fromLocal8Bit("C++��ƽ̨�����еı�������"));
    eleLesson.appendChild(dtText);
    eleCourses.appendChild(eleLesson);  

    // lesson
    eleLesson = document.createElement("lesson");
    
    strName = "id";
    strValue = QString("%1").arg(3);
    eleLesson.setAttribute(strName, strValue);

    strName = "url";
    strValue = "https://study.163.com/instructor/1143174933.htm";
    eleLesson.setAttribute(strName, strValue);


    dtText = document.createTextNode(QString::fromLocal8Bit("Qt����������-GUI��Ʒ����"));
    eleLesson.appendChild(dtText);
    eleCourses.appendChild(eleLesson);


    // lesson
    eleLesson = document.createElement("lesson");

    strName = "id";
    strValue = QString("%1").arg(4);
    eleLesson.setAttribute(strName, strValue);

    strName = "url";
    strValue = "sorry, not ready";
    eleLesson.setAttribute(strName, strValue);
	 
    dtText = document.createTextNode(QString::fromLocal8Bit("C++��ƽ̨����ģ�鿪��"));
    eleLesson.appendChild(dtText);
    eleCourses.appendChild(eleLesson);
    
    document.save(out, 4, QDomNode::EncodingFromTextStream);    // 4:����ֵ
	
	// ����Ϣ�������ն�
	qDebug() << "XML to write";		
	qDebug() << document.toString(4);

	file.close();
}

/**
* @brief ��ȡxml��ʽ�ļ�ʾ������
*/
void example02() {

	QString strPath = QCoreApplication::applicationDirPath();
	strPath = ns_train::getPath(strPath);
	if (!strPath.endsWith("/")) {
		strPath += "/";
	}

	QString strFileName = strPath + "test04_13.xml"; // ��������Ŀ¼�µ�xml�ļ�
	QFile file(strFileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))	{
		return;
	}

	QDomDocument document;
	QString error;
	int row = 0, column = 0;

	if (!document.setContent(&file, false, &error, &row, &column))	{
		return;
	}
	QDomElement rootDoc = document.firstChildElement();

	if (rootDoc.nodeName() != "doc") {
		return;
	}
	QString strName;
	QString strValue;
	int nCount =0;
    Q_UNUSED(nCount);
	QDomCharacterData dtText;
	QDomElement eleCourses = rootDoc.firstChildElement();
	while (eleCourses.isElement()) {
		strName = eleCourses.tagName();
		if (strName != "courses") {
            eleCourses = eleCourses.nextSiblingElement();
			continue;
		}
		strName = "institution";
		strValue = eleCourses.attribute(strName);

		strName = "teacher";
		strValue = eleCourses.attribute(strName);

		strName = "serie";
		strValue = eleCourses.attribute(strName);


		strName = "count";
		strValue = eleCourses.attribute(strName);

		QDomElement eleLesson = eleCourses.firstChildElement();
		while (eleLesson.isElement()) {
			strName = eleLesson.tagName();
			if (strName == "lesson") {
				QDomNamedNodeMap attrs = eleLesson.attributes();
				int nC = attrs.count();
				for (int i = 0; i < nC; ++i) {
					QDomAttr  attrEle = attrs.item(i).toAttr();
					if (!attrEle.isNull()) {
						strName = attrEle.name();
						strValue = attrEle.value();
					}
				}
				if (!eleLesson.firstChild().isNull()) {
					dtText = eleLesson.firstChild().toCharacterData();
					if (!dtText.isNull()) {
						strValue = dtText.data();
					}
				}
			}			
            eleLesson = eleLesson.nextSiblingElement();
		}
        eleCourses = eleCourses.nextSiblingElement();
	}

	file.close();
}


