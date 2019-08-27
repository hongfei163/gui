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
	if (index.column() != 1) {
		return QStyledItemDelegate::createEditor(parent, option, index);
	}

	if (index.row() == CTableModel::EAttr_Id) {
		QSpinBox *pEditor = new QSpinBox(parent);
		pEditor->setFrame(false);
		pEditor->setMinimum(0);
		pEditor->setMaximum(100);
		return pEditor;
	} 
	else if (index.row() == CTableModel::EAttr_Checked){
		QComboBox* pEditor = new QComboBox(parent);
		pEditor->addItems(m_strListYesNo);
		pEditor->setItemData(0, true);
		pEditor->setItemData(1, false);
		return pEditor;
	}
	else if (index.row() == CTableModel::EAttr_LastOneFlag){
		CEditor *pEditor = new CEditor(parent);
		connect(pEditor, &CEditor::editingFinished,
			this, &CDelegate::commitAndCloseEditor);
		return pEditor;
	}
	else if (index.row() == CTableModel::Eattr_AnimateSpeed){
		// �����ٶ����õ�Ԫ��	
		QComboBox* pEditor = new QComboBox(parent);
		pEditor->addItems(m_strListSpeed);
		pEditor->setItemData(0, CTableModel::EAnimateSpeed_Slow);
		pEditor->setItemData(1, CTableModel::EAnimateSpeed_Normal);
		pEditor->setItemData(2, CTableModel::EAnimateSpeed_Fast);
		return pEditor;
	}
    else {
		return QStyledItemDelegate::createEditor(parent, option, index);
	}
}

void CDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
	if (index.column() != 1) {
		return QStyledItemDelegate::setEditorData(editor, index);
	}
	if (index.row() == CTableModel::EAttr_Id) {
		int value = index.model()->data(index, Qt::EditRole).toInt();
		QSpinBox *pEditor = static_cast<QSpinBox*>(editor);
		pEditor->setValue(value);
	}
	else if (index.row() == CTableModel::EAttr_Checked) {
		QComboBox* pEditor = static_cast<QComboBox*>(editor);
		pEditor->setCurrentIndex(index.model()->data(index, Qt::EditRole).toBool() ? 0 : 1);
	}
	else if (index.row() == CTableModel::EAttr_LastOneFlag) {
		//QCheckBox* pBox = static_cast<QCheckBox*>(editor);
		//Qt::CheckState checkState = static_cast<Qt::CheckState>(index.model()->data(index, Qt::EditRole).toInt());
		//pBox->setCheckState(checkState);
		CEditor *pEditor = qobject_cast<CEditor *>(editor);
		Qt::CheckState checkState = static_cast<Qt::CheckState>(index.model()->data(index, Qt::EditRole).toInt()); 
		if (checkState)
			pEditor->setText("Y");
		else
			pEditor->setText("N");

	}
	else if (index.row() == CTableModel::Eattr_AnimateSpeed) {
		// �����ٶ����õ�Ԫ��
		QComboBox* pEditor = static_cast<QComboBox*>(editor);
		int nValue = index.model()->data(index, Qt::EditRole).toInt();
		CTableModel::EAnimateSpeed animateSpeed = static_cast<CTableModel::EAnimateSpeed>(nValue);
		pEditor->setCurrentIndex( index.model()->data(index, Qt::EditRole).toInt());
	}
	else {
		QStyledItemDelegate::setEditorData(editor, index);
	}
}

void CDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
	if (index.column() != 1) {
		QStyledItemDelegate::setModelData(editor, model, index);
	}

	if (index.row() == CTableModel::EAttr_Id)	{
		QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
		spinBox->interpretText();
		int value = spinBox->value();

		model->setData(index, value, Qt::EditRole); // Ϊģ����������
	} 
 	else if (index.row() == CTableModel::EAttr_Checked) {
		QComboBox* pBox = static_cast<QComboBox*>(editor);
		QVariant var = pBox->currentData();
		model->setData(index, var.toBool());// Ϊģ����������
	}
 	else if (index.row() == CTableModel::EAttr_LastOneFlag) {
		CEditor *pEditor = qobject_cast<CEditor *>(editor);
		QVariant var;
		var.setValue((pEditor->text() == "Y") ? Qt::Checked : Qt::Unchecked);
		model->setData(index, var);// Ϊģ����������
	}
	else if (index.row() == CTableModel::Eattr_AnimateSpeed) {
		// �����ٶ����õ�Ԫ��
		QComboBox* pBox = static_cast<QComboBox*>(editor);
		QVariant var = pBox->currentData();
		model->setData(index, var);// Ϊģ����������
	}
   else {
		QStyledItemDelegate::setModelData(editor, model, index);
	}
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
	emit closeEditor(pEditor);
}