#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Medico {
    string nome, crm;
public:
    Medico(const string& n, const string& c) : nome(n), crm(c) {
        cout << "[construtor] Medico: " << nome << "\n";
    }
    ~Medico(){ cout << "[destrutor] Medico: " << nome << "\n"; }
    string getNome() const { return nome; }
};

class Paciente {
    string nome, cpf;
public:
    Paciente(const string& n, const string& c) : nome(n), cpf(c) {
        cout << "[construtor] Paciente: " << nome << "\n";
    }
    ~Paciente(){ cout << "[destrutor] Paciente: " << nome << "\n"; }
    string getNome() const { return nome; }
};

class Anotacao {
    string data, texto;
public:
    Anotacao(const string& d, const string& t) : data(d), texto(t) {
        cout << "[construtor] Anotacao em " << data << "\n";
    }
    ~Anotacao(){ cout << "[destrutor] Anotacao em " << data << "\n"; }
    string info() const { return "[" + data + "] " + texto; }
};

/* Prontuario COMPÕE anotações e AGREGA médico/paciente */
class Prontuario {
    Paciente* paciente; // agregação
    Medico* responsavel; // agregação
    vector<Anotacao> notas; // composição
public:
    Prontuario(Paciente* p, Medico* m) : paciente(p), responsavel(m) {
        cout << "[construtor] Prontuario de " << p->getNome() << "\n";
    }
    ~Prontuario(){ cout << "[destrutor] Prontuario de " << paciente->getNome() << "\n"; }

    void adicionar(const Anotacao& a){ notas.push_back(a); }
    void setMedico(Medico* m){ responsavel = m; }
    void listar() const{
        cout << "Prontuario de " << paciente->getNome()
             << " (resp.: " << responsavel->getNome() << ")\n";
        for (auto& n : notas) cout << " - " << n.info() << "\n";
    }
};

int main(){
    Medico m1("Dra. Ana", "CRM123");
    Medico m2("Dr. João", "CRM456");
    Paciente p("Carlos", "111.222.333-44");
    Prontuario pr(&p, &m1);
    pr.adicionar(Anotacao("2025-10-01", "Check-up anual"));
    pr.adicionar(Anotacao("2025-10-05", "Retorno com exames"));
    pr.setMedico(&m2); // troca de responsável (agregação)
    pr.listar();
    return 0;
}
