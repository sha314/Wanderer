#include "treeviewform.h"
#include "ui_treeviewform.h"
#include <QStandardPaths>

TreeViewForm::TreeViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeViewForm)
{
    ui->setupUi(this);

    // by shahnoor
    // set view mode path
    QString root_path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(root_path);

    ui->treeView->setModel(dirmodel);
}

TreeViewForm::~TreeViewForm()
{
    delete ui;
}
