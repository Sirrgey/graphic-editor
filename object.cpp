#include "object.h"

object::object()
{

}


void object::GetHW(int &h, int &w)//задали высоту ширину
{
    h=height;
    w=width;
}

void object::GetSE(int &s, int &e)//забрали старт и конец
{
    s=start;
    e=end;
}

void object::SetHW(int h, int w)//забрали высоту и ширину
{
    height=h;
    width=w;
}

void object::SetSE(int s, int e)//задали старт и конец
{
    start=s;
    end=e;
}

tochka* object::get_mas()//забрали массив
{
    return mas;
}

void object::set_mas(tochka *mas_points)//задали массив
{
    mas = mas_points;
}

void object::set_row(int n_row)//задали кол-во строк
{
    row = n_row;
}

int object::get_row()//забрали кол-во строк
{
    return row;
}

void object::set_index(int ind)//задали индекс
{
    index = ind;
}

int object::get_index()//забрали индекс
{
    return index;
}



