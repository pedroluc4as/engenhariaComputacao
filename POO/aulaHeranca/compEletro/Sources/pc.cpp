#include <ComponenteEletronico.h>
#include <iostream>

ComponenteEletronico::ComponenteEletronico()
{
    std::cout << "ComponenteEletronico " << std::string(40, '.') << " criado \n";
}

ComponenteEletronico::~ComponenteEletronico() 
{
    std::cout << "Um computador foi destruído!" << std::endl;
}

void ComponenteEletronico::ligar() 
{
    std::cout << "Ligando o computador..." << std::endl;
}



