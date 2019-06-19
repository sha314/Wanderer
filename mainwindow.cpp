#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStandardPaths>
#include <iostream>
#include <QTreeWidget>

#include<QColumnView>

using namespace  std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // added by shahnoor
    currentViewMode = ViewMode::IconView;

//    QStringList fileNames{"Fvorite", "Devices", "Network"};
//    QTreeWidget treeWidget;
//    treeWidget.setColumnCount(1);

//    for (const auto& filename : fileNames)
//    {
//        QTreeWidgetItem *parentTreeItem = new QTreeWidgetItem(&treeWidget);
//        parentTreeItem->setText(0, filename.split('/').first());
//        QStringList filenameParts = filename.split('/').mid(1);

//        for(const auto& filenamePart : filenameParts)
//        {
//             QTreeWidgetItem *treeItem = new QTreeWidgetItem();
//             treeItem->setText(0, filenamePart);
//             parentTreeItem->addChild(treeItem);
//             parentTreeItem = treeItem;
//        }
//    }

//    treeWidget.show();


    // set view mode path
//    QString root_path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
//    dirmodel = new QFileSystemModel(this);
//    dirmodel->setRootPath(root_path);

    current_widget = ui->listView;



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


void MainWindow::on_actionTreeView_triggered()
{
    qDebug() << "on_actionTreeView_triggered " << __LINE__;
//    cvf.show();
    if (currentViewMode != ViewMode::TreeView){
        // no need to change view mode if it is already activated
        currentViewMode = ViewMode::TreeView;


        // add and remove widget in layout
        qDebug() << " add and remove widget in layout " << __LINE__ ;
    //    ui->treeView->setModel(dirmodel);
        auto treeViewIndex = ui->horizontalLayout->indexOf(ui->treeView);
        qDebug() << "treeViewIndex " << treeViewIndex;
        auto listViewIndex = ui->horizontalLayout->indexOf(ui->listView);
        qDebug() << "listViewIndex " << listViewIndex;

        QTreeView * view_navigation = new QTreeView();
        view_navigation->setObjectName(QString::fromUtf8("columnView"));

    //    QWidget *column_view_widget = new QColumnView(this);
    //    ui->horizontalLayout->removeWidget(ui->listView);
          //Insert widget at new position
    //    ui->horizontalLayout->insertWidget(listViewIndex , column_view_widget);

        ui->horizontalLayout->replaceWidget(current_widget , view_navigation);


        dirmodel = new QFileSystemModel(this);
        QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        dirmodel->setRootPath(current_location);

        QModelIndex indx = dirmodel->index(current_location);
        qDebug() << indx.data();
        view_navigation->setRootIndex(indx);


        //    column_widths.append(min_column_width);
        //    ui->columnView->setColumnWidths(column_widths);

        view_navigation->setModel(dirmodel);


        current_widget = view_navigation;
    }else{
        qDebug() << "already in the selected viewmode";
        return;
    }

    qDebug() << "on_actionTreeView_triggered" << __LINE__;
    ui->actionTreeView->setChecked(true);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionListView_triggered()
{
    qDebug() << "on_actionListView_triggered " << __LINE__;
//    cvf.show();
    if (currentViewMode != ViewMode::ListView){
        currentViewMode = ViewMode::ListView;
        // no need to change view mode if it is already activated
        // add and remove widget in layout
        qDebug() << " add and remove widget in layout " << __LINE__ ;
    //    ui->treeView->setModel(dirmodel);
        auto treeViewIndex = ui->horizontalLayout->indexOf(ui->treeView);
        qDebug() << "treeViewIndex " << treeViewIndex;
        auto listViewIndex = ui->horizontalLayout->indexOf(ui->listView);
        qDebug() << "listViewIndex " << listViewIndex;

        QListView * view_navigation = new QListView();
        view_navigation->setObjectName(QString::fromUtf8("columnView"));

    //    QWidget *column_view_widget = new QColumnView(this);
    //    ui->horizontalLayout->removeWidget(ui->listView);
          //Insert widget at new position
    //    ui->horizontalLayout->insertWidget(listViewIndex , column_view_widget);

        ui->horizontalLayout->replaceWidget(current_widget , view_navigation);


        dirmodel = new QFileSystemModel(this);
        QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        dirmodel->setRootPath(current_location);

        QModelIndex indx = dirmodel->index(current_location);
        qDebug() << indx.data();
        view_navigation->setRootIndex(indx);


        //    column_widths.append(min_column_width);
        //    ui->columnView->setColumnWidths(column_widths);

        view_navigation->setModel(dirmodel);


        current_widget = view_navigation;
    }else{
        qDebug() << "already in the selected viewmode";
        return;
    }

    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(true);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionIconView_triggered()
{
    qDebug() << "on_actionIconView_triggered " << __LINE__;
    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(true);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionColumnView_triggered()
{
    qDebug() << "on_actionColumnView_triggered " << __LINE__;
    if (currentViewMode != ViewMode::ColumnView){
        currentViewMode = ViewMode::ColumnView;
        // add and remove widget in layout
        qDebug() << " add and remove widget in layout " << __LINE__ ;
    //    ui->treeView->setModel(dirmodel);
        auto treeViewIndex = ui->horizontalLayout->indexOf(ui->treeView);
        qDebug() << "treeViewIndex " << treeViewIndex;
        auto listViewIndex = ui->horizontalLayout->indexOf(ui->listView);
        qDebug() << "listViewIndex " << listViewIndex;

        QColumnView * view_navigation = new QColumnView();

        view_navigation->setObjectName(QString::fromUtf8("columnView"));

    //    QWidget *column_view_widget = new QColumnView(this);
    //    ui->horizontalLayout->removeWidget(ui->listView);
          //Insert widget at new position
    //    ui->horizontalLayout->insertWidget(listViewIndex , column_view_widget);

//        ui->horizontalLayout->replaceWidget(ui->listView , view_navigation);
        ui->horizontalLayout->replaceWidget(current_widget , view_navigation);


        dirmodel = new QFileSystemModel(this);
        QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        dirmodel->setRootPath(current_location);

        QModelIndex indx = dirmodel->index(current_location);
        qDebug() << indx.data();
        view_navigation->setRootIndex(indx);


        //    column_widths.append(min_column_width);
        //    ui->columnView->setColumnWidths(column_widths);

        view_navigation->setModel(dirmodel);
        auto widths = view_navigation->columnWidths();
        foreach (int a, widths) {
            qDebug() << a;
        }
        column_widths.append(min_column_width);
        view_navigation->setColumnWidths(column_widths);

        current_widget = view_navigation;

    }else{
        qDebug() << "already in the selected viewmode";
        return;
    }
    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(true);
}




