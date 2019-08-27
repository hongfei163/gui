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

#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>

#include "tablemodel.h"
#include "ceditor.h"


CDelegate::CDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
	m_strListSpeed << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("����");
	m_strListYesNo << "yes" << "no";
}

QWidget *CDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem & option ,
    const QModelIndex & index ) const
{
	QModelIndex idxParent = index.parent().isValid()
		? index.parent()
		: index;

	if (index.column() != 1) {
		return NULL;
	}

	if (idxParent.row() == CTableModel::EAttr_Id) {
		QSpinBox *pEditor = new QSpinBox(parent);
		pEditor->setFrame(false);
		pEditor->setMinimum(0);
		pEditor->setMaximum(100);
		return pEditor;
	} 
	else if (idxParent.row() == CTableModel::EAttr_Checked){
		QComboBox* pEditor = new QComboBox(parent);
		pEditor->addItems(m_strListYesNo);
		pEditor->setItemData(0, true);
		pEditor->setItemData(1, false);
		return pEditor;
	}
	else if (idxParent.row() == CTableModel::EAttr_LastOneFlag){
		CEditor *pEditor = new CEditor(parent);
		connect(pEditor, &CEditor::editingFinished,
			this, &CDelegate::commitAndCloseEditor);
		return pEditor;
	}
	else if (idxParent.row() == CTableModel::Eattr_Animate){
		if (index == idxParent) {

		}
		else if (index.row() == (CTableModel::Eattr_AnimateSpeed)) {
			// �����ٶ����õ�Ԫ��	
			QComboBox* pEditor = new QComboBox(parent);
			pEditor->addItems(m_strListSpeed);
			pEditor->setItemData(0, CTableModel::EAnimateSpeed_Slow);
			pEditor->setItemData(1, CTableModel::EAnimateSpeed_Normal);
			pEditor->setItemData(2, CTableModel::EAnimateSpeed_Fast);
			return pEditor;
		}
	}
	return QStyledItemDelegate::createEditor(parent, option, index);
}

void CDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
	QModelIndex idxParent = index.parent().isValid()
		? index.parent()
		: index;

	if (index.column() != 1) {
		return QStyledItemDelegate::setEditorData(editor, index);
	}
	if (idxParent.row() == CTableModel::EAttr_Id) {
		int value = index.model()->data(index, Qt::EditRole).toInt();
		QSpinBox *pEditor = static_cast<QSpinBox*>(editor);
		pEditor->setValue(value);
		return;
	}
	else if (idxParent.row() == CTableModel::EAttr_Checked) {
		QComboBox* pEditor = static_cast<QComboBox*>(editor);
		pEditor->setCurrentIndex(index.model()->data(index, Qt::EditRole).toBool() ? 0 : 1);
		return;
	}
	else if (idxParent.row() == CTableModel::EAttr_LastOneFlag) {
		CEditor *pEditor = qobject_cast<CEditor *>(editor);
		Qt::CheckState checkState = static_cast<Qt::CheckState>(index.model()->data(index, Qt::EditRole).toInt()); 
		if (checkState)
			pEditor->setText("Y");
		else
			pEditor->setText("N");
		return;
	}
	else if (idxParent.row() == CTableModel::Eattr_Animate){
		if (index == idxParent) {

		}
		else if (index.row() == (CTableModel::Eattr_AnimateSpeed)) {
			// �����ٶ����õ�Ԫ��
			QComboBox* pEditor = static_cast<QComboBox*>(editor);
			int nValue = index.model()->data(index, Qt::EditRole).toInt();
			CTableModel::EAnimateSpeed animateSpeed = static_cast<CTableModel::EAnimateSpeed>(nValue);
			pEditor->setCurrentIndex(index.model()->data(index, Qt::EditRole).toInt());
			return;
		}
	}
	
	QStyledItemDelegate::setEditorData(editor, index);	
}

void CDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
	QModelIndex idxParent = index.parent().isValid()
		? index.parent()
		: index;

	if (index.column() != 1) {
		QStyledItemDelegate::setModelData(editor, model, index);
		return;
	}

	if (idxParent.row() == CTableModel::EAttr_Id)	{
		QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
		spinBox->interpretText();
		int value = spinBox->value();
		model->setData(index, value, Qt::EditRole); // Ϊģ����������
		return;
	} 
 	else if (idxParent.row() == CTableModel::EAttr_Checked) {
		QComboBox* pBox = static_cast<QComboBox*>(editor);
		QVariant var = pBox->currentData();
		model->setData(index, var.toBool());// Ϊģ����������
		return;
	}
 	else if (idxParent.row() == CTableModel::EAttr_LastOneFlag) {
		CEditor *pEditor = qobject_cast<CEditor *>(editor);
		QVariant var;
		var.setValue((pEditor->text() == "Y") ? true : false);
		model->setData(index, var);// Ϊģ����������
		return;
	}
	else if (idxParent.row() == CTableModel::Eattr_Animate) {
		if (index == idxParent) {

		}
		else if (index.row() == (CTableModel::Eattr_AnimateSpeed)) {
			// �����ٶ����õ�Ԫ��
			QComboBox* pBox = static_cast<QComboBox*>(editor);
			QVariant var = pBox->currentData();
			model->setData(index, var);// Ϊģ����������
			return;
		}
	}

	QStyledItemDelegate::setModelData(editor, model, index);
}


void CDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

QString CDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
	switch (value.userType()) {
	case QMetaType::Bool:
		return value.toBool() ? tr("yes") : tr("no");
		break;
	default:
		return QStyledItemDelegate::displayText(value, locale);
	}
}

void CDelegate::commitAndCloseEditor()
{
	CEditor *pEditor = qobject_cast<CEditor *>(sender());
	emit commitData(pEditor);
	//emit closeEditor(pEditor);
}

//bool CDelegate::editorEvent(QEvent *event,
//	QAbstractItemModel *model,
//	const QStyleOptionViewItem &option,
//	const QModelIndex &index)
//{
//	return QStyledItemDelegate::editorEvent(event, model, option, index);
//}
