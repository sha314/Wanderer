#ifndef ICONVIEWFORM_H
#define ICONVIEWFORM_H

#include <QWidget>

namespace Ui {
class IconViewForm;
}

class IconViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit IconViewForm(QWidget *parent = nullptr);
    ~IconViewForm();

private:
    Ui::IconViewForm *ui;
};

#endif // ICONVIEWFORM_H
