#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    setWindowTitle("Графический редактор");

    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();

    for (int i=0;i<8;i++)
    {
        ui->tableWidget->setColumnWidth(i,130);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)//изменили кол-во строк
{
    change = false;
    int ex_row = arg1 * 2;
    int old = ui->tableWidget->rowCount();
    QTableWidgetItem * ti; //создали указатель
    QSpinBox *my_sb;
    ui->tableWidget->setRowCount(ex_row);
    old=old/2;
    if(old>arg1)
    {
        object *mas_tmp;
        mas_tmp = new object[arg1];
        for(int i=0;i<arg1;i++)
        {
            mas_tmp[i].set_mas(mas[i].get_mas());
            mas_tmp[i].set_index(mas[i].get_index());
            mas_tmp[i].my_pen.SetStyle(mas[i].my_pen.GetStyle());
            mas_tmp[i].my_pen.SetWidth(mas[i].my_pen.GetWidth());
            mas_tmp[i].my_brush.SetStyle(mas[i].my_brush.GetStyle());
            int r,g,b,a;
            mas[i].my_pen.GetRGB(r,g,b,a);
            mas_tmp[i].my_pen.SetRGB(r,g,b,a);
            mas[i].my_brush.GetRGB(r,g,b,a);
            mas_tmp[i].my_brush.SetRGB(r,g,b,a);
            mas_tmp[i].set_row(mas[i].get_row());
        }
        mas = new object[arg1];
        for (int i = 0; i<arg1; i++)
        {
            mas[i].set_mas(mas_tmp[i].get_mas());
            mas[i].set_index(mas_tmp[i].get_index());
            mas[i].my_pen.SetStyle(mas_tmp[i].my_pen.GetStyle());
            mas[i].my_pen.SetWidth(mas_tmp[i].my_pen.GetWidth());
            mas[i].my_brush.SetStyle(mas_tmp[i].my_brush.GetStyle());
            int r,g,b,a;
            mas_tmp[i].my_pen.GetRGB(r,g,b,a);
            mas[i].my_pen.SetRGB(r,g,b,a);
            mas_tmp[i].my_brush.GetRGB(r,g,b,a);
            mas[i].my_brush.SetRGB(r,g,b,a);
        }
        delete [] mas_tmp;
        mas_tmp = nullptr;
    }
    else
    {
        if(old==0)
        {
            mas = new object[arg1];
            for (int i=0; i < arg1; i++)
            {
                mas[i].my_pen.SetStyle(1);
                mas[i].set_index(0);
                mas[i].my_brush.SetStyle(1);
                mas[i].my_pen.SetWidth(3);
                mas[i].my_pen.SetRGB(0,0,0,255);
                mas[i].my_brush.SetRGB(0,0,0,255);
                tochka * tmp = new tochka[3];
                for (int j=0;j<3;j++)
                {
                    tmp[j].SetXY(0,0);
                }
                mas[i].set_mas(tmp);
                mas[i].set_row(3);
            }
        }
        else
        {
            object *mas_tmp;
            mas_tmp = new object[old];
            for(int i=0;i<old;i++)
            {
                mas_tmp[i].set_mas(mas[i].get_mas());
                mas_tmp[i].set_index(mas[i].get_index());
                mas_tmp[i].my_pen.SetStyle(mas[i].my_pen.GetStyle());
                mas_tmp[i].my_pen.SetWidth(mas[i].my_pen.GetWidth());
                mas_tmp[i].my_brush.SetStyle(mas[i].my_brush.GetStyle());
                int r,g,b,a;
                mas[i].my_pen.GetRGB(r,g,b,a);
                mas_tmp[i].my_pen.SetRGB(r,g,b,a);
                mas[i].my_brush.GetRGB(r,g,b,a);
                mas_tmp[i].my_brush.SetRGB(r,g,b,a);
                mas_tmp[i].set_row(mas[i].get_row());
            }
            mas = new object[arg1];
            for (int i=0; i < arg1; i++)
            {
                mas[i].my_pen.SetStyle(1);
                mas[i].set_index(0);
                mas[i].my_brush.SetStyle(1);
                mas[i].my_pen.SetWidth(3);
                mas[i].my_pen.SetRGB(0,0,0,255);
                mas[i].my_brush.SetRGB(0,0,0,255);
                tochka * tmp = new tochka[3];
                for (int j=0;j<3;j++)
                {
                    tmp[j].SetXY(0,0);
                }
                mas[i].set_mas(tmp);
                mas[i].set_row(3);
            }
            for (int i = 0; i<old; i++)
            {
                mas[i].set_mas(mas_tmp[i].get_mas());
                mas[i].set_index(mas_tmp[i].get_index());
                mas[i].my_pen.SetStyle(mas_tmp[i].my_pen.GetStyle());
                mas[i].my_pen.SetWidth(mas_tmp[i].my_pen.GetWidth());
                mas[i].my_brush.SetStyle(mas_tmp[i].my_brush.GetStyle());
                int r,g,b,a;
                mas_tmp[i].my_pen.GetRGB(r,g,b,a);
                mas[i].my_pen.SetRGB(r,g,b,a);
                mas_tmp[i].my_brush.GetRGB(r,g,b,a);
                mas[i].my_brush.SetRGB(r,g,b,a);
            }
            delete [] mas_tmp;
            mas_tmp = nullptr;
        }
    }
    old*=2;

    for (int i=old; i < ex_row; i+=2)
    {
        //вернхняя
        ti = new QTableWidgetItem; //выделили память
        ti->setFlags(ti->flags()&0xfffffffd);
        ti->setText("Фигура");
        ui->tableWidget->setItem(i, 0, ti); //поместили ячейку в таблицу

        //нижняя
        //создаем комбо бокс
        QComboBox *my_cb;
        my_cb = new QComboBox;
        my_cb->addItem("Точка");
        my_cb->addItem("Линии");
        my_cb->addItem("Прямоугольник");
        my_cb->addItem("Эллипс");
        my_cb->addItem("Дуга");
        my_cb->addItem("Ломаная");
        my_cb->addItem("Полигон");
        my_cb->setProperty("row",i);

        //ловим событие смены позиций в комбобоксе
        connect(my_cb,SIGNAL(currentIndexChanged(int)),this,SLOT(onMyCbCurrentIndexChanged(int)));
        connect(my_cb,SIGNAL(activated(int)),this,SLOT(onMyCbCurrentIndexChanged(int)));

        ui->tableWidget->setCellWidget(i+1, 0, my_cb);

        //вернхняя
        ti = new QTableWidgetItem; //выделили память
        ti->setFlags(ti->flags()&0xfffffffd);
        ti->setText("X");
        ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

        //нижняя
        my_sb = new QSpinBox; //выделили память
        my_sb->setValue(0);
        my_sb->setRange(-2147483647,2147483647);
        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


        //вернхняя
        ti = new QTableWidgetItem; //выделили память
        ti->setFlags(ti->flags()&0xfffffffd);
        ti->setText("Y");
        ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

        //нижняя
        my_sb = new QSpinBox; //выделили память
        my_sb->setValue(0);
        my_sb->setRange(-2147483647,2147483647);
        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу


        //вернхняя
        ti = new QTableWidgetItem; //выделили память
        ti->setFlags(ti->flags()&0xfffffffd);
        ti->setText("Настройки");
        ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

        //нижняя + создаем кнопку
        QPushButton *my_but;
        my_but = new QPushButton;
        my_but->setText("Изменить");
        my_but->setProperty("row",i/2);
        //ловим событие нажатия кнопки
        connect(my_but,SIGNAL(clicked()),this,SLOT(onMyButClick()));
        ui->tableWidget->setCellWidget(i+1, 3, my_but);

        for (int j = 4 ; j < 8; j++)
        {
            //нижняя
            ti = new QTableWidgetItem; //выделили память
            ti->setFlags(ti->flags()&0xfffffffd);
            ti->setText("--");

            ui->tableWidget->setItem(i, j, ti);//верхняя
            ti = new QTableWidgetItem; //выделили память
            ti->setFlags(ti->flags()&0xfffffffd);
            ti->setText("--");
            ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
        }
    }
}

void MainWindow::onMyCbCurrentIndexChanged(int index)//изменили комбобокс в таблице
{
    QComboBox *cb_s = qobject_cast<QComboBox*>(sender());
    QPushButton *my_but;
    my_but = new QPushButton;
    //ловим событие нажатия кнопки
    int i = cb_s->property("row").toInt();
    mas[i/2].set_index(index);
    my_but->setProperty("row",i/2);
    connect(my_but,SIGNAL(clicked()),this,SLOT(onMyButClick()));
    QTableWidgetItem * ti; //создали указатель
    QSpinBox *my_sb;
    if (cb_s != nullptr)
    {
        switch(index)
        {
            case 0:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 3);
                ui->tableWidget->setCellWidget(i+1, 3, my_but);

                for (int j = 4 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }

                break;

            }
            case 1:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X1");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y1");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X2");
                ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 3);
                ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y2");
                ui->tableWidget->setItem(i, 4, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 4);
                ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 5, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 5);
                ui->tableWidget->setCellWidget(i+1, 5, my_but);

                for (int j = 6 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }
                break;

            }
            case 2:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Длина(Y)");
                ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 3);
                ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Ширина(X)");
                ui->tableWidget->setItem(i, 4, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 4);
                ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 5, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 5);
                ui->tableWidget->setCellWidget(i+1, 5, my_but);

                for (int j = 6 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }
                break;

            }
            case 3:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Полуось(Y)");
                ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(1,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 3);
                ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Полуось(X)");
                ui->tableWidget->setItem(i, 4, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(1,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 4);
                ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 5, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 5);
                ui->tableWidget->setCellWidget(i+1, 5, my_but);

                for (int j = 6 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }
                break;

            }
            case 4:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("X");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Y");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-2147483647,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Полуось(Y)");
                ui->tableWidget->setItem(i, 3, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(1,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 3);
                ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Полуось(X)");
                ui->tableWidget->setItem(i, 4, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(1,2147483647);
                ui->tableWidget->removeCellWidget(i+1, 4);
                ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Начало дуги,°");
                ui->tableWidget->setItem(i, 5, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-359,359);
                ui->tableWidget->removeCellWidget(i+1, 5);
                ui->tableWidget->setCellWidget(i+1, 5, my_sb); //сбшник ячейку в таблицу


                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Угловая длина,°");
                ui->tableWidget->setItem(i, 6, ti); //поместили ячейку в таблицу

                //нижняя
                my_sb = new QSpinBox; //выделили память
                my_sb->setValue(0);
                my_sb->setRange(-360,360);
                ui->tableWidget->removeCellWidget(i+1, 6);
                ui->tableWidget->setCellWidget(i+1, 6, my_sb); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 7, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 7);
                ui->tableWidget->setCellWidget(i+1, 7, my_but);
                break;
            }
            case 5:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Задать точки");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                QPushButton *but_poly;
                but_poly = new QPushButton;
                but_poly->setProperty("row",i/2);
                connect(but_poly,SIGNAL(clicked()),this,SLOT(onPolyClick()));
                but_poly->setText("Задать");
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, but_poly); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_but);

                for (int j = 3 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }

                break;

            }
            case 6:
            {
                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Задать точки");
                ui->tableWidget->setItem(i, 1, ti); //поместили ячейку в таблицу

                //нижняя
                QPushButton *but_poly;
                but_poly = new QPushButton;
                but_poly->setProperty("row",i/2);
                connect(but_poly,SIGNAL(clicked()),this,SLOT(onPolyClick()));
                but_poly->setText("Задать");
                ui->tableWidget->removeCellWidget(i+1, 1);
                ui->tableWidget->setCellWidget(i+1, 1, but_poly); //сбшник ячейку в таблицу

                //вернхняя
                ti = new QTableWidgetItem; //выделили память
                ti->setFlags(ti->flags()&0xfffffffd);
                ti->setText("Настройки");
                ui->tableWidget->setItem(i, 2, ti); //поместили ячейку в таблицу

                //нижняя
                my_but->setText("Изменить");
                ui->tableWidget->removeCellWidget(i+1, 2);
                ui->tableWidget->setCellWidget(i+1, 2, my_but);

                for (int j = 3 ; j < 8; j++)
                {
                    //нижняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->setItem(i, j, ti);//верхняя
                    ti = new QTableWidgetItem; //выделили память
                    ti->setFlags(ti->flags()&0xfffffffd);
                    ti->setText("--");
                    ui->tableWidget->removeCellWidget(i+1, j);
                    ui->tableWidget->setItem(i+1, j, ti);//поместили ячейку в таблицу //нижняя
                }
                break;

            }
        }
    }
}

void MainWindow::onMyButClick()//открыли настройки
{
    QPushButton *but_s = qobject_cast<QPushButton*>(sender());
    int i = but_s->property("row").toInt();
    object obj;
    obj = mas[i];
    settings * dialog = new settings();

    dialog->set_value(obj,i);
    connect(dialog,SIGNAL(export_obj(object, int)),this,SLOT(import_obj(object, int)));

    dialog->exec();
}

void MainWindow::import_obj(object obj, int index)//импорт объекта из настроек
{
    int r,g,b,a;
    obj.my_pen.GetRGB(r,g,b,a);
    mas[index].my_pen.SetStyle(obj.my_pen.GetStyle());
    mas[index].my_pen.SetWidth(obj.my_pen.GetWidth());
    mas[index].my_pen.SetRGB(r,g,b,a);
    obj.my_brush.GetRGB(r,g,b,a);
    mas[index].my_brush.SetRGB(r,g,b,a);
    mas[index].my_brush.SetStyle(obj.my_brush.GetStyle());
}

void MainWindow::onPolyClick()//открыли задание точек для ломанной или полигона
{
    QPushButton *but_s = qobject_cast<QPushButton*>(sender());
    int i = but_s->property("row").toInt();
    object obj;
    obj = mas[i];
    tochka *mas_send;
    mas_send = obj.get_mas();
    int row = obj.get_row();
    poly_dialog * dialog = new poly_dialog(this, mas_send, row, i);
    connect(dialog,SIGNAL(export_points(tochka*, int, int)),this,SLOT(import_points(tochka*, int, int)));
    dialog->exec();
}

void MainWindow::import_points(tochka* mas_im, int row, int ind)//импортируем точки и их кол-во а также номер строки
{
    mas[ind].set_mas(mas_im);
    mas[ind].set_row(row);
}

void MainWindow::on_pushButton_clicked()//кнопка рисовать
{
    int row = ui->spinBox->value();
    int figure = 0;
    int j=0;
    for(int i=1; i<row*2; i+=2)
    {
        QComboBox *cb = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(i,0));
        figure = cb->currentIndex();
        switch (figure)
        {
            case 0:
            {
                QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                mas[j].SetXY(sp_x->value(),sp_y->value());
                mas[j].set_index(0);
                break;
            }
            case 1:
            {
                QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                mas[j].SetXY(sp_x->value(),sp_y->value());
                mas[j].SetHW(sp_h->value(), sp_w->value());
                mas[j].set_index(1);
                break;
            }
            case 2:
            {
                QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                mas[j].SetXY(sp_x->value(),sp_y->value());
                mas[j].SetHW(sp_h->value(), sp_w->value());
                mas[j].set_index(2);
                break;
            }
            case 3:
            {
                QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                mas[j].SetXY(sp_x->value(),sp_y->value());
                mas[j].SetHW(sp_h->value(), sp_w->value());
                mas[j].set_index(3);
                break;
            }
            case 4:
            {
                QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                QSpinBox *sp_s = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,5));
                QSpinBox *sp_e = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,6));
                mas[j].SetXY(sp_x->value(),sp_y->value());
                mas[j].SetHW(sp_h->value(), sp_w->value());
                mas[j].SetSE(sp_s->value(), sp_e->value());
                mas[j].set_index(4);
                break;
            }
            case 5:
            {
                mas[j].set_index(5);
                break;
            }
            case 6:
            {
                mas[j].set_index(6);
                break;
            }
        }
        j++;
    }
    change = true;
    Dialog * dialog_win = new Dialog(this,mas,j);
    dialog_win->exec();

}

void MainWindow::on_pushButton_2_clicked()//кнопка сохранить
{
    int row = ui->spinBox->value();
    if(row==0)
    {
        QMessageBox::information(this,"Ошибка","Нельзя сохранять пустой файл",QMessageBox::Ok);
    }
    else
    {
        if(!change)
        {
            int figure = 0;
            int j=0;
            for(int i=1; i<row*2; i+=2)
            {
                QComboBox *cb = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(i,0));
                figure = cb->currentIndex();
                switch (figure)
                {
                    case 0:
                    {
                        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                        mas[j].SetXY(sp_x->value(),sp_y->value());
                        mas[j].set_index(0);
                        break;
                    }
                    case 1:
                    {
                        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                        QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                        QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                        mas[j].SetXY(sp_x->value(),sp_y->value());
                        mas[j].SetHW(sp_h->value(), sp_w->value());
                        mas[j].set_index(1);
                        break;
                    }
                    case 2:
                    {
                        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                        QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                        QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                        mas[j].SetXY(sp_x->value(),sp_y->value());
                        mas[j].SetHW(sp_h->value(), sp_w->value());
                        mas[j].set_index(2);
                        break;
                    }
                    case 3:
                    {
                        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                        QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                        QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                        mas[j].SetXY(sp_x->value(),sp_y->value());
                        mas[j].SetHW(sp_h->value(), sp_w->value());
                        mas[j].set_index(3);
                        break;
                    }
                    case 4:
                    {
                        QSpinBox *sp_x = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,1));
                        QSpinBox *sp_y = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,2));
                        QSpinBox *sp_h = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,3));
                        QSpinBox *sp_w = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,4));
                        QSpinBox *sp_s = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,5));
                        QSpinBox *sp_e = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,6));
                        mas[j].SetXY(sp_x->value(),sp_y->value());
                        mas[j].SetHW(sp_h->value(), sp_w->value());
                        mas[j].SetSE(sp_s->value(), sp_e->value());
                        mas[j].set_index(4);
                        break;
                    }
                    case 5:
                    {
                        mas[j].set_index(5);
                        break;
                    }
                    case 6:
                    {
                        mas[j].set_index(6);
                        break;
                    }
                }
                j++;
            }
        }
        QString fileName;
        fileName = QFileDialog::getSaveFileName(this,tr("Сохранить файл в BIN"),"C:\\Users\\student\\Documents",tr("Binary file (*.bin)"));

        if(fileName.isEmpty())//выбран ли файл
        {//не выбран
            QMessageBox::information(this,"Ошибка","Файл не выбран",QMessageBox::Ok);
        }
        else
        {
            QFile file;
            file.setFileName(fileName);
            file.open(QIODevice::WriteOnly);
            char * mas_ch;
            int size_int = sizeof (int);
            mas_ch = new char[size_int];
            //считаем размер файла
            int size=0;
            memcpy(mas_ch,&row,size_t(size_int));
            file.write(mas_ch,size_int);
            for (int i=0; i < row; i++)
            {
                switch(mas[i].get_index())
                {
                    case 0:
                    {
                        size+=7;
                        break;
                    }
                    case 1:
                    {
                        size+=11;
                        break;
                    }
                    case 2:
                    {
                        size+=16;
                        break;
                    }
                    case 3:
                    {
                        size+=16;
                        break;
                    }
                    case 4:
                    {
                        size+=13;
                        break;
                    }
                    case 5:
                    {
                        size=size + 8 + 2*mas[i].get_row();
                        break;
                    }
                    case 6:
                    {
                        size=size + 13 + 2*mas[i].get_row();
                        break;
                    }
                }
            }
            size++;
            memcpy(mas_ch,&size,size_t(size_int));
            file.write(mas_ch,size_int);
            QString str;
            for (int i=0; i < row; i++)
            {
                switch(mas[i].get_index())
                {
                    case 0:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetX();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetY();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                    case 1:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetX();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetY();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int h,w;
                        mas[i].GetHW(h,w);
                        tmp = h;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = w;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                    case 2:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetX();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetY();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int h,w;
                        mas[i].GetHW(h,w);
                        tmp = h;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = w;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        mas[i].my_brush.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_brush.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                    case 3:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetX();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetY();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int h,w;
                        mas[i].GetHW(h,w);
                        tmp = h;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = w;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        mas[i].my_brush.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_brush.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                    case 4:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetX();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].GetY();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int h,w;
                        mas[i].GetHW(h,w);
                        tmp = h;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = w;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int s,e;
                        mas[i].GetSE(s,e);
                        tmp = s;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = e;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                    case 5:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].get_row();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int tmp_row = tmp;
                        tochka * tmp_mas =  mas[i].get_mas();
                        for (int k=0; k < tmp_row; k++)
                        {
                            tmp = tmp_mas[k].GetX();
                            memcpy(mas_ch,&tmp,size_t(size_int));
                            file.write(mas_ch,size_int);
                            str.append(QString::number(tmp));
                            tmp = tmp_mas[k].GetY();
                            memcpy(mas_ch,&tmp,size_t(size_int));
                            file.write(mas_ch,size_int);
                            str.append(QString::number(tmp));
                        }
                        break;
                    }
                    case 6:
                    {
                        int tmp = mas[i].get_index();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int r,g,b,a;
                        mas[i].my_pen.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_pen.GetWidth();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].get_row();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        int tmp_row = tmp;
                        tochka * tmp_mas =  mas[i].get_mas();
                        for (int k=0; k < tmp_row; k++)
                        {
                            tmp = tmp_mas[k].GetX();
                            memcpy(mas_ch,&tmp,size_t(size_int));
                            file.write(mas_ch,size_int);
                            str.append(QString::number(tmp));
                            tmp = tmp_mas[k].GetY();
                            memcpy(mas_ch,&tmp,size_t(size_int));
                            file.write(mas_ch,size_int);
                            str.append(QString::number(tmp));
                        }
                        mas[i].my_brush.GetRGB(r,g,b,a);
                        tmp = r;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = g;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = b;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = a;
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        tmp = mas[i].my_brush.GetStyle();
                        memcpy(mas_ch,&tmp,size_t(size_int));
                        file.write(mas_ch,size_int);
                        str.append(QString::number(tmp));
                        break;
                    }
                }
            }
            QByteArray hash=QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Md5).toHex();
            file.write(hash);
            file.close();
        }
    }

}

void MainWindow::on_tableWidget_cellChanged()//поменяли значение ячеек
{
    change = false;
}

void MainWindow::on_pushButton_3_clicked()//кнопка открыть
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Открыть файл в BIN"),"C:\\Users\\student\\Documents",tr("Binary file (*.bin)"));

    if(fileName.isEmpty())//выбран ли файл
    {//не выбран
        QMessageBox::information(this,"Ошибка","Файл не выбран",QMessageBox::Ok);
    }
    else
    {
        //проверка
        QFile file_g;
        file_g.setFileName(fileName);
        file_g.open(QIODevice::ReadOnly);
        char * mas_ch;
        int size_int = sizeof (int);
        int size{},tmp;
        QString str;
        str.clear();
        QByteArray hash;
        mas_ch = new char[size_int];
        file_g.read(mas_ch,size_int);
        memcpy(&size,mas_ch,size_t(size_int));
        file_g.read(mas_ch,size_int);
        memcpy(&size,mas_ch,size_t(size_int));
        for (int j=0; j<size-1;j++)
        {
            file_g.read(mas_ch,size_int);
            memcpy(&tmp,mas_ch,size_t(size_int));
            str.append(QString::number(tmp));
        }

        hash = file_g.readLine();
        QByteArray file_h = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Md5).toHex();
        file_g.close();

        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        int row{};
        mas_ch = new char[size_int];
        file.read(mas_ch,size_int);
        memcpy(&row,mas_ch,size_t(size_int));
        file.read(mas_ch,size_int);
        memcpy(&size,mas_ch,size_t(size_int));
        if((file_h==hash) and size<1000000 and size != 0 and (row<99) and (row>0))
        {
            int i = 0;
            QSpinBox *my_sb;
            ui->spinBox->setValue(row);
            QPushButton *my_but;
            for (int j=0; j < row; j++)
            {
                int index;
                my_but = new QPushButton;
                //ловим событие нажатия кнопки
                my_but->setProperty("row",j);//изменяем значение свойства
                connect(my_but,SIGNAL(clicked()),this,SLOT(onMyButClick()));
                file.read(mas_ch,size_int);
                memcpy(&index,mas_ch,size_t(size_int));
                //нижняя
                //создаем комбо бокс
                QComboBox *my_cb;
                my_cb = new QComboBox;
                my_cb->addItem("Точка");
                my_cb->addItem("Линии");
                my_cb->addItem("Прямоугольник");
                my_cb->addItem("Эллипс");
                my_cb->addItem("Дуга");
                my_cb->addItem("Ломаная");
                my_cb->addItem("Полигон");
                my_cb->setProperty("row",i);
                ui->tableWidget->setCellWidget(i+1, 0, my_cb);
                connect(my_cb,SIGNAL(currentIndexChanged(int)),this,SLOT(onMyCbCurrentIndexChanged(int)));
                my_cb->setCurrentIndex(index);
                switch(index)
                {
                    case 0:
                    {
                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 1);
                        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 2);
                        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);
                        break;

                    }
                    case 1:
                    {
                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 1);
                        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 2);
                        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 3);
                        ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память
                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 4);
                        ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        break;

                    }
                    case 2:
                    {
                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 1);
                        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 2);
                        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 3);
                        ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 4);
                        ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_brush.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_brush.SetStyle(tmp);

                        break;
                    }
                    case 3:
                    {
                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 1);
                        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 2);
                        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(1,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 3);
                        ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(1,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 4);
                        ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_brush.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_brush.SetStyle(tmp);

                        break;
                    }
                    case 4:
                    {
                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 1);
                        ui->tableWidget->setCellWidget(i+1, 1, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-2147483647,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 2);
                        ui->tableWidget->setCellWidget(i+1, 2, my_sb); //сбшник ячейку в таблицу

                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(1,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 3);
                        ui->tableWidget->setCellWidget(i+1, 3, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(1,2147483647);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 4);
                        ui->tableWidget->setCellWidget(i+1, 4, my_sb); //сбшник ячейку в таблицу

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(0,359);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 5);
                        ui->tableWidget->setCellWidget(i+1, 5, my_sb); //сбшник ячейку в таблицу


                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        //нижняя
                        my_sb = new QSpinBox; //выделили память

                        my_sb->setRange(-360,360);
                        my_sb->setValue(tmp);
                        ui->tableWidget->removeCellWidget(i+1, 6);
                        ui->tableWidget->setCellWidget(i+1, 6, my_sb); //сбшник ячейку в таблицу
                        break;
                    }
                    case 5:
                    {
                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].set_row(tmp);

                        int mas_tmp_row = tmp;
                        tochka *mas_tmp = new tochka[mas_tmp_row];

                        for (int k=0; k<mas_tmp_row; k++)
                        {
                            file.read(mas_ch,size_int);
                            memcpy(&tmp,mas_ch,size_t(size_int));
                            mas_tmp[k].SetX(tmp);

                            file.read(mas_ch,size_int);
                            memcpy(&tmp,mas_ch,size_t(size_int));
                            mas_tmp[k].SetY(tmp);
                        }
                        mas[j].set_mas(mas_tmp);
                        break;

                    }
                    case 6:
                    {
                        int r,g,b,a;
                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_pen.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetStyle(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_pen.SetWidth(tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].set_row(tmp);

                        int mas_tmp_row = tmp;
                        tochka *mas_tmp = new tochka[mas_tmp_row];

                        for (int k=0; k<mas_tmp_row; k++)
                        {
                            file.read(mas_ch,size_int);
                            memcpy(&tmp,mas_ch,size_t(size_int));
                            mas_tmp[k].SetX(tmp);

                            file.read(mas_ch,size_int);
                            memcpy(&tmp,mas_ch,size_t(size_int));
                            mas_tmp[k].SetY(tmp);
                        }
                        mas[j].set_mas(mas_tmp);

                        file.read(mas_ch,size_int);
                        memcpy(&r,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&g,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&b,mas_ch,size_t(size_int));

                        file.read(mas_ch,size_int);
                        memcpy(&a,mas_ch,size_t(size_int));

                        mas[j].my_brush.SetRGB(r,g,b,a);

                        file.read(mas_ch,size_int);
                        memcpy(&tmp,mas_ch,size_t(size_int));
                        mas[j].my_brush.SetStyle(tmp);
                        break;
                    }
                }
                i+=2;
            }

        }
        else
        {
            QMessageBox::information(this,"Ошибка","Файл был изменен вне программы",QMessageBox::Ok);
        }
    }
}
