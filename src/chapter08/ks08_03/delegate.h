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
#pragma once

#include <QStyledItemDelegate>

class CDelegate : public QStyledItemDelegate{
    Q_OBJECT
public:
    explicit CDelegate(QObject *parent = nullptr);
    virtual ~CDelegate(){}

    // editing
    /*
     * @brief Ϊָ����������༭��
     * @param[in] parent �������༭���ĸ�����
     * @param[in] option ��ʽѡ��
     * @param[in] index ����������
     * @return �����õı༭��
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    /**
    * @brief Ϊָ���������ı༭������ֵ����ģ�ͻ�ȡ���ݲ����õ��༭���ؼ���
    *
    * @param[in|out] editor ָ���������ı༭��
    * @param[in] index �ƶ�������������
    * @return ��
    */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    /**
    * @brief �ӱ༭����ȡָ����������ֵ�����õ�ģ�͡�
    *           �û��ñ༭���ؼ��޸������ݺ󣬴����ýӿڡ�
    *
    * @param[in|out] editor ָ���������ı༭��
    * @param[in|out] model ģ��
    * @param[in] index ����������
    * @return ��
    */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    /**
    * @brief ����ָ���������ı༭���ߴ硣
    *
    * @param[in|out] editor ָ���������ı༭��
    * @param[in] option ��ʽѡ��
    * @param[in] index ����������
    * @return ��
    */
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

    /**
    *	@brief	��д�����ýӿڣ�ʵ��bool����ʱ��ʾ�ǻ��߷���
    *	@param[in] value    ��ֵ
    *	@param[in] locale   ���ض���
    *	return ��ʾ���ַ���
    */
    virtual QString displayText(const QVariant &value,
                                const QLocale &locale) const override;
private slots:
    /**
    *	@brief	���ԡ�lastoneflag�����ɱ༭ʱ��Ӧ�Ĳۺ���
    *	return void
    */
    void slot_commitAndCloseEditor();
private:
    QStringList m_strListYesNo;/// �����洢yes��no�ַ���
    QStringList m_strListSpeed;/// �����洢�ٶ��ַ���
};





