#include "brush_style_dialog.h"
#include "ui_brush_style_dialog.h"

brush_style_dialog::brush_style_dialog(QWidget *parent, int style) :
    QDialog(parent),
    ui(new Ui::brush_style_dialog)
{
    ui->setupUi(this);

    ui->radioButton_2->setIcon(QIcon("..//15//img//brush2.png"));
    ui->radioButton_3->setIcon(QIcon("..//15//img//brush3.png"));
    ui->radioButton_4->setIcon(QIcon("..//15//img//brush4.png"));
    ui->radioButton_5->setIcon(QIcon("..//15//img//brush5.png"));
    ui->radioButton_6->setIcon(QIcon("..//15//img//brush6.png"));
    ui->radioButton_7->setIcon(QIcon("..//15//img//brush7.png"));
    ui->radioButton_8->setIcon(QIcon("..//15//img//brush8.png"));
    ui->radioButton_10->setIcon(QIcon("..//15//img//brush10.png"));
    ui->radioButton_11->setIcon(QIcon("..//15//img//brush11.png"));
    ui->radioButton_12->setIcon(QIcon("..//15//img//brush12.png"));
    ui->radioButton_13->setIcon(QIcon("..//15//img//brush13.png"));
    ui->radioButton_14->setIcon(QIcon("..//15//img//brush14.png"));
    ui->radioButton_15->setIcon(QIcon("..//15//img//brush15.png"));
    switch(style)
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
        case 7:
        {
            ui->radioButton_7->setChecked(true);
            break;
        }
        case 8:
        {
            ui->radioButton_8->setChecked(true);
            break;
        }
        case 10:
        {
            ui->radioButton_10->setChecked(true);
            break;
        }
        case 11:
        {
            ui->radioButton_11->setChecked(true);
            break;
        }
        case 12:
        {
            ui->radioButton_12->setChecked(true);
            break;
        }
        case 13:
        {
            ui->radioButton_13->setChecked(true);
            break;
        }
        case 14:
        {
            ui->radioButton_14->setChecked(true);
            break;
        }
        case 15:
        {
            ui->radioButton_15->setChecked(true);
            break;
        }
    }

}

brush_style_dialog::~brush_style_dialog()
{
    delete ui;
}

void brush_style_dialog::on_pushButton_clicked()//отправили стиль
{
    if (ui->radioButton_1->isChecked())
    {
        emit export_style_brush(0);
    }
    if (ui->radioButton_2->isChecked())
    {
        emit export_style_brush(2);
    }
    if (ui->radioButton_3->isChecked())
    {
        emit export_style_brush(3);
    }

    if (ui->radioButton_4->isChecked())
    {
        emit export_style_brush(4);
    }
    if (ui->radioButton_5->isChecked())
    {
        emit export_style_brush(5);
    }
    if (ui->radioButton_6->isChecked())
    {
        emit export_style_brush(6);
    }
    if (ui->radioButton_7->isChecked())
    {
        emit export_style_brush(7);
    }
    if (ui->radioButton_8->isChecked())
    {
        emit export_style_brush(8);
    }
    if (ui->radioButton_10->isChecked())
    {
        emit export_style_brush(10);
    }
    if (ui->radioButton_11->isChecked())
    {
        emit export_style_brush(11);
    }
    if (ui->radioButton_12->isChecked())
    {
        emit export_style_brush(12);
    }
    if (ui->radioButton_13->isChecked())
    {
        emit export_style_brush(13);
    }
    if (ui->radioButton_14->isChecked())
    {
        emit export_style_brush(14);
    }
    if (ui->radioButton_15->isChecked())
    {
        emit export_style_brush(15);
    }
    close();

}

void brush_style_dialog::on_pushButton_2_clicked()//просто закрыли
{
    close();
}
