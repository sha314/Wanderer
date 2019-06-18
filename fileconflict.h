#ifndef FILECONFLICT_H
#define FILECONFLICT_H

#include <QWidget>

namespace Ui {
class FileConflict;
}

class FileConflict : public QWidget
{
    Q_OBJECT

public:
    explicit FileConflict(QWidget *parent = nullptr);
    ~FileConflict();

private:
    Ui::FileConflict *ui;
};

#endif // FILECONFLICT_H
