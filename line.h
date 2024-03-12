#ifndef LINE_H
#define LINE_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include <QImage>
#include <QPainter>

class line : public tochka
{
public:
    line();
    void draw(QImage &im); //рисуем изображение
    void SetHW(int h, int w);
    void GetHW(int &h, int &w);
    pen my_pen;

protected:
    int width;
    int height;
};

#endif // LINE_H
