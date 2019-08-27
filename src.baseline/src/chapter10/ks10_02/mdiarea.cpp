/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: mdiarea.cpp
\brief ��ʾ��ͷ�ļ�

\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8
*/
#include <QAction>
#include <QFileInfo>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QToolBar>

#include "mdiarea.h"
#include "graphview.h"


CEditMdiArea::CEditMdiArea(QMainWindow* pMainWindow) : QMdiArea(pMainWindow), m_pLastActivatedMdiChild(NULL), m_pMainWindow(pMainWindow)
{
    createActions();
    createToolBars();
    connect(this, SIGNAL(subWindowActivated(QMdiSubWindow*)),
        this, SLOT(onSubWindowActivate(QMdiSubWindow*)));
    onSubWindowActivate(NULL);

}

CEditMdiArea::~CEditMdiArea()
{

}

bool CEditMdiArea::openFile(const QString &fileName, QString* pError)
{
    bool succeeded = false;
    if (!fileName.isEmpty())  {
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing)   {
            setActiveSubWindow(existing);
            return true;
        }
        CGraphView* child = createMdiChild(fileName, pError);
        succeeded = child->isValid();
        if (succeeded)  {
            child->showMaximized();
        }
        else  {
            if (NULL != child->parent())   {
                QMdiSubWindow* pSubWindow = dynamic_cast<QMdiSubWindow*>(child->parent());
                (NULL != pSubWindow) ? pSubWindow->close() : child->close();
            }
            else  {
                child->close();
            }
        }
    }
    else  {
        if (NULL != pError)  {
            *pError = tr("filename is empty");
        }
    }
    return succeeded;
}
void CEditMdiArea::onSubWindowActivate(QMdiSubWindow *pMdiChild)
{
    bool hasMdiChild = (pMdiChild == NULL) ? false : true;
    if (hasMdiChild)   {
        if (pMdiChild != m_pLastActivatedMdiChild)   {
            if (m_pLastActivatedMdiChild != NULL)  {
                CGraphView* pView = getActiveEditView(m_pLastActivatedMdiChild);
                if (NULL != pView)   {
                    // ��Ҫ�Ѳۺ���������ͼ���󣬷�ֹ����ͼ�źż��������ۺ���
                    disconnectEditViewWithSlot_whenInActivate(pView);
                }
            }
            CGraphView* pView = getActiveEditView(pMdiChild);
            if (NULL != pView)   {
                QWidget* pWidget = pView;
                
                emit editViewChanged(pWidget); // �����ź�
         
                // ���༭��ͼ�ҽӵ��ര�������Ĳۺ���
                connectEditViewWithSlot(pView);
            }
            m_pLastActivatedMdiChild = pMdiChild;
        }
    }
   
#ifndef QT_NO_CLIPBOARD
    m_pPasteAct->setEnabled(hasMdiChild);
#endif
}
QMainWindow* CEditMdiArea::getMainWindow()
{
    return m_pMainWindow;
}

CGraphView * CEditMdiArea::activeMdiChild()
{
    CGraphView* pView = NULL;
    QMdiSubWindow *tActiveSubWindow = activeSubWindow();
    if (NULL == tActiveSubWindow)
    {
        tActiveSubWindow = m_pLastActivatedMdiChild;
    }
    if (NULL != tActiveSubWindow)
    {
        pView = getActiveEditView(tActiveSubWindow);
    }
    return pView;
}

CGraphView* CEditMdiArea::createMdiChild(const QString& fileName, QString* /*pError*/)
{
    QGraphicsScene* pScene = new QGraphicsScene(this);
    CGraphView* pView = new CGraphView(this);
    pView->setScene(pScene);
    QRectF rct(0, 0, 400,400);
    pScene->setSceneRect(rct);
    if (fileName.length() > 0)  {
       //pView->openFile(fileName);
    }
    if ((NULL != pView) && pView->isValid())
    {
        QMdiSubWindow *subWindow1 = new QMdiSubWindow;
        subWindow1->setWidget(pView);
        subWindow1->setAttribute(Qt::WA_DeleteOnClose);
        addSubWindow(subWindow1);
        pView->setParent(subWindow1);
    }
    return pView;
}
QMdiSubWindow *CEditMdiArea::findMdiChild(const QString &fileName)
{
    QString strFileName = QFileInfo(fileName).fileName();
    foreach(QMdiSubWindow *window, subWindowList())
    {
        CGraphView* pView = getActiveEditView(window);
        if (NULL != pView && pView->getFileName() == strFileName)
        {
            return window;
        }
    }
    return 0;
}
CGraphView* CEditMdiArea::getActiveEditView(QMdiSubWindow* pMdiChild)
{
    if (NULL == pMdiChild)   {
        return NULL;
    }
    CGraphView* pView = NULL;
    if (NULL != pMdiChild->widget()) { 
       pView = dynamic_cast<CGraphView*>(pMdiChild->widget());
    }   
    return pView;
}

void CEditMdiArea::slot_new()
{
    CGraphView* child = createMdiChild("");
    if (NULL == child)
    {
        return;
    }
    bool succeeded = child->isValid();
    if (succeeded)
    {
        child->showMaximized();
    }
    else
    {
        child->close();
    }
}

void CEditMdiArea::onViewClose(QWidget* pChild)
{
    if (pChild == NULL)
    {
        return;
    }

    CGraphView* pView = dynamic_cast<CGraphView*>(pChild);
    if (NULL != pView)   {
        disconnectEditViewWithSlot(pView); // ���༭��ͼ���ര�������Ĳۺ����Ͽ�����
    }
    m_pLastActivatedMdiChild = NULL;

    emit editViewClose(pChild);
    m_pLastActivatedMdiChild = NULL; // ��ֹӦ�ò����� editViewClose �źŵĴ������´���activeSubWindow�Ӷ�ʹm_pLastActivatedMdiChild���±���ֵ��Ϊ�ѹرյĴ��ڣ�

}

void CEditMdiArea::connectEditViewWithSlot(CGraphView* pView)
{
    connect(pView, SIGNAL(viewMouseMove(QMouseEvent*)), 
        this, SIGNAL(viewMouseMove(QMouseEvent*)));
    connect(pView, SIGNAL(viewClose(QWidget*)), 
        this, SLOT(onViewClose(QWidget*)));
}

void CEditMdiArea::disconnectEditViewWithSlot(CGraphView* pView)
{
    disconnectEditViewWithSlot_whenInActivate(pView);
    disconnect(pView, SIGNAL(viewClose(QWidget*)), 
        this, SLOT(onViewClose(QWidget*)));
}
void CEditMdiArea::disconnectEditViewWithSlot_whenInActivate(CGraphView* pView)
{
    disconnect(pView, SIGNAL(viewMouseMove(QMouseEvent*)),
        this, SIGNAL(viewMouseMove(QMouseEvent*)));
}
void CEditMdiArea::createActions()
{
    m_pNewAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    m_pNewAct->setShortcuts(QKeySequence::New);
    m_pNewAct->setStatusTip(tr("New File"));
    connect(m_pNewAct, &QAction::triggered, this, &CEditMdiArea::slot_new);

    m_pOpenAct = new QAction(QIcon(":/images/open.png"), tr("&New"), this);
    m_pOpenAct->setShortcuts(QKeySequence::Open);
    m_pOpenAct->setStatusTip(tr("Open File"));
    connect(m_pOpenAct, &QAction::triggered, this, &CEditMdiArea::slot_open);

#ifndef QT_NO_CLIPBOARD
    m_pCutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
    m_pCutAct->setShortcuts(QKeySequence::Cut);
    m_pCutAct->setStatusTip(tr("Cut the current selection's contents to the "
        "clipboard"));
    connect(m_pCutAct, &QAction::triggered, this, &CEditMdiArea::slot_cut);

    m_pCopyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    m_pCopyAct->setShortcuts(QKeySequence::Copy);
    m_pCopyAct->setStatusTip(tr("Copy the current selection's contents to the "
        "clipboard"));
    connect(m_pCopyAct, &QAction::triggered, this, &CEditMdiArea::slot_copy);

    m_pPasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    m_pPasteAct->setShortcuts(QKeySequence::Paste);
    m_pPasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
        "selection"));
    connect(m_pPasteAct, &QAction::triggered, this, &CEditMdiArea::slot_paste);
#endif

    m_pRectAct = new QAction(tr("addRect"), this);
    m_pRectAct->setStatusTip(tr("add rect to view"));
    connect(m_pRectAct, &QAction::triggered, this, &CEditMdiArea::slot_addRect);

    m_pEllipseAct = new QAction(tr("addEllipse"), this);
    m_pEllipseAct->setStatusTip(tr("add ellipse to view"));
    connect(m_pEllipseAct, &QAction::triggered, this, &CEditMdiArea::slot_addEllipse);

}

void CEditMdiArea::createToolBars()
{
    m_pEditToolBar = m_pMainWindow->addToolBar(tr("edit tool bar"));
    m_pEditToolBar->setObjectName("edit tool bar");
    m_pEditToolBar->addAction(m_pNewAct);
    m_pEditToolBar->addAction(m_pOpenAct);
#ifndef QT_NO_CLIPBOARD
    m_pEditToolBar->addAction(m_pCutAct);
    m_pEditToolBar->addAction(m_pCopyAct);
    m_pEditToolBar->addAction(m_pPasteAct);
#endif

    m_pEditToolBar->addAction(m_pRectAct);
    m_pEditToolBar->addAction(m_pEllipseAct);

}

void CEditMdiArea::slot_open()
{
    openFile("");
}

#ifndef QT_NO_CLIPBOARD
void CEditMdiArea::slot_cut()
{
    CGraphView* pView = activeMdiChild();
    if (NULL == pView)
        return;
    pView->cut();
}

void CEditMdiArea::slot_copy()
{
    CGraphView* pView = activeMdiChild();
    if (NULL == pView)
        return;
    pView->copy();
}

void CEditMdiArea::slot_paste()
{
    CGraphView* pView = activeMdiChild();
    if (NULL == pView)
        return;
    pView->paste();
}
#endif

void CEditMdiArea::slot_addRect()
{
    CGraphView* pView = activeMdiChild();
    if (NULL == pView)
        return;
    pView->addRect();
}

void CEditMdiArea::slot_addEllipse()
{
    CGraphView* pView = activeMdiChild();
    if (NULL == pView)
        return;
    pView->addEllipse();
}
