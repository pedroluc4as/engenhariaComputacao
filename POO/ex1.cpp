#include <iostream>
#include <string>

using namespace std;

class Livro {
    // modificadores de acesso -> nível de visibilidade dos atributos e métodos
private:
    //private -> visivel class
    //quando os atributos (atr ou att) estão privados damos o nome de encapsulamento 

    string isbn, titulo, autor;
    bool disponivel {true};


public:
    //construtor é sempre o mesmo nome da classe 
    //com letra maiscula e tem essa cara ai embaixo, com essas chaves
    Livro(string isbn, string titulo, string autor) : isbn(move(isbn)), titulo(move(titulo)), autor(move(autor)) {}
    bool estaDisponivel() const { return disponivel; }
//alt+shift+seta para baixo para duplicar

    void marcarIndisponivel() { disponivel = false; }
    void marcarIndisponivel() { disponivel = true; }

};

class Aluno {
private:
    string ra, nome;
public:
     Aluno(string ra, string nome) : ra(move(ra)), nome(move(nome)) {}

     string getNome(){ return nome;}
};

class Emprestimo {
private:
    Livro* livro;
    Aluno* aluno;
    string dataSaida, dataPrevista;
    bool devolvido{false};

public:
    //construtor
    Emprestimo(Livro *livro, Aluno* aluno, string dataSaida, string dataPrevista) 
    : livro(livro), aluno(aluno), dataSaida(move(dataSaida)), dataPrevista(move(dataPrevista)){}

    bool confirmar()
    {
        if(livro && livro->estaDisponivel()){
            livro->marcarIndisponivel();
            return true;
        }
        return false;
    }

    bool devolver()
    {
        if(livro == devolvido){

        }
    }

};