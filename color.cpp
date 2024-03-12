#include "color.h"

color::color()
{
    red=0;
    green=0;
    blue=0;
    alpha=255;
}

void color::SetRGB(int r, int g, int b, int a)//установили ргба
{
    red=r;
    green =g;
    blue = b;
    alpha=a;
}

void color::GetRGB(int &r, int &g, int &b, int &a)//взяли ргба
{
    r=red;
    g=green;
    b=blue;
    a=alpha;
}
