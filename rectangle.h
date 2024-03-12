#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class rectangle : public tochka
{
public:
    rectangle(); //конструктор
    void draw(QImage &im); //рисуем изображение
    void SetHW(int h, int w);
    void GetHW(int &h, int &w);
    pen my_pen;
    brush my_brush;

protected:
    int width;
    int height;
};

#endif // RECTANGLE_H
