/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file: graphview.h
\brief ��ʾ��ͷ�ļ�
  
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2018/8 
*/

#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QMouseEvent;
QT_END_NAMESPACE

class CGraphView : public QGraphicsView
{
	Q_OBJECT
public:
	CGraphView(QWidget* parent);
    ~CGraphView();

public:
    void addEllipse();
    void addRect();
    
public slots:
 #ifndef QT_NO_CLIPBOARD
    void cut();     /// ����
    void copy();    /// ����
    void paste();   /// ����
#endif

Q_SIGNALS:
    void viewMouseMove(const QPointF&);
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void drawBackground(QPainter *painter, const QRectF &rect);
    void 	createActions();

#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif

Q_SIGNALS:

private:
    void copyItems(QList<QGraphicsItem*>&);    /// ����ͼԪ
private:
#ifndef QT_NO_CLIPBOARD
    QAction *m_pCutAct;         /// ����
    QAction *m_pCopyAct;		/// ����
    QAction *m_pPasteAct;		/// ����
#endif
    QPointF m_ptScene;
};

#endif // TEXTEDIT_H