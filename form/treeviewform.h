#ifndef TREEVIEWFORM_H
#define TREEVIEWFORM_H

#include <QWidget>
#include <QFileSystemModel>

namespace Ui {
class TreeViewForm;
}

class TreeViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit TreeViewForm(QWidget *parent = nullptr);
    ~TreeViewForm();

private:
    Ui::TreeViewForm *ui;


    // added by shahnoor
    QFileSystemModel *dirmodel;
};

#endif // TREEVIEWFORM_H
