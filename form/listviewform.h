#ifndef LISTVIEWFORM_H
#define LISTVIEWFORM_H

#include <QWidget>
#include <QFileSystemModel>


namespace Ui {
class ListViewForm;
}

class ListViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListViewForm(QWidget *parent = nullptr);
    ~ListViewForm();

private:
    Ui::ListViewForm *ui;

    // added by shahnoor
    QFileSystemModel *dirmodel;
};

#endif // LISTVIEWFORM_H
