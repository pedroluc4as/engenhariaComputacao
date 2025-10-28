#include <FiguraGeometrica.h>
#include <Reta.h>
#include <Circulo.h>
int main()
{
    FiguraGeometrica *rfig, *cfig;
    Reta reta;
    Circulo circulo;

    rfig = &reta;
    cfig = &circulo;

    rfig->draw();
    cfig->draw();


}