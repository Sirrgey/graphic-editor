#ifndef PEN_STYLE_DIALOG_H
#define PEN_STYLE_DIALOG_H

#include <QDialog>

namespace Ui {
class pen_style_dialog;
}

class pen_style_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit pen_style_dialog(QWidget *parent = nullptr, int style_base = 1);
    ~pen_style_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pen_style_dialog *ui;

signals:
    void export_style_pen(int index);
};

#endif // PEN_STYLE_DIALOG_H
