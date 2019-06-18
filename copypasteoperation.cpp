#include "copypasteoperation.h"
#include "ui_copypasteoperation.h"

CopyPasteOperation::CopyPasteOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CopyPasteOperation)
{
    ui->setupUi(this);
}

CopyPasteOperation::~CopyPasteOperation()
{
    delete ui;
}
