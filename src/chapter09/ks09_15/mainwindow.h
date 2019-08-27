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
class QGraphicsScene;
class QPropertyAnimation;
QT_END_NAMESPACE


class CGraphView;

class CMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* parent);
	~CMainWindow(){;}

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

    void slot_fileMenu();
    void slot_openFile();
    void slot_saveFile();
    void slot_closeFile();
    void slot_exit();
    void slot_animationMenuFinished();
private:
	void createActions();		/// �����˵�����Ӧ��QAction��
	void createMenus();			/// �����˵�
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
	QAction *m_pFileMenuAct;	/// �ļ��˵�
	QAction *m_pOpenFileAct;	/// �����ļ�
    QAction *m_pSaveFileAct;	/// �����ļ�
    QAction *m_pCloseFileAct;	/// �ر��ļ�
    QAction *m_pExitAct;	    /// �˳�

#ifndef QT_NO_CLIPBOARD
	QAction *m_pCutAct;			/// ����
	QAction *m_pCopyAct;		/// ����
	QAction *m_pPasteAct;		/// ����
#endif
    QAction *m_pRectAct;        /// ���Ӿ���
    QAction *m_pEllipseAct;     /// ������Բ

	QAction *m_pAboutAct;	    /// ����

	QLabel *m_pInfoLabel;	    /// ��Ϣ��ǩ
	QLabel* m_pMouseLabel;	    /// ����λ����ʾ

	CGraphView* m_pView;        /// ��ͼ
    QGraphicsScene* m_pScene;   /// ����(�ĵ�)

    QPropertyAnimation* m_pAnimaMenuShow; /// �˵�����
    bool     m_bShowMenu;       /// ��ʾ�˵�
};

#endif // MAINWINDOW_H