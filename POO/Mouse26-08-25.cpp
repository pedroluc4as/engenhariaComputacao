#include <iostream>

using namespace std;

class Mouse {

private:
//atributos -> caracteristicas 
    int sn;
    bool semFio;
    string marca;
    string modelo;
    int dpi;

public:

    // Construtor
    Mouse(int sn, bool semFio, string marca, string modelo, int dpi){
        this->sn = sn;
        this->semFio = semFio;
        this->marca = marca;
        this->modelo = modelo;
        this->dpi = dpi;     
    }

};
//Construtor vai ser o responsavel por crirar o objeto na memoria do computador