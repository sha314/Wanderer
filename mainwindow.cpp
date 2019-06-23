#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace  std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // added by shahnoor
    default_location = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    qDebug() << "__LINE__ " << __LINE__ ;

    qDebug() << QIcon::themeSearchPaths();

    setIconTheme();
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
    delete file_system_model;
    delete dir_model;
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

    file_system_model = new QFileSystemModel(this);

    QString current_location = default_location;

//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    view_navigation->setModel(file_system_model);
    file_system_model->setRootPath(current_location); // must be called after setModel is called
    view_navigation->setRootIndex(file_system_model->index(current_location));

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

    file_system_model = new QFileSystemModel(this);

    QString current_location = default_location;

//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    view_navigation->setModel(file_system_model);
    file_system_model->setRootPath(current_location); // must be called after setModel is called
    view_navigation->setRootIndex(file_system_model->index(current_location));


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

    file_system_model = new QFileSystemModel(this);

    QString current_location = default_location;

//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    view_navigation->setModel(file_system_model);
    file_system_model->setRootPath(current_location); // must be called after setModel is called
    view_navigation->setRootIndex(file_system_model->index(current_location));


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

    file_system_model = new QFileSystemModel(this);


    QString current_location = default_location;

//    dirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    view_navigation->setModel(file_system_model);
    file_system_model->setRootPath(current_location); // must be called after setModel is called
    view_navigation->setRootIndex(file_system_model->index(current_location));


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
//    sidebar = new SideBar(this);
//    ui->horizontalLayout->addWidget(sidebar);
    qDebug() << "__LINE__" << __LINE__;

    qDebug() << "/home/$USER/.config/gtk-3.0/bookmarks" ; // bookmarks

    QTreeWidget * tree = new QTreeWidget(this);
    tree->setHeaderHidden(true); // hide the header

    // top level
    QTreeWidgetItem *favorites = new QTreeWidgetItem();
    QTreeWidgetItem *devices = new QTreeWidgetItem();
    QTreeWidgetItem *network = new QTreeWidgetItem();

    qDebug() << "__LINE__" << __LINE__;
    // childrens
    QTreeWidgetItem *home = new QTreeWidgetItem();
    home->setText(0, "Home");
    home->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *desktop = new QTreeWidgetItem();
    desktop->setText(0, "Desktop");
    desktop->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *documents = new QTreeWidgetItem();
    documents->setText(0, "Documents");
    documents->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *music = new QTreeWidgetItem();
    music->setText(0, "Music");
    music->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *pictures = new QTreeWidgetItem();
    pictures->setText(0, "Pictures");
    pictures->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *videos = new QTreeWidgetItem();
    videos->setText(0, "Videos");
    videos->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *downloads = new QTreeWidgetItem();
    downloads->setText(0, "Downloads");
    downloads->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *filesystem = new QTreeWidgetItem();
    filesystem->setText(0, "Filesystem"); // the "/" directory in linux
    filesystem->setIcon(0, QIcon(":/icon/folder.png"));
    QTreeWidgetItem *trash = new QTreeWidgetItem();
    trash->setText(0, "Trash");
    trash->setIcon(0, QIcon(":/icon/folder.png"));

    qDebug() << "__LINE__" << __LINE__;

    favorites->setText(0, "Favorites");
    favorites->setIcon(0, QIcon(":/icon/folder.png"));
    favorites->addChild(home);
    favorites->addChild(desktop);
    favorites->addChild(documents);
    favorites->addChild(music);
    favorites->addChild(pictures);
    favorites->addChild(videos);
    favorites->addChild(downloads);
    favorites->addChild(filesystem);
    favorites->addChild(trash);

    qDebug() << "__LINE__" << __LINE__;

    devices->setText(0, "Devices");
    devices->setIcon(0, QIcon(":/icon/folder.png"));
    network->setText(0, "Network");
    network->setIcon(0, QIcon(":/icon/folder.png"));


    qDebug() << "__LINE__" << __LINE__;


    tree->addTopLevelItem(favorites);
    tree->addTopLevelItem(devices);
    tree->addTopLevelItem(network);

    qDebug() << "__LINE__" << __LINE__;
    tree->expandAll();

    qDebug() << "__LINE__" << __LINE__;


    tree->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding); // x axis fixed

    ui->horizontalLayout->addWidget(tree);
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

    currentViewMode = ViewMode::TreeView;
    // add and remove widget in layout
    qDebug() << " add and remove widget in layout " << __LINE__ ;

    QTreeView * view_navigation = nullptr;
    navigation_panel = new QTreeView();

    view_navigation = dynamic_cast<QTreeView*> (navigation_panel);
    qDebug() << "__LINE__" << __LINE__;
    view_navigation->setObjectName(QString::fromUtf8("iconView"));


    file_system_model = new QFileSystemModel(this);

    QString current_location = default_location;

    QModelIndex index = file_system_model->index(current_location);
    if(index.isValid()){
        qDebug() << "valid index";
    }else{
        qDebug() << "Invalid index";
    }
    qDebug() << index.data();

//    view_navigation->setCurrentIndex(file_system_model->index(0, 0, view_navigation->rootIndex()));

//    file_system_model->setReadOnly(false); // read write is enabled


    view_navigation->expand(index);
    view_navigation->scrollTo(index);
    view_navigation->setCurrentIndex(index);

    view_navigation->resizeColumnToContents(0);

    QModelIndex current_index = view_navigation->currentIndex();
    qDebug() << "view_navigation->currentIndex() " << current_index.data();
    if(current_index.isValid()){
        qDebug() << "valid index";
    }else{
        qDebug() << "Invalid index";
    }

    view_navigation->setModel(file_system_model);
    file_system_model->setRootPath(current_location); // must be called after setModel is called
    view_navigation->setRootIndex(file_system_model->index(current_location));

//    file_system_model->setRootPath(current_location);
//    view_navigation->setRootIndex(file_system_model->index(current_location));


    // monitoring clicks on item
    connect(view_navigation, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

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

void MainWindow::setIconTheme()
{
    qDebug() << "setIconTheme : " << __LINE__;

//    if (QIcon::hasThemeIcon("document-open"))
//            ui->action_Open->setIcon(QIcon::fromTheme("document-open"));
//    if (QIcon::hasThemeIcon("document-save-as"))
//        ui->action_Convert->setIcon(QIcon::fromTheme("document-save-as"));
//    if (QIcon::hasThemeIcon("application-exit"))
//        ui->action_Quit->setIcon(QIcon::fromTheme("application-exit"));
}
