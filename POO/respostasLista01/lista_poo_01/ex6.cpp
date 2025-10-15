#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Parada {
    string nome, endereco;
public:
    Parada(const string& n, const string& e) : nome(n), endereco(e){
        cout << "[construtor] Parada: " << nome << "\n";
    }
    ~Parada(){ cout << "[destrutor] Parada: " << nome << "\n"; }
    string info() const { return nome + " - " + endereco; }
};

/* Rota COMPÕE paradas */
class Rota {
    string codigo;
    vector<Parada> paradas; // composição
public:
    Rota(const string& c) : codigo(c){ cout << "[construtor] Rota: " << codigo << "\n"; }
    ~Rota(){ cout << "[destrutor] Rota: " << codigo << "\n"; }

    void adicionar(const Parada& p){ paradas.push_back(p); }
    string getCodigo() const { return codigo; }
    void listar() const{
        cout << "Rota " << codigo << ":\n";
        for (auto& p : paradas) cout << " - " << p.info() << "\n";
    }
};

class Motorista {
    string nome, cnh;
public:
    Motorista(const string& n, const string& c) : nome(n), cnh(c){
        cout << "[construtor] Motorista: " << nome << "\n";
    }
    ~Motorista(){ cout << "[destrutor] Motorista: " << nome << "\n"; }
    string getNome() const { return nome; }
};

/* Onibus AGREGA rota (ponteiro) */
class Onibus {
    string placa;
    int capacidade;
    Rota* rota; // agregação
public:
    Onibus(const string& p, int cap) : placa(p), capacidade(cap), rota(nullptr){
        cout << "[construtor] Onibus: " << placa << "\n";
    }
    ~Onibus(){ cout << "[destrutor] Onibus: " << placa << "\n"; }
    void setRota(Rota* r){ rota = r; }
    void info() const{
        cout << "Onibus " << placa << " cap=" << capacidade
             << " rota=" << (rota ? rota->getCodigo() : "sem rota") << "\n";
    }
};

/* Empresa COMPÕE onibus e AGREGA motoristas */
class Empresa {
    string nome;
    vector<Onibus> frota; // composição
    vector<Motorista*> motoristas; // agregação
public:
    Empresa(const string& n) : nome(n){ cout << "[construtor] Empresa: " << nome << "\n"; }
    ~Empresa(){ cout << "[destrutor] Empresa: " << nome << "\n"; }

    void contratar(Motorista* m){ motoristas.push_back(m); }
    void comprar(const Onibus& o){ frota.push_back(o); }

    void listar() const{
        cout << "Empresa " << nome << "\n";
        cout << "Motoristas:\n";
        for (auto* m : motoristas) cout << " - " << m->getNome() << "\n";
        cout << "Frota:\n";
        for (auto& o : frota) o.info();
    }
};

int main(){
    Rota r("R1");
    r.adicionar(Parada("Terminal", "Centro"));
    r.adicionar(Parada("UFMS", "Av. B"));

    Onibus o1("ABC-1234", 40);
    o1.setRota(&r);

    Motorista m("Carlos", "999999");

    Empresa e("TransMS");
    e.comprar(o1);
    e.contratar(&m);

    r.listar();
    e.listar();
    return 0;
}
