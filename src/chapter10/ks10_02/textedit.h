/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: textedit.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
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

public:
	/**
	* @brief ����ָ���ļ���
	* @param[in] strFileName ȫ·���ļ�����֧�ֻ�������
	* @return true:�ɹ���false:ʧ��
	*/
	bool openFile(const QString& strFileName);
	/**
	* @brief ��ȡ��ǰ�򿪵��ļ������֡�
	* @reutrn ��ǰ�򿪵��ļ������֣�ȫ·����
	*/
	QString currentFileName() { return m_strFileName; }

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void mouseMoveEvent(QMouseEvent *e) override;
	virtual void mouseReleaseEvent(QMouseEvent *e) override;

Q_SIGNALS:
	void viewMouseMove(QMouseEvent *event);

private:
	QString m_strFileName;
	bool	m_bDrag;
	QPoint  m_ptMousePress;
};

#endif // TEXTEDIT_H