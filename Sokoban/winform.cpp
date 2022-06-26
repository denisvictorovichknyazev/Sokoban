#include "winform.h"
#include "ui_winform.h"

WinForm::WinForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinForm)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(exit()));
}

void WinForm::exit(){
	this->close();
}

WinForm::~WinForm()
{
    delete ui;
}
