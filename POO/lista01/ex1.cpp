#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Livro 
{
private:
    string titulo;
    string autor;
    string anoPubli;

public:
//construtor
    Livro(string titulo, string autor, string anoPubli) 
    : titulo(std::move(titulo)), autor(std::move(autor)), anoPubli(std::move(anoPubli)) {}
   
    string getTitulo() const { return titulo; }
    string getAutor() const {return autor;}
    string getAnoPubli() const {return anoPubli;}

};

class Biblioteca
{
private:
    string nome;
    string id;
    string endereco;
    vector <Livro> acervo; //variavel do tipo vector para armazenar uma colecao de objetos do tipo Livro. Um vetor!
                           

public:
    Biblioteca(string nome, string id, string endereco) 
    : nome(std::move(nome)), id(std::move(id)), endereco(std::move(endereco)) {}



    void registrarLivro(Livro livro) { acervo.push_back(std::move(livro)); }

    void exibirLivros() const {
        cout << "Acervo da biblioteca " << nome << " (" << acervo.size() << " livros):\n";
        for (const auto& l : acervo) {
            cout << "Título: " << l.getTitulo()
                 << ", Autor: " << l.getAutor()
                 << ", Ano: " << l.getAnoPubli() << '\n';
        }
    }
};

int main() {
    Biblioteca b("Biblioteca IFMS", "0001", "Rua Angelo Melao, 790");

    // criamos livros temporários e registramos (move evita cópia extra)
    b.registrarLivro(Livro("POO em C++", "Beckes", "2020"));
    b.registrarLivro(Livro("Estruturas de Dados", "Castro", "2018"));

    b.exibirLivros();
    return 0;
}
