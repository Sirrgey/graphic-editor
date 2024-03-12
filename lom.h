#ifndef LOM_H
#define LOM_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include <QImage>
#include <QPainter>

class lom
{
public:
    lom();
    void draw(QImage &im); //рисуем изображение
    pen my_pen;
    void set_mas(tochka* mas_points);
    tochka* get_mas();
    void set_row(int n_row);
    int get_row();

protected:
    tochka * mas;
    int row;

};

#endif // LOM_H
