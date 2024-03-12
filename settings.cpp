#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

void settings::set_value(object obj, int i)//приянили значение из мейнвиндоу
{
    width = obj.my_pen.GetWidth();
    style_pen = obj.my_pen.GetStyle();
    style_brush = obj.my_brush.GetStyle();
    obj.my_pen.GetRGB(rp, gp, bp, ap);
    obj.my_brush.GetRGB(rb, gb, bb, ab);
    index = i;
    int figure = obj.get_index();
    if(figure == 0)
    {
        ui->pushButton_brush_color->hide();
        ui->pushButton_brush_style->hide();
        ui->pushButton_pen_style->hide();
        ui->pushButton_pen_width->hide();
        ui->label_brush->setEnabled(false);
    }
    if(figure == 1)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(false);
        ui->pushButton_brush_color->hide();
        ui->pushButton_brush_style->hide();
    }
    if(figure == 2)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(true);
        ui->pushButton_brush_color->show();
        ui->pushButton_brush_style->show();
    }
    if(figure == 3)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(true);
        ui->pushButton_brush_color->show();
        ui->pushButton_brush_style->show();
    }
    if(figure == 4)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(false);
        ui->pushButton_brush_color->hide();
        ui->pushButton_brush_style->hide();
    }
    if(figure == 5)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(false);
        ui->pushButton_brush_color->hide();
        ui->pushButton_brush_style->hide();
    }
    if(figure == 6)
    {
        ui->pushButton_pen_style->show();
        ui->pushButton_pen_width->show();
        ui->label_brush->setEnabled(true);
        ui->pushButton_brush_color->show();
        ui->pushButton_brush_style->show();
    }
//    if (style_pen ==0)
//    {
//        ui->pushButton_pen_width->hide();
//    }
//    else {
//        ui->pushButton_pen_width->show();
//    }
}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_brush_color_clicked()//изменили стиль кисти
{
    color_dialog * dialog = new color_dialog(this,rb,gb,bb,ab);

    connect(dialog,SIGNAL(export_rgb(int, int, int, int)),this,SLOT(import_rgb_brush(int, int, int, int)));

    dialog->exec();
}

void settings::import_rgb_pen(int r, int g, int b, int a)//импорт цвета ручки
{
    rp =r;
    gp = g;
    bp=b;
    ap=a;

}

void settings::import_rgb_brush(int r, int g, int b, int a)//импорт стиля кисти
{
    rb=r;
    gb=g;
    bb=b;
    ab=a;
}

void settings::on_pushButton_brush_style_clicked()//изменили стиль кисти
{
    brush_style_dialog * dialog = new brush_style_dialog(this, style_brush);

    connect(dialog,SIGNAL(export_style_brush(int)),this,SLOT(import_brush_style(int)));

    dialog->exec();
}

void settings::import_brush_style(int index)//импортируем стиль кисти
{
    style_brush = index;
}



void settings::on_pushButton_pen_color_clicked()//изменили цвет ручки
{
    color_dialog * dialog = new color_dialog(this,rp,gp,bp,ap);

    connect(dialog,SIGNAL(export_rgb(int, int, int, int)),this,SLOT(import_rgb_pen(int, int, int, int)));

    dialog->exec();
}

void settings::on_pushButton_pen_style_clicked()//изменили стиль ручки
{
    pen_style_dialog * dialog = new pen_style_dialog(this, style_pen);

    connect(dialog,SIGNAL(export_style_pen(int)),this,SLOT(import_pen_style(int)));

    dialog->exec();
}

void settings::on_pushButton_pen_width_clicked()//изменили ширину
{
    width_dialog * dialog = new width_dialog(this, width);

    connect(dialog,SIGNAL(export_width(int)),this,SLOT(import_width(int)));

    dialog->exec();
}

void settings::import_width(int index)//импортируем ширину
{
    width = index;
}

void settings::import_pen_style(int index)//импортируем стиль ручки
{
    style_pen = index;
//    if (index == 0)
//    {
//      ui->pushButton_pen_width->hide();
//    }
//    else {
//        ui->pushButton_pen_width->show();
//    }


}

void settings::on_pushButton_clicked()//сохранение настроек
{
    object obj;
    obj.my_pen.SetWidth(width);
    obj.my_pen.SetStyle(style_pen);
    obj.my_brush.SetStyle(style_brush);
    obj.my_pen.SetRGB(rp, gp, bp, ap);
    obj.my_brush.SetRGB(rb, gb, bb, ab);
    emit export_obj(obj,index);
    close();
}
