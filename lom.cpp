#include "lom.h"

lom::lom()
{

}

tochka* lom::get_mas()//геттер
{
    return mas;
}

void lom::set_mas(tochka *mas_points)//сеттеры
{
    mas = mas_points;
}

void lom::set_row(int n_row)
{
    row = n_row;
}

void lom::draw(QImage &im)
{
    QPainter painter(&im);

    QPen pen;
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

    QColor color;
    int r{},g{},b{},a{};
    my_pen.GetRGB(r,g,b,a);
    color.setRgb(r,g,b,a);
    pen.setColor(color);

    tochka * mas_points;
    mas_points = this->get_mas();
    QPainterPath path;
    path = QPainterPath();
    painter.setPen(pen);
    path.moveTo(mas_points[0].GetX(),mas_points[0].GetY());
    for (int i=1;i<row;i++)
    {
        path.lineTo(mas_points[i].GetX(),mas_points[i].GetY());
    }
    painter.drawPath(path);

}

