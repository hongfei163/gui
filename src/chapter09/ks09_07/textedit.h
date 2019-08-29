/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: textedit.h
\brief 演示用头文件
  
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>


class CTextEdit : public QTextEdit
{
	Q_OBJECT
public:
	CTextEdit(QWidget* parent);
	~CTextEdit(){;}

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *e) override;

Q_SIGNALS:
	void viewMouseMove(QMouseEvent *event);

private:
};

#endif // TEXTEDIT_H