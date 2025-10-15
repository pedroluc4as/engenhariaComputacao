#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Professor {
    string nome, siape;
public:
    Professor(const string& n, const string& s) : nome(n), siape(s){
        cout << "[construtor] Professor: " << nome << "\n";
    }
    ~Professor(){ cout << "[destrutor] Professor: " << nome << "\n"; }
    string getNome() const { return nome; }
};

class Aluno {
    string nome, ra;
public:
    Aluno(const string& n, const string& r) : nome(n), ra(r){
        cout << "[construtor] Aluno: " << nome << "\n";
    }
    ~Aluno(){ cout << "[destrutor] Aluno: " << nome << "\n"; }
    string getNome() const { return nome; }
};

/* Turma COMPÕE alunos e AGREGA professor */
class Turma {
    string codigo;
    Professor* prof; // agregação
    vector<Aluno> alunos; // composição
public:
    Turma(const string& c, Professor* p) : codigo(c), prof(p){
        cout << "[construtor] Turma: " << codigo << "\n";
    }
    ~Turma(){ cout << "[destrutor] Turma: " << codigo << "\n"; }

    void matricular(const Aluno& a){ alunos.push_back(a); }
    void listar() const{
        cout << "Turma " << codigo << " (prof.: " << prof->getNome() << ")\n";
        for (auto& a : alunos) cout << " - " << a.getNome() << "\n";
    }
};

/* Curso COMPÕE turmas (vector<Turma>) */
class Curso {
    string nome;
    vector<Turma> turmas; // composição
public:
    Curso(const string& n) : nome(n){ cout << "[construtor] Curso: " << nome << "\n"; }
    ~Curso(){ cout << "[destrutor] Curso: " << nome << "\n"; }

    void adicionarTurma(const Turma& t){ turmas.push_back(t); }
    void listar() const{
        cout << "Curso: " << nome << "\n";
        for (auto& t : turmas) t.listar();
    }
};

int main(){
    Professor p("Beto", "123456");
    Turma t("POO-2025", &p);
    t.matricular(Aluno("Ana", "RA01"));
    t.matricular(Aluno("João", "RA02"));

    Curso c("Engenharia de Computação");
    c.adicionarTurma(t);
    c.listar();
    return 0;
}
