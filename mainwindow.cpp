#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
using namespace  std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPrevious_triggered()
{
    qDebug() << "on_actionPrevious_triggered" << endl;
}

void MainWindow::on_actionNext_triggered()
{
    cout << "on_actionNext_triggered" << endl;
}

void MainWindow::on_actionParent_triggered()
{
    cout << "on_actionParent_triggered" << endl;
}

void MainWindow::on_actionIconView_toggled(bool arg1)
{
    cout << "on_actionIconView_toggled " << arg1 << endl;
}

void MainWindow::on_actionListView_toggled(bool arg1)
{
    cout << "on_actionListView_toggled " << arg1 << endl;
}

void MainWindow::on_actionColumnView_toggled(bool arg1)
{
    cout << "on_actionColumnView_toggled " << arg1 << endl;
}
