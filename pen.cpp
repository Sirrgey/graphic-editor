#include "pen.h"

pen::pen() //конструктор
{
    width = 3;
    style = 1;
}

void pen::SetWidth(int n_w)//задали ширину
{
    width = n_w;
}

int pen::GetWidth()//забрали ширину
{
    return width;
}

void pen::SetStyle(int n_s)//задали стиль
{
    style = n_s;
}

int pen::GetStyle()//забрали стиль
{
    return style;
}
