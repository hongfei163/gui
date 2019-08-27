#include "dialog.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent)
{
	ui.setupUi(this);
	//m_pLabel2->setText(  tr("this is translated by source code.")   );
	ui.m_pLabel2->setText( tr( "this is translated by source code." )  );
}

CDialog::~CDialog()
{
	
}
