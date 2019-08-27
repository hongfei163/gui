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
#include <QList>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QMenu;
class QActionGroup;
class QAction;
class QLabel;
class QToolbar;
class QGraphicsScene;
QT_END_NAMESPACE


class CGraphView;
class CActionObjectInterface;
class CMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* parent);
	~CMainWindow(){;}

protected:

private slots:
#ifndef QT_NO_CLIPBOARD
	void slot_cut();
	void slot_copy();
	void slot_paste();
#endif
    void onMouseMoveInView(const QPointF&);
    
    void about();

	void slot_addRect();
	void slot_addEllipse();

private:
	void createActions();		/// �����˵�����Ӧ��QAction��
	void createPluginActions();	/// ��������Action��
	//void createMenus();			/// �����˵�
	void createToolBars();		/// ����������
	void createStatusBar();		/// ����״̬��
	void initialize();			/// ��ʼ��
	
	void connectSignalAndSlot();/// �����źŲ�
	
private:
	QMenu *m_pFileMenu;			/// �ļ��˵�
	QMenu *m_pEditMenu;			/// �༭�˵�
	QMenu *m_pFormatMenu;		/// ��ʽ�˵�(�����˵�)
	QMenu *m_pHelpMenu;			/// �����˵�
	
	QToolBar *m_pEditToolBar;	/// �༭������

	QActionGroup *m_pAlignmentGroup;

#ifndef QT_NO_CLIPBOARD
	QAction *m_pCutAct;			/// ����
	QAction *m_pCopyAct;		/// ����
	QAction *m_pPasteAct;		/// ����
#endif
    QAction *m_pRectAct;        /// ���Ӿ���
    QAction *m_pEllipseAct;     /// ������Բ

	QAction *m_pAboutAct;	/// ����

	QLabel *m_pInfoLabel;	/// ��Ϣ��ǩ
	QLabel* m_pMouseLabel;	/// ����λ����ʾ

	CGraphView* m_pView;        /// ��ͼ
    QGraphicsScene* m_pScene;   /// ����(�ĵ�)
    QList<CActionObjectInterface*> m_lstActionObject;
};

#endif // MAINWINDOW_H