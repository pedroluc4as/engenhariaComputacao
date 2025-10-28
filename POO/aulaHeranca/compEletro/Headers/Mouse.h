#ifndef COMPONENTE_ELETRONICO_MOUSE_H
#define COMPONENTE_ELETRONICO_MOUSE_H

#include <iostream>
#include "ComponenteEletronico.h"

class Mouse : public ComponenteEletronico //HERANÇA
{
public:
    Mouse();
    void ligar() override;
};
#endif