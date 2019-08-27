/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ���������ڿγ̡�Qt����������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;�����������Ը���

\file delegate.h
\brief delegateͷ�ļ�
\author Ů�����ϰ�   http://xingdianketang.cn/
\Date 2019/1
*/
#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>

class CDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
	CDelegate(QObject *parent = 0);

	/**
	* @brief Ϊָ����������༭��
	*
	* @param[in|out] parent �������༭���ĸ�����
	* @param[in] option ��ʽѡ��
	* @param[in] index ����������
	* @return �����õı༭��
	*/
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

	/**
	* @brief Ϊָ���������ı༭������ֵ
	*
	* @param[in|out] editor ָ���������ı༭��
	* @param[in] index ����������
	* @return ��
	*/
	void setEditorData(QWidget *editor, const QModelIndex &index) const override;
	
	/**
	* @brief �ӱ༭����ȡָ����������ֵ�����õ�ģ��
	*
	* @param[in|out] editor ָ���������ı༭��
	* @param[in|out] model ģ��
	* @param[in] index ����������
	* @return ��
	*/
	void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

	/**
	* @brief ����ָ���������ı༭���ߴ�
	*
	* @param[in|out] editor ָ���������ı༭��
	* @param[in] option ��ʽѡ��
	* @param[in] index ����������
	* @return ��
	*/
	void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	/**
	*	@brief	��д�����ýӿڣ�ʵ��bool����ʱ��ʾ�ǻ��߷���
	*	@param[in] value	�¼�
	*	@param[in] locale	���ض���
	*	return ��ʾ���ַ���
	*/
	virtual QString displayText(const QVariant &value, const QLocale &locale) const;

	///**
	//*	@brief	��д�����༭���¼��ӿ�
	//*	@param[in] event	�¼�
	//*	@param[in] model    ģ��
	//*	@param[in] option	��ʽѡ��
	//*	@param[in] index	����������
	//*	@return		true:�����ɹ�, false:ʧ��
	//*/
	//virtual bool editorEvent(QEvent *event,
	//	QAbstractItemModel *model,
	//	const QStyleOptionViewItem &option,
	//	const QModelIndex &index);

private slots:
	void commitAndCloseEditor();

private:
	QStringList m_strListYesNo;/// �����洢yes��no�ַ���
	QStringList m_strListSpeed;/// �����洢�ٶ��ַ���
};

#endif
