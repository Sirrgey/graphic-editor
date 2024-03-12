#include "rectangle.h"

rectangle::rectangle()
{

}

void rectangle::GetHW(int &h, int &w)//берем высоту и ширину
{
    h=height;
    w=width;
}

void rectangle::SetHW(int h, int w)//установили ширину и высоту
{
    height=h;
    width=w;
}

void rectangle::draw(QImage &im) //рисуем изображение
{
    QPainter painter(&im);
    QPen pen;
    QBrush brush;
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

    switch (my_brush.GetStyle())
    {
    case 1:
        brush.setStyle(Qt::SolidPattern);
        break;
    case 2:
        brush.setStyle(Qt::Dense1Pattern);
        break;
    case 3:
        brush.setStyle(Qt::Dense2Pattern);
        break;
    case 4:
        brush.setStyle(Qt::Dense3Pattern);
        break;
    case 5:
        brush.setStyle(Qt::Dense4Pattern);
        break;
    case 6:
        brush.setStyle(Qt::Dense5Pattern);
        break;
    case 7:
        brush.setStyle(Qt::Dense6Pattern);
        break;
    case 8:
        brush.setStyle(Qt::Dense7Pattern);
        break;
    case 9:
        brush.setStyle(Qt::NoBrush);
        break;
    case 10:
        brush.setStyle(Qt::HorPattern);
        break;
    case 11:
        brush.setStyle(Qt::VerPattern);
        break;
    case 12:
        brush.setStyle(Qt::CrossPattern);
        break;
    case 13:
        brush.setStyle(Qt::BDiagPattern);
        break;
    case 14:
        brush.setStyle(Qt::FDiagPattern);
        break;
    case 15:
        brush.setStyle(Qt::DiagCrossPattern);
        break;
    case 16:
        brush.setStyle(Qt::LinearGradientPattern);
        break;
    case 17:
        brush.setStyle(Qt::RadialGradientPattern);
        break;
    case 18:
        brush.setStyle(Qt::ConicalGradientPattern);
        break;
    default:
        break;
    }

    int r{},g{},b{},a{};
    my_pen.GetRGB(r,g,b,a);
    color.setRgb(r,g,b,a);
    pen.setColor(color);
    painter.setPen(pen);

    my_brush.GetRGB(r,g,b,a);
    color.setRgb(r,g,b,a);
    brush.setColor(color);
    painter.setBrush(brush);
    int width_rect,height_rect;

    this->GetHW(height_rect, width_rect);

    painter.drawRect(x, y, width_rect, height_rect);
}

