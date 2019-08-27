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
	CGraphView(QWidget* parent, const QString& strFileName="");
    ~CGraphView();

public:
    QPointF getMousePressPoint() { return m_ptView; }///��ȡ���굥����������
    void addEllipse();
    void addRect();
    bool isValid();
    QString getFileName() const;

public slots:
 #ifndef QT_NO_CLIPBOARD
    void cut();     /// ����
    void copy();    /// ����
    void paste();   /// ����
#endif

Q_SIGNALS:
    void viewMouseMove(const QPointF&);
    void viewClose(QWidget*);		/// �����յ����źź󣬵���disconnect���ص�signal������
protected:
    void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    /**
    * @brief ��ͼ�ر��������
    * �������صĸ��ຯ��������֪ͨ���Դ��Ƚ�����Ӧ������
    * @param event ��ͼ�ر����
    */
    virtual void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
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
    QPointF m_ptView;
    QPointF m_ptScene;
    QString m_strFileName;
};

#endif // TEXTEDIT_H