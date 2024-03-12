#ifndef OBJECT_H
#define OBJECT_H

#include "tochka.h"
#include "color.h"
#include "pen.h"
#include "brush.h"
#include <QMainWindow>


class object : public tochka
{
public:
    object();//для дуги
    pen my_pen;
    brush my_brush;
    void SetHW(int h, int w);
    void GetHW(int &h, int &w);
    void SetSE(int s, int e);
    void GetSE(int &s, int &e);
    void set_mas(tochka* mas_points);
    tochka* get_mas();
    void set_row(int n_row);
    int get_row();
    int get_index();
    void set_index(int);

protected:
    int width;
    int height;
    int start;
    int end;
    int index;
    tochka *mas;
    int row;
    //индексы 0 - точка 1 - линия 2 - прямоугольник 3 - эллипс 4 - дуга 5 - ломанная 6 - полигон


};

#endif // OBJECT_H
