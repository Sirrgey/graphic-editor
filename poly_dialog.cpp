#include "poly_dialog.h"
#include "ui_poly_dialog.h"


poly_dialog::poly_dialog(QWidget *parent, tochka* mas_points, int row_base, int index) :
    QDialog(parent),
    ui(new Ui::poly_dialog)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(row_base);
    ui->spinBox->setValue(row_base);
    ind = index;
    QSpinBox *my_sb;
    if(mas_points != nullptr)
    {
        for (int i=0;i < row_base; i++)
        {
            ui->tableWidget->setColumnWidth(i,96);
            my_sb = new QSpinBox; //выделили память
            my_sb->setValue(mas_points[i].GetX());
            my_sb->setRange(-2147483647,2147483647);
            ui->tableWidget->setCellWidget(i, 0, my_sb);
            my_sb = new QSpinBox; //выделили память
            my_sb->setValue(mas_points[i].GetY());
            my_sb->setRange(-2147483647,2147483647);
            ui->tableWidget->setCellWidget(i, 1, my_sb);
        }
    }

}

poly_dialog::~poly_dialog()
{
    delete ui;
}

void poly_dialog::on_spinBox_valueChanged(int arg1)//изменили значение спинбокса
{
    int old = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(arg1);
    QSpinBox *my_sb;
    for(int i = old; i< arg1; i++)
    {
       my_sb = new QSpinBox; //выделили память
       my_sb->setValue(0);
       my_sb->setRange(-2147483647,2147483647);
       ui->tableWidget->setCellWidget(i, 0, my_sb);
       my_sb = new QSpinBox; //выделили память
       my_sb->setValue(0);
       my_sb->setRange(-2147483647,2147483647);
       ui->tableWidget->setCellWidget(i, 1, my_sb);
    }
}

void poly_dialog::on_pushButton_add_clicked()//добавилис троку
{
    ui->spinBox->setValue(ui->spinBox->value()+1);
}

void poly_dialog::on_pushButton_del_clicked()//удалили строку
{
    ui->spinBox->setValue(ui->spinBox->value()-1);
}

void poly_dialog::on_pushButton_cancel_clicked()//отмена
{
    close();
}

void poly_dialog::on_pushButton_accept_clicked()//отправляем точки
{
    int row = ui->tableWidget->rowCount();
    tochka * mas;
    mas = new tochka[row];
    for(int i=0; i < row; i++)
    {
        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,0));
        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
        mas[i].SetXY(sp_x->value(),sp_y->value());
    }
    emit export_points(mas,row,ind);
    close();

}

