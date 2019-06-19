#include "columnviewform.h"
#include "ui_columnviewform.h"
#include <QDebug>
#include <QStandardPaths>


ColumnViewForm::ColumnViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColumnViewForm)
{
    ui->setupUi(this);

    qDebug() << "ColumnViewForm " << __LINE__ ;
    dirmodel = new QFileSystemModel(this);
    current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);

    QModelIndex indx = dirmodel->index(current_location);
    qDebug() << indx.data();
    ui->columnView->setRootIndex(indx);


//    column_widths.append(min_column_width);
//    ui->columnView->setColumnWidths(column_widths);

    ui->columnView->setModel(dirmodel);
    auto widths = ui->columnView->columnWidths();
    foreach (int a, widths) {
        qDebug() << a;
    }
    column_widths.append(min_column_width);
    ui->columnView->setColumnWidths(column_widths);
}

ColumnViewForm::~ColumnViewForm()
{
    delete ui;
}

void ColumnViewForm::on_columnView_clicked(const QModelIndex &index)
{
    qDebug() << "clicked " << index.row() << " " << index.column();
    qDebug() << index.data().toString();
    current_location.append("/" + index.data(Qt::DisplayRole).toString());
//    qDebug() << index.data(Qt::DisplayRole).toString();
    qDebug() << current_location;
    int sz =  64*3; // change
    sz = sz < min_column_width? min_column_width: sz > max_column_width ? max_column_width : sz;
    qDebug() << "resizing column widths to " << sz;
    column_widths.append(sz);
    ui->columnView->setColumnWidths(column_widths);
    // also check if the clicked item is a file or folder
    // if file display details with simple preview

}
