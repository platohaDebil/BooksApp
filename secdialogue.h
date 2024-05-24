#ifndef SECDIALOGUE_H
#define SECDIALOGUE_H

#include <QDialog>
#include "supplementary.h"

namespace Ui {
class SecDialogue;
}

class SecDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialogue(QWidget *parent = nullptr);
    Book getFields() const;
    ~SecDialogue();

private:
    Ui::SecDialogue *ui;
};

#endif // SECDIALOGUE_H
