#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class ellipse : public tochka
{
public:
    ellipse();
    void draw(QImage &im); //рисуем изображение
    void SetHW(int h, int w);
    void GetHW(int &h, int &w);
    pen my_pen;
    brush my_brush;

protected:
    int width;
    int height;
};

#endif // ELLIPSE_H
