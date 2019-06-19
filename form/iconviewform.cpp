#include "iconviewform.h"
#include "ui_iconviewform.h"

IconViewForm::IconViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IconViewForm)
{
    ui->setupUi(this);
}

IconViewForm::~IconViewForm()
{
    delete ui;
}
