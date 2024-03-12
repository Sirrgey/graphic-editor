#include "brush.h"

brush::brush() //конструктор
{
    style = 1;
}

void brush::SetStyle(int n_s)//задали стиль
{

    style = n_s;

}

int brush::GetStyle()//забрали стиль
{
    return style;
}
