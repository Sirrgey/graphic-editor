#ifndef POLY_DIALOG_H
#define POLY_DIALOG_H
#include "tochka.h"

#include <QDialog>
#include <QSpinBox>

namespace Ui {
class poly_dialog;
}

class poly_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit poly_dialog(QWidget *parent = nullptr,tochka* mas_points= nullptr, int row_base = 3, int index=5);
    ~poly_dialog();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_accept_clicked();


private:
    Ui::poly_dialog *ui;
    int ind;

signals:
    void export_points(tochka*, int, int);
};

#endif // POLY_DIALOG_H
