#include "fileconflict.h"
#include "ui_fileconflict.h"

FileConflict::FileConflict(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileConflict)
{
    ui->setupUi(this);
}

FileConflict::~FileConflict()
{
    delete ui;
}
