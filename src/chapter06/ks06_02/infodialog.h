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
    /*
    * @brief ÔÊÐí±à¼­±»µ¥»÷
    * @param[in] b true:ÔÊÐí±à¼­,false:½ûÖ¹±à¼­
    * @return void
    */
    void slot_editEnabled(bool b);
private:
    Ui::CInfoDialog *ui;
};

#endif // INFODIALOG_H
