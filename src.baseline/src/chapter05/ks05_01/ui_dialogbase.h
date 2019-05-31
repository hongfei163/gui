/********************************************************************************
** Form generated from reading UI file 'dialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBASE_H
#define UI_DIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CDialogBase
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CDialogBase)
    {
        if (CDialogBase->objectName().isEmpty())
            CDialogBase->setObjectName(QStringLiteral("CDialogBase"));
        CDialogBase->resize(174, 120);
        gridLayout = new QGridLayout(CDialogBase);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CDialogBase);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CDialogBase);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(CDialogBase);
        QObject::connect(buttonBox, SIGNAL(accepted()), CDialogBase, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CDialogBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(CDialogBase);
    } // setupUi

    void retranslateUi(QDialog *CDialogBase)
    {
        CDialogBase->setWindowTitle(QApplication::translate("CDialogBase", "Dialog", nullptr));
        label->setText(QApplication::translate("CDialogBase", "This is my dialog!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDialogBase: public Ui_CDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBASE_H
