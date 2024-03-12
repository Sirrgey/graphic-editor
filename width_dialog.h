#ifndef WIDTH_DIALOG_H
#define WIDTH_DIALOG_H

#include <QDialog>

namespace Ui {
class width_dialog;
}

class width_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit width_dialog(QWidget *parent = nullptr, int width_base = 3);
    ~width_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::width_dialog *ui;

signals:
    void export_width(int value);
};

#endif // WIDTH_DIALOG_H
