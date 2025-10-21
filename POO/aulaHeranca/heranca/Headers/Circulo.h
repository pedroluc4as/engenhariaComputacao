#ifndef FIGURA_CIRCULO_H
#define FIGURA_CIRCULO_H

#include <iostream>
#include "FiguraGeometrica.h"


class Circulo : public FiguraGeometrica //HERANÇA
{
public:
    Circulo();
    void draw();
};

#endif