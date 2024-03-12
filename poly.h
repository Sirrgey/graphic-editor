#ifndef POLY_H
#define POLY_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class poly
{
public:
    poly();
    void draw(QImage &im); //рисуем изображение
    pen my_pen;
    brush my_brush;
    void set_mas(tochka* mas_points);
    tochka* get_mas();
    void set_row(int n_row);
    int get_row();

protected:
    tochka * mas;
    int row;
};

#endif // POLY_H
