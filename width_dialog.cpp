#include "width_dialog.h"
#include "ui_width_dialog.h"

width_dialog::width_dialog(QWidget *parent, int width_base) :
    QDialog(parent),
    ui(new Ui::width_dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(width_base);
}

width_dialog::~width_dialog()
{
    delete ui;
}

void width_dialog::on_pushButton_clicked()//иморт ширины
{
    emit export_width(ui->spinBox->value());
    close();
}

void width_dialog::on_pushButton_2_clicked()//отмена
{
    close();
}
