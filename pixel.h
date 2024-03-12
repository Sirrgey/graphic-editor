#ifndef PIXEL_H
#define PIXEL_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include <QImage>
#include <QPainter>

class pixel: public tochka
{
public:
    pixel(); //конструктор
    void draw(QImage &im); //рисуем изображение
    pen my_pen;
};

#endif // PIXEL_H
