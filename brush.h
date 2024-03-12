#ifndef BRUSH_H
#define BRUSH_H

#include "color.h"

class brush : public color
{
public:
    brush(); //конструктор
    void SetStyle(int n_s); //задать стиль
    int GetStyle(); //получить стиль

private:
    int style;
};

#endif // BRUSH_H
