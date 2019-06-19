#ifndef COLUMNVIEWFORM_H
#define COLUMNVIEWFORM_H

#include <QFileSystemModel>
#include <QWidget>

namespace Ui {
class ColumnViewForm;
}

class ColumnViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit ColumnViewForm(QWidget *parent = nullptr);
    ~ColumnViewForm();

private slots:
    void on_columnView_clicked(const QModelIndex &index);

private:
    Ui::ColumnViewForm *ui;
    QFileSystemModel * dirmodel;

    QString current_location;

    QList<int> column_widths;
    int max_column_width = 64*4;
    int min_column_width = 64*2;
};

#endif // COLUMNVIEWFORM_H
