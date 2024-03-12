#ifndef PEN_H
#define PEN_H

#include <color.h>

class pen : public color
{
public:
    pen(); //конструктор
    void SetWidth(int n_w);
    int GetWidth();
    void SetStyle(int n_s);
    int GetStyle();

protected:
    int width;
    int style;
};

#endif // PEN_H
