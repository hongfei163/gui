/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: mdichild.h
\brief  MdiChild ���Ķ����ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/9
*/


#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>

class MdiChild : public QTextEdit
{
    Q_OBJECT

public:
    MdiChild();

    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile();
    QString currentFile() { return curFile; }

Q_SIGNALS:
    void textSelected(const QString&); /// ѡ���ı���Ҫ���͵��ź�

protected:
    void closeEvent(QCloseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;

private slots:
    void documentWasModified();
private:
    bool maybeSave();
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
};

#endif
