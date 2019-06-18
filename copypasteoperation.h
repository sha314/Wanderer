#ifndef COPYPASTEOPERATION_H
#define COPYPASTEOPERATION_H

#include <QWidget>

namespace Ui {
class CopyPasteOperation;
}

class CopyPasteOperation : public QWidget
{
    Q_OBJECT

public:
    explicit CopyPasteOperation(QWidget *parent = nullptr);
    ~CopyPasteOperation();

private:
    Ui::CopyPasteOperation *ui;
};

#endif // COPYPASTEOPERATION_H
