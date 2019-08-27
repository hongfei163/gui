/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。
\file: main.cpp
\brief main()函数的实现文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/8
*/

#include <QApplication>
#include <QInputDialog>
#include <QDebug>
#include <QFile>
#include "basedll/baseapi.h"
#include "fileencodetype.h"

void transformFile(const QString &sourceFile);
void saveFile(const QString &fileName,
              const QString& sourceCode,
              const QString& targetEncode,
              QByteArray& data);

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QString str = QInputDialog::getText(NULL,
                                QString::fromLocal8Bit("ASCII码批量转换为UTF-8"),
                                QString::fromLocal8Bit("请输入待转换的文件所在路径(支持环境变量,$MYPROGRAMPATH):"));
    QString strPath = ns_train::getPath(str);
    QStringList nameFilters;
    nameFilters << "*.cpp" << "*.h" << "*.pro" ;
    QStringList fileList = ns_train::getFileList(strPath, nameFilters, true);
    QStringList::iterator iteFile;
    for (iteFile=fileList.begin(); iteFile != fileList.end(); iteFile++) {
        transformFile(*iteFile);
    }
    return app.exec();
}
void transformFile(const QString &sourceFile)
{
    QFile file(sourceFile);
    if(!file.open(QIODevice::ReadOnly)){

        qDebug() << "open failed!";
        return;
    }

    QByteArray byteArray = file.readAll();
    file.close();

    CFileEncodeType *fileEncodeType =
                    CFileTypeFactory::createFileTypeFactory(byteArray.left(2));

    saveFile(sourceFile,
             fileEncodeType->getFileEncodeType(),
             "utf-8",
             byteArray);


    delete fileEncodeType;
    fileEncodeType = nullptr;
}
void saveFile(const QString &fileName,
              const QString& sourceCode,
              const QString& targetEncode,
              QByteArray& data)
{
    if(fileName.isEmpty())
        return;
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly)){

        qDebug() << "Open failed!" << endl;
        return;
    }

    if(targetEncode == "ascii"){

        if(sourceCode == "utf-8"){

            file.write(QString::fromUtf8(data).toStdString().c_str());
        }
        else{

            file.write(QString::fromLocal8Bit(data).toStdString().c_str());
        }
    }
    else{

        if(sourceCode == "utf-8"){

           //file.write("\xEF\xBB\xBF");
           // file.write(QString::fromUtf8(data).toStdString().c_str());
        }
        else{

            file.write("\xEF\xBB\xBF");
            file.write(QString::fromLocal8Bit(data).toStdString().c_str());
        }
    }
    file.close();
}
