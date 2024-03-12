#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "object.h"
#include "brush_style_dialog.h"
#include "width_dialog.h"
#include "pen_style_dialog.h"
#include <QColorDialog>
#include "color_dialog.h"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    void set_value(object obj, int i);
    ~settings();

private slots:
    void on_pushButton_brush_color_clicked();

    void on_pushButton_brush_style_clicked();

    void import_brush_style(int);

    void import_width(int);

    void import_pen_style(int);
    void on_pushButton_pen_color_clicked();

    void on_pushButton_pen_style_clicked();

    void on_pushButton_pen_width_clicked();

    void on_pushButton_clicked();

    void import_rgb_pen(int, int, int, int);

    void import_rgb_brush(int, int, int, int);

private:
    Ui::settings *ui;
    int rb{}, gb{}, bb{}, ab{255};
    int rp{}, gp{}, bp{}, ap{255};
    int style_brush=1;
    int style_pen=1;
    int width = 3;
    int index;
    QColor p_color,b_color;

signals:
    void export_obj(object, int);
};

#endif // SETTINGS_H
