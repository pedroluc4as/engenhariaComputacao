#include <ComponenteEletronico.h>
#include <Teclado.h>
#include <Mouse.h>
int main()
{
    ComponenteEletronico *mousep, *tecladop;
    Teclado teclado;
    Mouse mouse;

    mousep = &mouse;
    tecladop = &teclado;

    mousep->ligar();
    tecladop->ligar();
}
