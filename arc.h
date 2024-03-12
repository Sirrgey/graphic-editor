#ifndef ARC_H
#define ARC_H


#include "tochka.h"
#include "color.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class arc : public tochka
{
public:
    arc();
    void draw(QImage &im); //рисуем изображение
    void SetHW(int h, int w);
    void GetHW(int &h, int &w);
    void SetSE(int s, int e);
    pen my_pen;
    brush my_brush;

protected:
    int width;
    int height;
    int start;
    int end;
};

#endif // ARC_H
