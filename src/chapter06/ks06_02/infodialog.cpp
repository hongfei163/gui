#include "infodialog.h"
#include "ui_infodialog.h"

#include <QIntValidator>

CInfoDialog::CInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CInfoDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::rejected,
            this, &CInfoDialog::reject);
    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &CInfoDialog::accept);

    connect(ui->ckEditable, &QCheckBox::stateChanged,
            this, &CInfoDialog::slot_editEnabled);

    // setValidator
    ui->leStature->setValidator(new QIntValidator(ui->leStature));

    // setInputMask
    ui->leBirthday->setInputMask("0000-00-00");
    ui->leBirthday->setText("00000000");
    ui->leBirthday->setCursorPosition(0);

    // validatorºÍinputmask
    QRegExp regExp("^1[3|4|5|8][0-9][0-9]{8}");
    ui->lePhone->setValidator(new QRegExpValidator(regExp, ui->lePhone));
    ui->lePhone->setInputMask("#00-000-00000000");
    ui->lePhone->setText("+00-000-00000000");
}

CInfoDialog::~CInfoDialog()
{
    delete ui;
}

void CInfoDialog::slot_editEnabled(bool b){
    ui->leName->setEnabled(b);
    ui->leStature->setEnabled(b);
    ui->leBirthday->setEnabled(b);
    ui->lePhone->setEnabled(b);
}
