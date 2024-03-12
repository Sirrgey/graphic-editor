#include "pixel.h"

pixel::pixel()
{

}

void pixel::draw(QImage &im)//рисуем
{
    QPainter painter(&im);

    QPen pen;
    pen.setWidth(my_pen.GetWidth());

    switch (my_pen.GetStyle())
    {
    case 1:
        pen.setStyle(Qt::SolidLine);
        break;
    case 2:
        pen.setStyle(Qt::DashLine);
        break;
    case 3:
        pen.setStyle(Qt::DotLine);
        break;
    case 4:
        pen.setStyle(Qt::DashDotLine);
        break;
    case 5:
        pen.setStyle(Qt::DashDotDotLine);
        break;
    default:
        break;
    }

    QColor color;
    int r{},g{},b{},a{};
    my_pen.GetRGB(r,g,b,a);
    color.setRgb(r,g,b,a);
    pen.setColor(color);

    painter.setPen(pen);
    painter.drawPoint(x, y);
}
