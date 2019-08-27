/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。
\file: fileencodetype.h
\brief 文件编码类定义头文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/8
*/

#pragma once

#include <QString>
#include <QDebug>

class CFileEncodeType{

public:

    virtual QString getFileEncodeType(){ return QString(""); }
};

class CAsciiFile: public CFileEncodeType{

public:
    QString getFileEncodeType() override{

        return "ansi";
    }
};

class CUtf8File: public CFileEncodeType{
public:
    QString getFileEncodeType() override{

        return "utf-8";
    }
};

class CUnicodeFile: public CFileEncodeType{
public:
    QString getFileEncodeType() override{

        return "unicode";
    }
};

class CUnicodeEndFile: public CFileEncodeType{
public:
    QString getFileEncodeType() override{

        return "unicode big endian";
    }
};

class CFileTypeFactory{

public:

    static CFileEncodeType *createFileTypeFactory(QByteArray byteArray){

        CFileEncodeType *fileEncodeType;

        if(byteArray == "\xEF\xBB"){    // utf-8

            fileEncodeType = new CUtf8File;
        }
        else if(byteArray == "\xFF\xFE"){  // unicode

            fileEncodeType = new CUnicodeFile;
        }
        else if(byteArray == "\xFE\xFF"){  // unicode big endian

            fileEncodeType = new CUnicodeEndFile;
        }
        else{

            fileEncodeType = new CAsciiFile;
        }

        return fileEncodeType;
    }
};


