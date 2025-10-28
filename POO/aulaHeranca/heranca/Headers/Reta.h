#ifndef FIGURA_RETA_H
#define FIGURA_RETA_H

#include <iostream>
#include "FiguraGeometrica.h"


class Reta : public FiguraGeometrica //HERANÇA
{
public:
    Reta();
    ~Reta();
    void draw();
};

#endif