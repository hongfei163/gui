/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: listwidget.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef CLISTWIDGET_H
#define CLISTWIDGET_H

#include <QListWidget>


class CListWidget : public QListWidget
{
//	Q_OBJECT
public:
	/**
	* @brief ���캯��
	* @param[in] parent ��־�������ĸ�����
	*/
	CListWidget(QWidget* parent);
	~CListWidget();

public:
	

protected:
	/**
	* @brief ��ק�����¼���Ӧ
	* @param[in] event ��ק�¼�
	*/
	void dragEnterEvent(QDragEnterEvent* event);

	/**
	* @brief ��ק�ƶ��¼���Ӧ
	* @param[in] event ��ק�¼�
	*/
	void dragMoveEvent(QDragMoveEvent* event);

	/**
	* @brief ��ק�뿪�¼���Ӧ
	* @param[in] event ��ק�¼�
	*/
	void dragLeaveEvent(QDragLeaveEvent *event);

	/**
	* @brief ��ק�����¼���Ӧ
	* @param[in] event ��ק�¼�
	*/
	void dropEvent(QDropEvent *event);

private:
	QString m_strFileName;
};

#endif // TEXTEDIT_H