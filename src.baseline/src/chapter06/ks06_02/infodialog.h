#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class CInfoDialog;
}

class CInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CInfoDialog(QWidget *parent = nullptr);
    ~CInfoDialog();
private slots:

private:
    Ui::CInfoDialog *ui;
};

#endif // INFODIALOG_H
