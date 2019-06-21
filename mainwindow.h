#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/sidebar/sidebar.h"

#include <QMainWindow>
#include <QFileSystemModel>

//#include <form/columnviewform.h>
//#include <form/listviewform.h>
//#include <form/iconviewform.h>
//#include <form/treeviewform.h>

#include <src/view/viewmodes.h>

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

private:
    Ui::MainWindow *ui;

    // added by shahnoor
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;

    QWidget *navigation_panel;
    QWidget *sidebar;

    ViewMode currentViewMode;


    QString current_location; // current file system location

    QList<int> column_widths;
    int max_column_width = 64*4;
    int min_column_width = 64*2;


    SideBar *widget_sidebar;

    void initializeSideBar(); // todo
    void initializeNavigationPanel();

};

#endif // MAINWINDOW_H
