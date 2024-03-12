#include "tochka.h"

tochka::tochka()
{
    x=0;
    y=0;

}

void tochka::SetX(int new_x)//сеттеры
{
    x=new_x;
}
void tochka::SetY(int new_y)
{
    y=new_y;
}
void tochka::SetXY(int new_x, int new_y)
{
    x=new_x;
    y=new_y;
}


int tochka::GetX()//геттеры
{
    return x;
}
int tochka::GetY()
{
    return y;
}

void tochka::GetXY(int &cur_x, int &cur_y)
{
    cur_x=x;
    cur_y=y;
}


