#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include "settings.h"
#include "object.h"
#include <QSpinBox>
#include "poly_dialog.h"
#include "dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QCryptographicHash>

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
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_cellChanged();

    void on_pushButton_3_clicked();

protected slots:

    void onMyButClick();

    void onMyCbCurrentIndexChanged(int index);

    void import_obj(object obj, int index);

    void onPolyClick();

    void import_points(tochka* mas_im, int row, int ind);

private:
    Ui::MainWindow *ui;
    object *mas;
    bool change=false;
};

#endif // MAINWINDOW_H
