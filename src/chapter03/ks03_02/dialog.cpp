#include "dialog.h"
#include <QCheckBox>


CDialog::CDialog(QWidget* pParent) : QDialog(pParent)
{
	ui.setupUi(this);

	connect(ui.checkBox, &QCheckBox::clicked, this, &CDialog::onChecked);
}

CDialog::~CDialog()
{
	
}

void CDialog::onChecked(bool checked)
{
	QString str;
	if (checked)
	{
		str = "i am checked.";
	}
	else
	{
		str = "please check!";
	}
	ui.m_pLabel2->setText(tr(str.toLocal8Bit().data()));
}