#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStandardPaths>
#include <iostream>

#include <QTreeWidget>
#include <QColumnView>
#include <QTableView>
#include <QListView>

using namespace  std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // added by shahnoor

    qDebug() << "__LINE__ " << __LINE__ ;

    initializeSideBar();
    initializeNavigationPanel(); // current view mode is set inside


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

//    current_widget = ui->listView;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete dirmodel;
    delete filemodel;
    delete navigation_panel;
    delete sidebar;
    delete widget_sidebar;
}

void MainWindow::inforLayout()
{
    int elements = ui->horizontalLayout->count();
    qDebug() << elements << " in " << ui->horizontalLayout;
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
    if (currentViewMode == ViewMode::TreeView){
        // no need to change view mode if it is already activated
        qDebug() << "already in the selected viewmode";
        return;
    }
    inforLayout();
    currentViewMode = ViewMode::TreeView;
    // removel previous
    navigation_panel->setParent(nullptr);
    ui->horizontalLayout->removeWidget(navigation_panel);

    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QWidget(this);

    QTreeView *view_navigation = nullptr;


    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QTreeView();

    view_navigation = dynamic_cast<QTreeView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));

    //    ui->widget_navigation_panel

    dirmodel = new QFileSystemModel(this);

    QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);
//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    view_navigation->setModel(dirmodel);


    view_navigation->setObjectName(QString::fromUtf8("columnView"));

    // set properties of the panel
    view_navigation->resizeColumnToContents(0);
    view_navigation->setColumnWidth(0, 200);

    // monitoring clicks on item
    connect(view_navigation, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));


    // finally add the navigation panel
    ui->horizontalLayout->addWidget(navigation_panel);


    inforLayout();

    ui->actionTreeView->setChecked(true);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionListView_triggered()
{
    qDebug() << "on_actionListView_triggered " << __LINE__;
//    cvf.show();
    if (currentViewMode == ViewMode::ListView){
        // no need to change view mode if it is already activated
        qDebug() << "already in the selected viewmode";
        return;
    }
    currentViewMode = ViewMode::ListView;

    inforLayout();
    // removel previous
    navigation_panel->setParent(nullptr);
    ui->horizontalLayout->removeWidget(navigation_panel);

    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QWidget(this);

    QListView *view_navigation = nullptr;


    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QListView();

    view_navigation = dynamic_cast<QListView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));

    //    ui->widget_navigation_panel

    dirmodel = new QFileSystemModel(this);

    QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);
//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    view_navigation->setModel(dirmodel);


    view_navigation->setObjectName(QString::fromUtf8("columnView"));

    // monitoring clicks on item
    connect(view_navigation, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));


    // finally add the navigation panel
    ui->horizontalLayout->addWidget(navigation_panel);

    inforLayout();

    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(true);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionIconView_triggered()
{
    qDebug() << "on_actionIconView_triggered " << __LINE__;
    if (currentViewMode == ViewMode::IconView) {
        // no need to change view mode if it is already activated
        qDebug() << "already in the selected viewmode";
        return;
    }
    currentViewMode = ViewMode::IconView;
    inforLayout();

    // removel previous
    navigation_panel->setParent(nullptr);
    ui->horizontalLayout->removeWidget(navigation_panel);
    // add and remove widget in layout
    navigation_panel = new QWidget(this);

    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;

    QTableView * view_navigation = nullptr;
    navigation_panel = new QTableView();

    view_navigation = dynamic_cast<QTableView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));

//    ui->widget_navigation_panel

    dirmodel = new QFileSystemModel(this);

    QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);
//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    view_navigation->setModel(dirmodel);

    // monitoring clicks on item
    connect(view_navigation, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));


    // finally add the navigation panel
    ui->horizontalLayout->addWidget(navigation_panel);

    inforLayout();

    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(true);
    ui->actionColumnView->setChecked(false);
}

void MainWindow::on_actionColumnView_triggered()
{
    qDebug() << "on_actionColumnView_triggered " << __LINE__;
    if (currentViewMode == ViewMode::ColumnView){
        // no need to change view mode if it is already activated
        qDebug() << "already in the selected viewmode";
        return;
    }

    currentViewMode = ViewMode::ColumnView;

    inforLayout();

    // removel previous
    navigation_panel->setParent(nullptr);
    ui->horizontalLayout->removeWidget(navigation_panel);

    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QWidget(this);
    QColumnView *view_navigation = nullptr;


    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;


    navigation_panel = new QColumnView();

    view_navigation = dynamic_cast<QColumnView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));

    //    ui->widget_navigation_panel

    dirmodel = new QFileSystemModel(this);

    QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);
//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    view_navigation->setModel(dirmodel);


    auto widths = view_navigation->columnWidths();
    foreach (int a, widths) {
        qDebug() << a;
    }
    column_widths.append(min_column_width);
    view_navigation->setColumnWidths(column_widths);

    view_navigation->setObjectName(QString::fromUtf8("columnView"));

    // monitoring clicks on item
    connect(view_navigation, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));


    // finally add the navigation panel
    ui->horizontalLayout->addWidget(navigation_panel);


    inforLayout();

    ui->actionTreeView->setChecked(false);
    ui->actionListView->setChecked(false);
    ui->actionIconView->setChecked(false);
    ui->actionColumnView->setChecked(true);
}

void MainWindow::initializeSideBar()
{
    qDebug() << "initializeSideBar " << __LINE__;
    sidebar = new SideBar(this);
    ui->horizontalLayout->addWidget(sidebar);
    qDebug() << "__LINE__" << __LINE__;
//    for (int i = 0; i < 3; ++i)
//      widget_sidebar->addAction(QString("Action %1").arg(i),
//                                QIcon(QString(":/sidebar/Resources/icon%1").arg(i)));
}

void MainWindow::initializeNavigationPanel()
{
    qDebug() << "initializeNavigationPanel " << __LINE__;
    /*
     * Navigation panel consists of two parts mainly.
     * On to side -> an address bar which indicates the current directory location
     * view panel -> items on the address bar is shown here
     *
     */

    //    navigation_panel = new NavigationPanel(this); // will be added later
    navigation_panel = new QWidget(this);

    currentViewMode = ViewMode::IconView;
    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;

    QTableView * view_navigation = nullptr;
    navigation_panel = new QTableView();

    view_navigation = dynamic_cast<QTableView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));

//    ui->widget_navigation_panel

    dirmodel = new QFileSystemModel(this);

    QString current_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirmodel->setRootPath(current_location);
//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    view_navigation->setModel(dirmodel);


    // finally add the navigation panel
    ui->horizontalLayout->addWidget(navigation_panel);

}



void MainWindow::onTableClicked(const QModelIndex &index)
{
    qDebug() << "onTableClicked " << __LINE__;
    if (index.isValid()) {
        QString cellText = index.data().toString();
        qDebug() << cellText;
    }
}
