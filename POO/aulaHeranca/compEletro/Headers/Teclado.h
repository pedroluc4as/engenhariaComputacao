#ifndef COMPONENTE_ELETRONICO_TECLADO_H
#define COMPONENTE_ELETRONICO_TECLADO_H

#include "ComponenteEletronico.h"
#include <iostream>

class Teclado : public ComponenteEletronico //HERANÇA
{
public:
    Teclado();
    void ligar() override;

};

#endif