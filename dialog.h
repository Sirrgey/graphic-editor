#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include "object.h"
#include <pixel.h>
#include "rectangle.h"
#include "line.h"
#include "ellipse.h"
#include "arc.h"
#include "lom.h"
#include "poly.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, object * mas = nullptr, int row = 1);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
