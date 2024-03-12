#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, object * mas, int row) :
    QDialog(parent),//конструтор
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->widget->create_im(ui->widget->width(),ui->widget->height());
    for (int i=0; i < row; i++)
    {
        int index = mas[i].get_index();
        switch (index)
        {
            case 0:
            {
                pixel pixel;
                pixel.SetXY(mas[i].GetX(), mas[i].GetY());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                pixel.my_pen.SetRGB(r,g,b,a);
                pixel.draw(ui->widget->im);
                break;
            }
            case 1:
            {
                line line;
                line.SetXY(mas[i].GetX(), mas[i].GetY());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                line.my_pen.SetRGB(r,g,b,a);
                line.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                line.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                int h,w;
                mas[i].GetHW(h,w);
                line.SetHW(h,w);
                line.draw(ui->widget->im);
                break;
            }
            case 2:
            {
                rectangle rectangle;
                rectangle.SetXY(mas[i].GetX(), mas[i].GetY());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                rectangle.my_pen.SetRGB(r,g,b,a);
                rectangle.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                rectangle.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                mas[i].my_brush.GetRGB(r,g,b,a);
                rectangle.my_brush.SetRGB(r,g,b,a);
                rectangle.my_brush.SetStyle(mas[i].my_brush.GetStyle());
                int h,w;
                mas[i].GetHW(h,w);
                rectangle.SetHW(h,w);
                rectangle.draw(ui->widget->im);
                break;
            }
            case 3:
            {
                ellipse ellipse;
                ellipse.SetXY(mas[i].GetX(), mas[i].GetY());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                ellipse.my_pen.SetRGB(r,g,b,a);
                ellipse.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                ellipse.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                mas[i].my_brush.GetRGB(r,g,b,a);
                ellipse.my_brush.SetRGB(r,g,b,a);
                ellipse.my_brush.SetStyle(mas[i].my_brush.GetStyle());
                int h,w;
                mas[i].GetHW(h,w);
                ellipse.SetHW(h,w);
                ellipse.draw(ui->widget->im);
                break;
            }
            case 4:
            {
                arc arc;
                arc.SetXY(mas[i].GetX(), mas[i].GetY());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                arc.my_pen.SetRGB(r,g,b,a);
                arc.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                arc.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                int h,w;
                mas[i].GetHW(h,w);
                int s,e;
                mas[i].GetSE(s,e);
                arc.SetSE(s,e);
                arc.SetHW(h,w);
                arc.draw(ui->widget->im);
                break;
            }
            case 5:
            {
                lom lom;
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                lom.my_pen.SetRGB(r,g,b,a);
                lom.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                lom.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                lom.set_mas(mas[i].get_mas());
                lom.set_row(mas[i].get_row());
                lom.draw(ui->widget->im);
                break;
            }
            case 6:
            {
                poly poly;
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                poly.my_pen.SetRGB(r,g,b,a);
                poly.my_pen.SetWidth(mas[i].my_pen.GetWidth());
                poly.my_pen.SetStyle(mas[i].my_pen.GetStyle());
                poly.set_mas(mas[i].get_mas());
                poly.set_row(mas[i].get_row());
                mas[i].my_brush.GetRGB(r,g,b,a);
                poly.my_brush.SetRGB(r,g,b,a);
                poly.my_brush.SetStyle(mas[i].my_brush.GetStyle());
                poly.draw(ui->widget->im);
                break;
            }
        }
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()//нажали закрыть
{
    close();
}
