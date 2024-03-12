#ifndef BRUSH_STYLE_DIALOG_H
#define BRUSH_STYLE_DIALOG_H

#include <QDialog>

namespace Ui {
class brush_style_dialog;
}

class brush_style_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit brush_style_dialog(QWidget *parent = nullptr, int style = 1);
    ~brush_style_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::brush_style_dialog *ui;

signals:
    void export_style_brush(int index);
};

#endif // BRUSH_STYLE_DIALOG_H
