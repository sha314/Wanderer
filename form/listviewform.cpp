#include "listviewform.h"
#include "ui_listviewform.h"
#include<QStandardPaths>

ListViewForm::ListViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListViewForm)
{
    ui->setupUi(this);

    // by shahnoor
    // set view mode path
    QString root_path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(root_path);

    ui->listView->setModel(dirmodel);
}

ListViewForm::~ListViewForm()
{
    delete ui;
}
