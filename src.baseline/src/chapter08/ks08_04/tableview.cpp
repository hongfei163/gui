﻿/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file tableview.cpp
\brief tableview实现文件
\author 女儿叫老白   http://xingdianketang.cn/
\Date 2019/1
*/

#include <QtWidgets>

#include "tableview.h"

void CTableView::mousePressEvent(QMouseEvent *event)
{
	QPoint pos = event->pos();
	QPersistentModelIndex index = indexAt(pos);
	// 如果本次选择和上次不一样，则需要关闭上次的编辑器
	if ((index != m_indexLast) && m_indexLast.isValid()) {
		closePersistentEditor(m_indexLast);
	}
	m_indexLast = index;
	if (index.isValid() && (1==index.column())) {
		// 打开编辑器进入编辑状态
		openPersistentEditor(index);
	}
	QTableView::mousePressEvent(event);
}