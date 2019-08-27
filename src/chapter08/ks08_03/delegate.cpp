/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file delegate.cpp
\brief delegateʵ���ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/

#include "delegate.h"

#include <QComboBox>
#include <QSpinBox>

#include "tablemodel.h"
#include "editor.h"

CDelegate::CDelegate(QObject* parent):
    QStyledItemDelegate (parent){

    m_strListYesNo << "yes" << "no"; // 0��yes, 1:no
    m_strListSpeed << QString::fromLocal8Bit("����") // tr("")
                   << QString::fromLocal8Bit("����")
                   << QString::fromLocal8Bit("����");
}

QWidget *CDelegate::createEditor(QWidget *parent,
                      const QStyleOptionViewItem &option,
                      const QModelIndex &index) const {
    // ֻ�е�1�������༭
    if (1 != index.column()){
        return QStyledItemDelegate::createEditor(parent,
                                                 option,
                                                 index);
    }

    if (CTableModel::EAttr_Id == index.row()) {
        QSpinBox* pEditor = new QSpinBox(parent);
        pEditor->setFrame(false);
        pEditor->setMinimum(0);
        pEditor->setMaximum(100);
        return pEditor;
    }
    else if (CTableModel::EAttr_Checked == index.row()) {
        QComboBox* pEditor = new QComboBox(parent);
        pEditor->addItems(m_strListYesNo);
        pEditor->setItemData(0, 0); // 0:yes,����=0����Ӧ��ֵ=0
        pEditor->setItemData(1, 1); // 1:no,����=1����Ӧ��ֵ=1
        return pEditor;
    }
    else if(CTableModel::EAttr_LastOneFlag == index.row()) {
        CEditor *pEditor = new CEditor(parent);
        connect(pEditor, &CEditor::sig_editFinished,
                this, &CDelegate::slot_commitAndCloseEditor);
        return pEditor;

    }
    else if (CTableModel::Eattr_AnimateSpeed == index.row()){
        QComboBox* pEditor = new QComboBox(parent);
        pEditor->addItems(m_strListSpeed);
        pEditor->setItemData(0, CTableModel::EAnimateSpeed_Slow);
        pEditor->setItemData(1, CTableModel::EAnimateSpeed_Normal);
        pEditor->setItemData(2, CTableModel::EAnimateSpeed_Fast);
        return pEditor;
    }
    else {
        return QStyledItemDelegate::createEditor(parent,
                                                 option,
                                                 index);
    }
}

void CDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    if (1 != index.column()) {
        return QStyledItemDelegate::setEditorData(editor, index);
    }
    if (CTableModel::EAttr_Id == index.row()){
        QSpinBox* pEditor = dynamic_cast<QSpinBox*>(editor);
        int value = index.model()->data(index, Qt::EditRole).toInt();
        pEditor->setValue(value);
    }
    else if (CTableModel::EAttr_Checked == index.row()){
        QComboBox* pEditor = dynamic_cast<QComboBox*>(editor);
        //      index  value(data())
        // yes  0        0
        // no   1        1
        int idx = (index.model()->data(index, Qt::EditRole).toBool() ? 1 : 0);
        pEditor->setCurrentIndex(idx);
    }
    else if (CTableModel::EAttr_LastOneFlag == index.row()) {
        CEditor* pEditor = dynamic_cast<CEditor*>(editor);
        QVariant var = index.model()->data(index, Qt::EditRole);
        Qt::CheckState checkState = static_cast<Qt::CheckState>(var.toInt());
        if (checkState) {
            pEditor->setText(QString::fromLocal8Bit("��"));
        }
        else {
            pEditor->setText(QString::fromLocal8Bit("��"));
        }
    }
    else if (CTableModel::Eattr_AnimateSpeed == index.row()){
        QComboBox* pEditor = static_cast<QComboBox*>(editor);
        int value = index.model()->data(index, Qt::EditRole).toInt(); //
       // CTableModel::EAnimateSpeed eSpeed =
       //         static_cast<CTableModel::EAnimateSpeed>(value);
        pEditor->setCurrentIndex(value);
    }
    else {
        QStyledItemDelegate::setEditorData(editor, index);
    }

}

void CDelegate::setModelData(QWidget *editor,
                  QAbstractItemModel *model,
                  const QModelIndex &index) const {
    if (1 != index.column()){
        return QStyledItemDelegate::setModelData(editor, model, index);
    }
    QVariant var;
    if (CTableModel::EAttr_Id == index.row()){
        QSpinBox* pEditor = qobject_cast<QSpinBox*>(editor);
        pEditor->interpretText();
        model->setData(index, pEditor->value(), Qt::EditRole);
    }
    else if (CTableModel::EAttr_Checked == index.row()){
        QComboBox* pEditor = qobject_cast<QComboBox*>(editor);
        var = pEditor->currentData();// 0:yes, 1:no
        model->setData(index, var.toBool());
    }
    else if (CTableModel::EAttr_LastOneFlag == index.row()) {
        CEditor* pEditor = qobject_cast<CEditor*>(editor);
        var.setValue((pEditor->text()==QString::fromLocal8Bit("��")) ? true : false);
        model->setData(index, var);
    }
    else if (CTableModel::Eattr_AnimateSpeed == index.row()){
        QComboBox* pEditor = qobject_cast<QComboBox*>(editor);
        var = pEditor->currentData();
        model->setData(index, var);
    }
    else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void CDelegate::updateEditorGeometry(QWidget *editor,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const {

    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}


void CDelegate::slot_commitAndCloseEditor() {

    CEditor* pEditor = dynamic_cast<CEditor*>(sender());

    emit commitData(pEditor); // �ύ����
    emit closeEditor(pEditor);// �رձ༭���ؼ�

}

QString CDelegate::displayText(const QVariant &value,
                                const QLocale &locale) const {

    switch (value.userType()) {
    case QMetaType::Bool:
        {
            QString str = (value.toBool() ?
                               QString::fromLocal8Bit("��") :
                               QString::fromLocal8Bit("��"));
            return str;
        }
        break;
    default:
        return QStyledItemDelegate::displayText(value, locale);
    }
}
