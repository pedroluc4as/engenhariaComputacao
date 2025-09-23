#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parada
{
private:
    string nome;
public:
    Parada(string nome) : nome(std::move(nome)) {}
    string getNome() const { return nome; }
};

class Rota
{
private:
    string nome;
    vector<Parada> paradas; 
public:
    Rota(string nome) : nome(std::move(nome)) {}

    void adicionarParada(const Parada& parada) 
    {
        paradas.push_back(parada);
    }

    void exibir() const 
    {
        cout << "      Paradas: ";
        for (size_t i = 0; i < paradas.size(); ++i) 
        {
            cout << paradas[i].getNome() << (i == paradas.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }
    string getNome() const { return nome; }
};

class Motorista
{
private:
    string nome;
    string matricula;
public:
    Motorista(string nome, string matricula)
    : nome(std::move(nome)), matricula(std::move(matricula)) {}
    string getNome() const { return nome; }
};

class Onibus
{
private:
    string placa;
    Motorista* motorista; 
    Rota* rota;           
public:
    Onibus(string placa) : placa(std::move(placa)), motorista(nullptr), rota(nullptr) {}

    void associarMotorista(Motorista* m) 
    {
        motorista = m;
    }

    void associarRota(Rota* r) 
    {
        rota = r;
    }

    void exibir() const 
    {
        cout << "  Ônibus Placa: " << placa << endl;
        if (motorista) {
            cout << "    Motorista: " << motorista->getNome() << endl;
        }
        if (rota) {
            cout << "    Rota: " << rota->getNome() << endl;
            rota->exibir();
        }
    }
};

class Empresa
{
private:
    string nome;
    vector<Onibus> frota; 
    vector<Motorista> motoristas;
    vector<Rota> rotas;           
public:
    Empresa(string nome) : nome(std::move(nome)) {}

    void contratarMotorista(const Motorista& m) { motoristas.push_back(m); }
    void adicionarRota(const Rota& r) { rotas.push_back(r); }
    void adicionarOnibus(const Onibus& o) { frota.push_back(o); }

    void exibirFrota() const 
    {
        cout << "======= Frota da Empresa: " << nome << " =======" << endl;
        for (const auto& onibus : frota) {
            onibus.exibir();
            cout << "----------------------------------------" << endl;
        }
    }
};

int main() {
    Empresa empresa("Viação Águia Dourada");

    Rota rota1("Centro -> Bairro");
    rota1.adicionarParada(Parada("Terminal Central"));
    rota1.adicionarParada(Parada("Praça Principal"));
    rota1.adicionarParada(Parada("Shopping"));

    Motorista motorista1("Roberto Carlos", "M-5566");
    
    Onibus onibus1("ABC-1234");
    onibus1.associarMotorista(&motorista1);
    onibus1.associarRota(&rota1);

    empresa.adicionarOnibus(onibus1);
    empresa.exibirFrota();

    return 0;
}