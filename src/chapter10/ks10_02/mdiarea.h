/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: mdiarea.h
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/

#ifndef MDIAREA_H
#define MDIAREA_H

#include <QMdiArea>

QT_BEGIN_NAMESPACE
class QMdiSubWindow;
class QMainWindow;
class QGraphicsScene;
class QAction;
class QToolBar;

QT_END_NAMESPACE

class CGraphView;
class CTextEdit;

class CEditMdiArea : public QMdiArea
{
    Q_OBJECT

public:
/**
	* @brief			���캯��
	* @param[in] pMainWindow	������
	*/
    CEditMdiArea(QMainWindow* pMainWindow);
	/// ��������
    virtual ~CEditMdiArea();

public:
	/**
	* @brief ��ȡ������
	* @return ������
	*/
    QMainWindow* getMainWindow();
	/**
	* @brief ��ȡ��ǰ���ͼ
	* @return ��ǰ���ͼ
	*/
    QWidget *activeMdiChild();
    /**
    * @brief ��ȡ��ǰ��༭��ͼ
    * @param[in] pMdiChild subwindow����
    * @return ��ǰ��༭��ͼ
    */
    QWidget* getActiveEditView(QMdiSubWindow* pMdiChild);

	/**
	* @brief �����ļ�������ͼ
	* @param[in] fileName �ļ���
	* @param[in] pError ������
	* @return ��ͼ����������������ģ�����Ͳ���ȷ�򷵻�NULL
	*/
	CGraphView* createGraphViewMdiChild(const QString& fileName, QString* pError = NULL);
	/**
	* @brief �����ļ������ı��༭��ͼ
	* @param[in] fileName �ļ���
	* @param[in] pError ������
	* @return ��ͼ����������������ģ�����Ͳ���ȷ�򷵻�NULL
	*/
    CTextEdit* createTexteditMdiChild(const QString& fileName, QString* pError = NULL);
    /**
    * @brief ��������Ϊfilename���Ӵ��ڶ���(��ͼ����Ϊ��CGraphView)
    * @param[in] fileName �ļ���
    * return �Ӵ��ڶ���
    */
    QMdiSubWindow *findGraphViewMdiChild(const QString &fileName);
    /**
    * @brief ��������Ϊfilename���Ӵ��ڶ���(��ͼ����Ϊ��CTextEdit)
    * @param[in] fileName �ļ���
    * return �Ӵ��ڶ���
    */
    QMdiSubWindow *findTexteditMdiChild(const QString &fileName);
    
    /**
    * @brief �����˵�����Ӧ��QAction
    * return void
    */
    void createActions();		
    
    /**
    * @brief ����������
    * return void
    */
   void createToolBars();		
	/**
	* @brief ����ָ���ļ�
	* @param[in] fileName �ļ�����·����
	* @param[in] pError ������
	* @retval true �����ļ��ɹ�
	* @retval true �����ļ�ʧ��
	*/
	bool openFileByGraphview(const QString &fileName, QString* pError = NULL);
	/**
	* @brief ����ָ���ļ�(���ı��༭��չʾ)
	* @param[in] fileName �ļ�����·����
	* @param[in] pError ������
	* @retval true �����ļ��ɹ�
	* @retval true �����ļ�ʧ��
	*/
	bool openFileByTextview(const QString &fileName, QString* pError = NULL);
   
private slots:
    void slot_new();
    void slot_open();

    void slot_addRect();
    void slot_addEllipse(); 

#ifndef QT_NO_CLIPBOARD
	/// ����
    void slot_cut();
	/// ����
    void slot_copy();
 	/// ����
   void slot_paste();
#endif
    /**
	*	@brief				��ͼ�رյĲۺ���
	*	@param[in] pView	��ͼָ��
    *   @return             void
	*/
	virtual void onViewClose(QWidget*);
    /**
	*	@brief				����ͼ���ļ�
	*	@param[in] strFileName	ͼ���ļ�����
    *   @return             void
	*/
	void slot_openTextGraphFile(const QString& strFileName);

    /**
    * @brief ���ڼ�����Ϣ����
    * @param[in] pMdiChild ����ָ��
    */
    virtual void onSubWindowActivate(QMdiSubWindow *pMdiChild);

Q_SIGNALS:
    void viewMouseMove(const QPointF&);
    void editViewChanged(QWidget*);
    void editViewClose(QWidget*);
private:
    /**
    * @brief ���༭��ͼ�ҽӵ��ര�������Ĳۺ���
    * @param[in] pView �༭��ͼ
    */
    void connectEditViewWithSlot(CGraphView* pView);
    /**
    * @brief ���༭��ͼ��Ϊ�Ǽ���״̬ʱ,���༭��ͼ���ര�������Ĳۺ����Ͽ�����
    * @param[in] pView �༭��ͼ
    */
    void disconnectEditViewWithSlot_whenInActivate(CGraphView* pView);
    /**
    * @brief ���༭��ͼ���ര�������Ĳۺ����Ͽ�����
    * @param[in] pView �༭��ͼ
    */
    void disconnectEditViewWithSlot(CGraphView* pView);
private:
	QMdiSubWindow *m_pLastActivatedMdiChild; /// �ϸ������Ĵ���(���㴰��)
	QMainWindow* m_pMainWindow;	// ������ָ��
    QToolBar *m_pEditToolBar;	/// �༭������
    QAction *m_pNewAct;			/// �½�
    QAction *m_pOpenAct;		/// �����ļ�

#ifndef QT_NO_CLIPBOARD
    QAction *m_pCutAct;			/// ����
    QAction *m_pCopyAct;		/// ����
    QAction *m_pPasteAct;		/// ����
#endif
    QAction *m_pRectAct;        /// ���Ӿ���
    QAction *m_pEllipseAct;     /// ������Բ
};

#endif // MDIAREA_H
