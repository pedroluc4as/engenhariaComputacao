#include <iostream>
#include <string>

using namespace std;

class Disciplina
{
private:
    string cod, nome, professor;
public:
    Disciplina(string cod, string nome, string professor) 
    : cod(std::move(cod)), nome(std::move(nome)), professor(std::move(professor)) {}
};

class Notas
{
private:
    float nota;
    Disciplina *disciplina;

public:
    Notas(float nota, Disciplina *disciplina) : nota(std::move(nota)), disciplina(std::move(disciplina)) {}
};

class Aluno
{
private:
    string cpf, nome, ra, dt_nasc;
    Notas *notas;
public:
    Aluno(string cpf, string nome, string ra, string dt_nasc, Notas *notas) 
    : cpf(std::move(cpf)), nome(std::move(nome)), ra(std::move(ra)), 
    dt_nasc(std::move(dt_nasc)), notas(std::move(notas)) {}

    //metodos
   int media();
};

class Matricula
{
private:
    string num;
    Aluno *aluno;

public:
    Matricula(string num, Aluno *aluno) : num(std::move(num)), aluno(std::move(aluno)) {}
};