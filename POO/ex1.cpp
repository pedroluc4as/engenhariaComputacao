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
    Livro(string isbn, string titulo, string autor) : isbn(std::move(isbn)), titulo(std::move(titulo)), autor(std::move(autor)) {}
    bool estaDisponivel() const { return disponivel; }
//alt+shift+seta para baixo para duplicar

    void marcarIndisponivel() { disponivel = false; }
    void marcarDisponivel() { disponivel = true; }

    string getTitulo(){ return titulo; }
};

class Aluno {
private:
    string ra, nome;
public:
     Aluno(string ra, string nome) : ra(std::move(ra)), nome(std::move(nome)) {}

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
    : livro(livro), aluno(aluno), dataSaida(std::move(dataSaida)), dataPrevista(std::move(dataPrevista)){}

    bool confirmar()
    {
        if (livro && livro->estaDisponivel()){
            livro->marcarIndisponivel();
            return true;
        }
        return false;
    }

    void devolver(string dataDevolucao)
    {
        if (livro)
        {
            livro->marcarDisponivel();
            cout << "Livro '" << livro->getTitulo() << "' devolvido em " << dataDevolucao << "\n";
        }

    }
};

void test_biblioteca()
{
    cout << "--- Biblioteca --- \n";
    Livro livro("789-190292", "Prog. Orientada a Objeto", "IFMS");
    Aluno aluno("2025001", "Pedro");
    Emprestimo emprestimo(&livro, &aluno, "2025-09-09", "2025-09-15");
    
    cout << "Disponível antes: " << (livro.estaDisponivel() ? "sim" : "não") << "\n";
    emprestimo.confirmar();

    cout << "Disponível depois: " << (livro.estaDisponivel() ? "sim" : "não") << "\n";
    emprestimo.devolver("2025-09-10");
    
};

int main()
{
    test_biblioteca();
    return 0;

}