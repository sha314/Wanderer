#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPrevious_triggered();

    void on_actionNext_triggered();

    void on_actionParent_triggered();

    void on_actionIconView_toggled(bool arg1);

    void on_actionListView_toggled(bool arg1);

    void on_actionColumnView_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
