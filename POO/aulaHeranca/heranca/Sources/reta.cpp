#include <Reta.h>

Reta::Reta(){
    std::cout << "Reta criada" << std::endl;
}

Reta::~Reta(){
    std::cout << "Reta destruída" << std::endl;
}

//POLIMORFISMO
void Reta::draw(){
    std::cout << "Reta desenhada!" << std::endl;
}
