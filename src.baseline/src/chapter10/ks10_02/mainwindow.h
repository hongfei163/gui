/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: mainwindow.h
\brief ������ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/12 
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QToolBar>
#include <QLabel>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QMenu;
class QActionGroup;
class QAction;
class QLabel;
class QToolbar;
QT_END_NAMESPACE

class CEditMdiArea;

class CGraphView;

class CMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* parent);
	~CMainWindow(){;}

protected:

private slots:

    void onMouseMoveInView(const QPointF&);    
    void about();


private:
	void createActions();		/// �����˵�����Ӧ��QAction��
	void createMenus();		    /// �����˵�
	void createStatusBar();		/// ����״̬��
	void initialize();			/// ��ʼ��	
	void connectSignalAndSlot();/// �����źŲ�
	
private:
	QMenu *m_pHelpMenu;			/// �����˵�
	
	QAction *m_pAboutAct;	/// ����

	QLabel *m_pInfoLabel;	/// ��Ϣ��ǩ
	QLabel* m_pMouseLabel;	/// ����λ����ʾ

    CEditMdiArea* 	m_pMdiArea;
};

#endif // MAINWINDOW_H