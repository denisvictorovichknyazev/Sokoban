#ifndef WINFORM_H
#define WINFORM_H

#include <QDialog>

namespace Ui {
class WinForm;
}

class WinForm : public QDialog
{
    Q_OBJECT

public:
    explicit WinForm(QWidget *parent = 0);
    ~WinForm();
public slots:
    void exit();
private:
    Ui::WinForm *ui;
};

#endif // WINFORM_H
