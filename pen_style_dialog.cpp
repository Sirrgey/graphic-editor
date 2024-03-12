#include "pen_style_dialog.h"
#include "ui_pen_style_dialog.h"

pen_style_dialog::pen_style_dialog(QWidget *parent, int style_base) :
    QDialog(parent),
    ui(new Ui::pen_style_dialog)
{
    ui->setupUi(this);

    ui->radioButton_2->setIcon(QIcon("..//15//img//pen2.png"));
    ui->radioButton_3->setIcon(QIcon("..//15//img//pen3.png"));
    ui->radioButton_4->setIcon(QIcon("..//15//img//pen4.png"));
    ui->radioButton_5->setIcon(QIcon("..//15//img//pen5.png"));
    ui->radioButton_6->setIcon(QIcon("..//15//img//pen6.png"));

    switch(style_base)
    {
        case 1:
        {
            ui->radioButton_1->setChecked(true);
            break;
        }
        case 2:
        {
            ui->radioButton_2->setChecked(true);
            break;
        }
        case 3:
        {
            ui->radioButton_3->setChecked(true);
            break;
        }
        case 4:
        {
            ui->radioButton_4->setChecked(true);
            break;
        }
        case 5:
        {
            ui->radioButton_5->setChecked(true);
            break;
        }
        case 6:
        {
            ui->radioButton_6->setChecked(true);
            break;
        }
    }
}

pen_style_dialog::~pen_style_dialog()
{
    delete ui;
}

void pen_style_dialog::on_pushButton_clicked()//отдали стиль
{
    if (ui->radioButton_1->isChecked())
    {
        emit export_style_pen(0);
    }
    if (ui->radioButton_2->isChecked())
    {
        emit export_style_pen(2);
    }
    if (ui->radioButton_3->isChecked())
    {
        emit export_style_pen(3);
    }

    if (ui->radioButton_4->isChecked())
    {
        emit export_style_pen(4);
    }
    if (ui->radioButton_5->isChecked())
    {
        emit export_style_pen(5);
    }
    if (ui->radioButton_6->isChecked())
    {
        emit export_style_pen(6);
    }

    close();
}

void pen_style_dialog::on_pushButton_2_clicked()//закрыли
{
    close();
}
