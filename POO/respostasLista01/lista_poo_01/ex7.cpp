#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Arma {
    string nome; int dano;
public:
    Arma(const string& n, int d) : nome(n), dano(d){
        cout << "[construtor] Arma: " << nome << "\n";
    }
    ~Arma(){ cout << "[destrutor] Arma: " << nome << "\n"; }
    string getNome() const { return nome; }
    int getDano() const { return dano; }
};

class Item {
    string nome; double peso;
public:
    Item(const string& n, double p) : nome(n), peso(p){
        cout << "[construtor] Item: " << nome << "\n";
    }
    ~Item(){ cout << "[destrutor] Item: " << nome << "\n"; }
    string info() const { return nome + " (" + to_string(peso) + "kg)"; }
};

/* Inventario COMPÕE itens e armas */
class Inventario {
    vector<Item> itens;
    vector<Arma> armas;
public:
    Inventario(){ cout << "[construtor] Inventario\n"; }
    ~Inventario(){ cout << "[destrutor] Inventario\n"; }

    void addItem(const Item& i){ itens.push_back(i); }
    void addArma(const Arma& a){ armas.push_back(a); }
    void listar() const{
        cout << "Itens:\n"; for (auto& i : itens) cout << " - " << i.info() << "\n";
        cout << "Armas:\n"; for (auto& a : armas) cout << " - " << a.getNome() << "\n";
    }
};

/* Jogador COMPÕE inventário */
class Jogador {
    string apelido;
    Inventario inv; // composição
public:
    Jogador(const string& a) : apelido(a){ cout << "[construtor] Jogador: " << apelido << "\n"; }
    ~Jogador(){ cout << "[destrutor] Jogador: " << apelido << "\n"; }
    Inventario& inventario(){ return inv; }
};

/* Inimigo AGREGA arma (ponteiro) */
class Inimigo {
    string tipo; int hp;
    Arma* arma; // agregação
public:
    Inimigo(const string& t, int h) : tipo(t), hp(h), arma(nullptr){
        cout << "[construtor] Inimigo: " << tipo << "\n";
    }
    ~Inimigo(){ cout << "[destrutor] Inimigo: " << tipo << "\n"; }
    void equipar(Arma* a){ arma = a; }
    void status() const{
        cout << "Inimigo " << tipo << " HP=" << hp
             << " Arma=" << (arma ? arma->getNome() : "nenhuma") << "\n";
    }
};

int main(){
    Jogador j("Fabi");
    j.inventario().addItem(Item("Poção", 0.5));
    j.inventario().addArma(Arma("Espada", 15));
    j.inventario().listar();

    Arma garra("Garras", 8);
    Inimigo lobo("Lobo", 30);
    lobo.equipar(&garra); // agregação
    lobo.status();
    return 0;
}
