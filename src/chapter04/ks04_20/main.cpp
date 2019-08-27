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
#include <QXmlStreamWriter>
#include <QDir>
#include <QFile>
#include "qglobal.h"
#include <QString>

#include "base/basedll/baseapi.h"

void example01();
void example02();

void parseDoc(QXmlStreamReader& reader);
void parseCourses(QXmlStreamReader& reader);
void parseLesson(QXmlStreamReader& reader);

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
*       --------------------------------------------------------------------
*       <?xml version="1.0" encoding="GB2312" standalone="yes"?>
*       <!--�����ع���-->
*       <doc>
*           <courses count="4" institution="�����ع���" teacher="Ů�����ϰ�">
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="1" fee="����">C++�����ռ�</lesson>
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="2" fee="����">C++��ƽ̨�����еı�������</lesson>
*               <lesson url="https://study.163.com/instructor/1143174933.htm" id="3">Qt����������-GUI��Ʒ����</lesson>
*               <lesson url="sorry, not ready" id="4">C++��ƽ̨����ģ�鿪��</lesson>
*           </courses>
*       </doc>
*
*/
void example01() {
    QString strPath = 
        ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_20");
    if (!strPath.endsWith("/")) {
        strPath += "/";
    }
    QDir dir(strPath);
    dir.mkpath(strPath);
    QString strFileName = strPath + "test04_20.xml";
    QFile file(strFileName);
    if (!file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)) {// QFile::Truncate��Ϊ������ԭ�����ļ�����
        return;
    }
    QXmlStreamWriter writer(&file);    
    writer.setCodec("UTF-8");// ����XML����
    writer.setAutoFormatting(true); // �Զ���ʽ��
    writer.writeStartDocument("1.0", true); // ��ʼ�ĵ���xml����
    writer.writeComment(QString::fromLocal8Bit("�����ع���"));

    writer.writeStartElement("doc");    // ��ʼ��Ԫ��<doc>
    // ���濪ʼд����
    writer.writeStartElement("courses"); // ��ʼ��Ԫ��<courses>
    {
        writer.writeAttribute("count", "4");
        writer.writeAttribute("institution", QString::fromLocal8Bit("�����ع���"));
        writer.writeAttribute("teacher", QString::fromLocal8Bit("Ů�����ϰ�"));

        // lesson1
        {
            writer.writeStartElement("lesson");
            {
                writer.writeAttribute("url", "https://study.163.com/instructor/1143174933.htm");
                writer.writeAttribute("id", "1");
                writer.writeAttribute("fee", QString::fromLocal8Bit("����"));
                writer.writeCharacters(QString::fromLocal8Bit("C++�����ռ�"));
           }
            writer.writeEndElement();   // ������Ԫ�� </lesson>
        }
        // lesson2
        {
            writer.writeStartElement("lesson");
            {
                writer.writeAttribute("url", "https://study.163.com/instructor/1143174933.htm");
                writer.writeAttribute("id", "2");
                writer.writeAttribute("fee", QString::fromLocal8Bit("����"));
                writer.writeCharacters(QString::fromLocal8Bit("C++��ƽ̨�����еı�������"));
            }
            writer.writeEndElement();   // ������Ԫ�� </lesson>
        }
        // lesson3
        {
            writer.writeStartElement("lesson");
            {
                writer.writeAttribute("url", "https://study.163.com/instructor/1143174933.htm");
                writer.writeAttribute("id", "3");
                writer.writeCharacters(QString::fromLocal8Bit("Qt����������-GUI��Ʒ����"));
            }
            writer.writeEndElement();   // ������Ԫ�� </lesson>
        }
        // lesson4
        {
            writer.writeStartElement("lesson");
            {
                writer.writeAttribute("url", "sorry, not ready");
                writer.writeAttribute("id", "4");
                writer.writeCharacters(QString::fromLocal8Bit("C++��ƽ̨����ģ�鿪��"));
            }
            writer.writeEndElement();   // ������Ԫ�� </lesson>
        }
    }
    writer.writeEndElement();   // ������Ԫ�� </courses>

    writer.writeEndElement();   // ������Ԫ�� </doc>
    writer.writeEndDocument();  // �����ĵ�

    file.close();
}

/**
* @brief ��ȡxml��ʽ�ļ�ʾ������
*/
void example02() {
    QString strPath =
        ns_train::getPath("$TRAINDEVHOME/test/chapter04/ks04_20");
    if (!strPath.endsWith("/")) {
        strPath += "/";
    }
    QString strFileName = strPath + "test04_20.xml";
    QFile file(strFileName);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return;
    }

    QXmlStreamReader reader(&file);
    QString strVersion;
    QString strEncoding;
    QXmlStreamReader::TokenType nType = reader.readNext();
    while (!reader.atEnd()) {// ���������ļ�
        // ��ȡ��һ��Ԫ��
        nType = reader.tokenType();
        switch (nType) {
        case QXmlStreamReader::StartDocument: { // �ĵ���ʼ
            qDebug() << QString::fromLocal8Bit("============== ��ʼ�ĵ�(XML����) ===============");
            // XML����
            strVersion = reader.documentVersion().toString();
            strEncoding = reader.documentEncoding().toString();
            bool bStandalone = reader.isStandaloneDocument();
            qDebug() << QString::fromLocal8Bit("XML�汾:%1  XML����:%2 Standalone=%3")
                .arg(strVersion).arg(strEncoding).arg(bStandalone);
            break;
        }
        case QXmlStreamReader::Comment: {// ע��
            qDebug() << QString::fromLocal8Bit("========== XML ע�� ===========");
            QString strComment = reader.text().toString();
            qDebug()<< strComment << "\r\n";
            break;
        }
        case QXmlStreamReader::ProcessingInstruction: {  // ����ָ��
            qDebug() << QString::fromLocal8Bit("============= ����ָ�� ============= ");
            QString strProcInstr = reader.processingInstructionData().toString();
            qDebug() << strProcInstr << "\r\n";
            break;
        }
        case QXmlStreamReader::DTD: {   // DTD
            qDebug() << QString::fromLocal8Bit("============= DTD ============= ");
            QString strDTD = reader.text().toString();
            QXmlStreamNotationDeclarations notationDeclarations = reader.notationDeclarations();  // ��������
            QXmlStreamEntityDeclarations entityDeclarations = reader.entityDeclarations();  // ʵ������
                                                                                            // DTD ����
            QString strDTDName = reader.dtdName().toString();
            QString strDTDPublicId = reader.dtdPublicId().toString();  // DTD ������ʶ��
            QString strDTDSystemId = reader.dtdSystemId().toString();  // DTD ϵͳ��ʶ��
            qDebug() << QString::fromLocal8Bit("DTD : %1").arg(strDTD);
            qDebug() << QString::fromLocal8Bit("DTD ���� : %1").arg(strDTDName);
            qDebug() << QString::fromLocal8Bit("DTD ������ʶ�� : %1").arg(strDTDPublicId);
            qDebug() << QString::fromLocal8Bit("DTD ϵͳ��ʶ�� : %1").arg(strDTDSystemId);
            qDebug() << "\r\n";

            break;
        }
        case QXmlStreamReader::StartElement: { // ��ʼԪ��
            QString strElementName = reader.name().toString();
            if (QString::compare(strElementName, "doc") == 0) { // ��Ԫ��doc
                qDebug() << QString::fromLocal8Bit("============== ��ʼԪ��<doc> ==============");
                // ����docԪ�ؼ�����Ԫ��
                parseDoc(reader);
            }
            break;
        }
        case QXmlStreamReader::EndElement: { // ����Ԫ�� 
            QString strElementName = reader.name().toString();
            if (QString::compare(strElementName, "doc") == 0) { // ��Ԫ��doc
                qDebug() << QString::fromLocal8Bit("============= ����Ԫ��</doc> ===============");
            }
            break;
        }
        case QXmlStreamReader::EndDocument: { // �ĵ�����
            qDebug() << QString::fromLocal8Bit("============== �ĵ����� ================");
            break;
        }
        default:
            break;
        }
        reader.readNext();
    }
    if (reader.hasError()) {
        // ��������,����������־��ִ����������
    }
    file.close();
}

void parseDoc(QXmlStreamReader& reader) {

    QXmlStreamReader::TokenType nType = reader.readNext();
    while (!reader.atEnd()) {
        nType = reader.tokenType();
        switch (nType) {
        case QXmlStreamReader::StartElement: { // ��ʼԪ��
            QString strElementName = reader.name().toString();
            if (QString::compare(strElementName, "courses") == 0) {
                qDebug() << QString::fromLocal8Bit("============== ��ʼԪ��<courses> ==============");
                // ����courses
                parseCourses(reader);
            }
            break;
        }
        case QXmlStreamReader::EndElement: { // ����Ԫ�� 
            QString strElementName = reader.name().toString();
            qDebug() << QString::fromLocal8Bit("============= ����Ԫ��<%1> =============").arg(strElementName);
            return;
        }
        default:
            break;
        }
        nType = reader.readNext();
    }
}

void    parseCourses(QXmlStreamReader& reader) {
    QXmlStreamReader::TokenType nType = reader.readNext(); // ��readerָ��lesson��Ԫ��.
    while (!reader.atEnd()) {
        nType = reader.tokenType();
        switch (nType) {
        case QXmlStreamReader::StartElement: { // ��ʼԪ�� 
            QString strElementName = reader.name().toString();
            if (QString::compare(strElementName, "lesson") == 0) { // lessonԪ��
                qDebug() << QString::fromLocal8Bit("============= ��ʼԪ��<lesson> =============");
                // ����lesson
                parseLesson(reader);
                continue;
            }
            break;
        }
        case QXmlStreamReader::EndElement: { // ����Ԫ�� 
            QString strElementName = reader.name().toString();
            qDebug() << QString::fromLocal8Bit("============= ����Ԫ��<%1> =============").arg(strElementName);
            if (QString::compare(strElementName, "courses") == 0) { // ����Ԫ��
                return;
            }
            break;
        }
        default:
            break;
        }  
        nType = reader.readNext();
    }
}

void parseLesson(QXmlStreamReader& reader) {
    QXmlStreamReader::TokenType nType;
    QString strElementName;
    QXmlStreamAttributes attributes; 
    QXmlStreamAttributes::iterator iteAttribute;
    QString strText;
    while (!reader.atEnd()) {
        nType = reader.tokenType();
        switch (nType)
        {
        case QXmlStreamReader::StartElement:
            strElementName = reader.name().toString();
            attributes = reader.attributes();
            for (iteAttribute= attributes.begin(); iteAttribute!= attributes.end(); iteAttribute++) {
                qDebug() << (*iteAttribute).name() << "=" << (*iteAttribute).value();
            }
            break;
        case QXmlStreamReader::EndElement:
            strElementName = reader.name().toString();    
            if (strElementName != "lesson") {
                return;
            }
            qDebug() << QString::fromLocal8Bit("============= ����Ԫ��:%1 =============").arg(strElementName); 
            break;
        case QXmlStreamReader::Characters:
            strText = reader.text().toString();
            qDebug() << QString("Characters:%1").arg(strText);
            break;
        default:
            break;
        }  
        nType = reader.readNext();
    }
}