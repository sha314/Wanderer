#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QFileSystemModel>
#include <QDirModel>
#include <QDebug>
#include <QStandardPaths>
#include <iostream>
#include <QTreeWidget>
#include <QColumnView>
#include <QTableView>
#include <QListView>


#include <src/view/viewmodes.h>
#include "src/sidebar/sidebar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void inforLayout();// information about the layout. to find bugs

private slots:
    void on_actionPrevious_triggered();
    void on_actionNext_triggered();
    void on_actionParent_triggered();


    void on_actionTreeView_triggered();
    void on_actionListView_triggered();
    void on_actionIconView_triggered();
    void on_actionColumnView_triggered();


    void onTableClicked(const QModelIndex &index);


    void model_directoryLoaded(QString path);
    void changeRoot(); // in case of icon view and list view
//    void expandTo(QString next); // in case of tree view

private:
    Ui::MainWindow *ui;

    // added by shahnoor
    QString default_location ;

    QFileSystemModel *file_system_model;
    QDirModel *dir_model;

    QWidget *navigation_panel;
    QWidget *sidebar;

    ViewMode currentViewMode;


    QString current_location; // current file system location

    QList<int> column_widths;
    int max_column_width = 64*4;
    int min_column_width = 64*2;


    SideBar *widget_sidebar;

    void setIconTheme();
    void initializeSideBar(); // todo
    void initializeNavigationPanel();

    // icon sizes
    int list_icon_size = 16*1;
    int table_icon_size = 16*3;

};

#endif // MAINWINDOW_H
