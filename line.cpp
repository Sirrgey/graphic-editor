#include "line.h"

line::line()
{

}

void line::GetHW(int &h, int &w)//забрали ширину и высоту
{
    h=height;
    w=width;
}

void line::SetHW(int h, int w)//установили ширину и высоту
{
    height=h;
    width=w;
}

void line::draw(QImage &im) //рисуем изображение
{
    QPainter painter(&im);
    QPen pen;
    QColor color;

    pen.setWidth(my_pen.GetWidth());

    switch (my_pen.GetStyle())
    {
    case 0:
        pen.setStyle(Qt::NoPen);
        break;
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


    int r{},g{},b{},a{};
    my_pen.GetRGB(r,g,b,a);
    color.setRgb(r,g,b,a);
    pen.setColor(color);
    painter.setPen(pen);


    int width_rect,height_rect;

    this->GetHW(width_rect, height_rect);

    painter.drawLine(x, y, width_rect, height_rect);
}
