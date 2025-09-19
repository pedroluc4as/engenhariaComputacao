#include <iostream>
#include <string>

using namespace std;

class Livro
{
    // modificadores de acesso -> nível de visibilidade dos atributos e métodos
private:
    /*    gh
    private -> visivel class
    qdo os atr estão privados damos o nome de encapsulamento

    */
    string isbn, titulo, autor;
    bool disponivel{true};

public:
    Livro(string i, string t, string a) : isbn(std::move(i)), titulo(std::move(t)), autor(std::move(a)) {}
    bool estaDisponivel() const { return disponivel; }

    void marcarIndisponivel() { disponivel = false; }
    void marcarDisponivel() { disponivel = true; }

    string getTitulo() { return titulo; }
};

class Aluno
{
private:
    string ra, nome;

public:
    Aluno(string r, string n) : ra(std::move(r)), nome(std::move(n)) {}

    string getNome() { return nome; }
};

class Emprestimo
{
private:
    Livro *livro;
    Aluno *aluno;
    string dataSaida, dataPrevista;
    bool devolvido{false};

public:
    Emprestimo(Livro *l, Aluno *a, string saida, string prevista) : livro(l), aluno(a), dataSaida(std::move(saida)), dataPrevista(std::move(prevista)) {}

    bool confirmar()
    {
        if (livro && livro->estaDisponivel())
        {
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
    cout << "\n--- Q1: Biblioteca ---\n";
    Livro l("978-857522", "Padrões de Projeto", "Gamma et al.");
    Aluno a("2025001", "Ana Silva");
    Emprestimo e(&l, &a, "2025-09-05", "2025-09-12");

    cout << "Disponível antes: " << (l.estaDisponivel() ? "sim" : "não") << "\n";
    e.confirmar();
    cout << "Disponível depois: " << (l.estaDisponivel() ? "sim" : "não") << "\n";
    e.devolver("2025-09-10");
}

int main()
{
    test_biblioteca();
    return 0;
}