#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
private:
    string nome;
public:
    Item(string nome) : nome(std::move(nome)) {}
    string getNome() const { return nome; }
};

class Arma
{
private:
    string nome;
    int dano;
public:
    Arma(string nome, int dano)
    : nome(std::move(nome)), dano(dano) {}
    
    string getNome() const { return nome; }
    int getDano() const { return dano; }
};

class Inventario
{
private:
    vector<Item> itens;  
    vector<Arma> armas;
public:
    Inventario() {}

    void adicionarItem(const Item& item) 
    {
        itens.push_back(item);
    }
    void adicionarArma(const Arma& arma) 
    {
        armas.push_back(arma);
    }

    void exibir() const {
        cout << "    Itens:" << endl;

        if (itens.empty()) 
        {
            cout << "      (Nenhum item)" << endl;
        } 
        
        else 
        {
            for (const auto& item : itens) 
            {
                cout << "      - " << item.getNome() << endl;
            }
        }

        cout << "    Armas:" << endl;
        if (armas.empty()) 
        {
            cout << "      (Nenhuma arma)" << endl;
        } 
        
        else 
        {
            for (const auto& arma : armas) 
            {
                cout << "      - " << arma.getNome() << " (Dano: " << arma.getDano() << ")" << endl;
            }
        }
    }
};

class Jogador
{
private:
    string nome;
    Inventario inventario; // Composição: o jogador possui um inventário
public:
    Jogador(string nome) : nome(std::move(nome)) {}

    void coletarItem(const Item& item) 
    {
        cout << nome << " coletou o item: " << item.getNome() << endl;
        inventario.adicionarItem(item);
    }

    void coletarArma(const Arma& arma)
    {
        cout << nome << " coletou a arma: " << arma.getNome() << endl;
        inventario.adicionarArma(arma);
    }

    void exibir() const 
    {
        cout << "--- Jogador: " << nome << " ---" << endl;
        cout << "  Inventário:" << endl;
        inventario.exibir();
        cout << "------------------------" << endl;
    }
};

class Inimigo
{
private:
    string tipo;
    Arma* armaEquipada;
public:
    Inimigo(string tipo) : tipo(std::move(tipo)), armaEquipada(nullptr) {}

    void equiparArma(Arma* arma) 
    {
        armaEquipada = arma;
    }

    void exibir() const 
    {
        cout << "--- Inimigo: " << tipo << " ---" << endl;

        if (armaEquipada) 
        {
            cout << "  Arma Equipada: " << armaEquipada->getNome() 
                 << " (Dano: " << armaEquipada->getDano() << ")" << endl;

        } 
        
        else 
        {
            cout << "  (Desarmado)" << endl;
        }
        cout << "------------------------" << endl;
    }
};

int main() {
    Item pocao("Poção de Cura");
    Arma espada("Espada de Ferro", 10);
    Arma machado("Machado de Guerra", 15);

    Jogador heroi("Aragorn");
    heroi.coletarItem(pocao);
    heroi.coletarArma(espada);
    heroi.exibir();

    Inimigo orc("Orc Grunt");
    orc.equiparArma(&machado); 
    orc.exibir();

    return 0;
}