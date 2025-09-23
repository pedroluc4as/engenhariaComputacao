#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aluno
{
private:
    string nome;
    string matricula;
public:
    Aluno(string nome, string matricula)
    : nome(std::move(nome)), matricula(std::move(matricula)) {}

    string getNome() const { return nome; }
};

class Professor
{
private:
    string nome;
    string departamento;
public:
    Professor(string nome, string departamento)
    : nome(std::move(nome)), departamento(std::move(departamento)) {}

    string getNome() const { return nome; }
};

class Turma
{
private:
    string codigo;
    Professor* professor; 
    vector<Aluno*> alunos; 
public:
    Turma(string codigo, Professor* p)
    : codigo(std::move(codigo)), professor(p) {}

    void adicionarAluno(Aluno* aluno) 
    {
        alunos.push_back(aluno);
    }

    void exibir() const 
    {
        cout << "  Turma: " << codigo << endl;
        cout << "    Professor: " << professor->getNome() << endl;
        cout << "    Alunos Matriculados (" << alunos.size() << "):" << endl;

        for (const auto& aluno : alunos) 
        {
            cout << "      - " << aluno->getNome() << endl;
        }
    }
};

class Curso
{
private:
    string nome;
    vector<Turma> turmas;
public:
    Curso(string nome)
    : nome(std::move(nome)) {}

    void adicionarTurma(const Turma& turma) 
    {
        turmas.push_back(turma);
    }

    void exibir() const 
    {
        cout << "========================================" << endl;
        cout << "Curso: " << nome << endl;
        cout << "----------------------------------------" << endl;

        if (turmas.empty()) 
        {
            cout << "  (Nenhuma turma cadastrada)" << endl;
        } 
        
        else 
        {
            for (const auto& turma : turmas) 
            {
                turma.exibir();
            }
        }
        cout << "========================================" << endl;
    }
};

int main() {
    Professor prof1("Ricardo", "Computação");
    Aluno aluno1("João", "2025111");
    Aluno aluno2("Maria", "2025112");
    Aluno aluno3("José", "2025113");

    Turma turmaPOO("TAD030", &prof1);
    turmaPOO.adicionarAluno(&aluno1);
    turmaPOO.adicionarAluno(&aluno2);
    turmaPOO.adicionarAluno(&aluno3);
    
    Curso cursoTADS("Tecnologia em Análise e Desenv. de Sistemas");
    cursoTADS.adicionarTurma(turmaPOO);

    cursoTADS.exibir();

    return 0;
}