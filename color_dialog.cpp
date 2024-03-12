#include "color_dialog.h"
#include "ui_color_dialog.h"

color_dialog::color_dialog(QWidget *parent, int r, int g, int b, int a) :
    QDialog(parent),
    ui(new Ui::color_dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(r);
    ui->spinBox_2->setValue(g);
    ui->spinBox_3->setValue(b);
    ui->spinBox_4->setValue(a);

}

color_dialog::~color_dialog()
{
    delete ui;
}

void color_dialog::on_pushButton_clicked()//отправили цвет
{
    emit export_rgb(ui->spinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value(),ui->spinBox_4->value());
    close();
}


void color_dialog::on_pushButton_2_clicked()//отмена
{
    close();
}
