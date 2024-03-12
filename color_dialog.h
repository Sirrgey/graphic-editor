#ifndef COLOR_DIALOG_H
#define COLOR_DIALOG_H

#include <QDialog>

namespace Ui {
class color_dialog;
}

class color_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit color_dialog(QWidget *parent = nullptr,int r=0, int g=0, int b=0, int a=255);
    ~color_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::color_dialog *ui;

signals:
    void export_rgb(int, int , int, int);
};

#endif // COLOR_DIALOG_H
