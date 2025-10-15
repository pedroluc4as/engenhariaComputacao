// Exemplo de POO em C++ com explicação linha a linha
#include <iostream>   // entrada/saída (std::cout, std::endl)
#include <string>     // std::string
#include <vector>     // std::vector

using namespace std;  // para não precisar escrever std:: toda hora

// ---------- Classe Pessoa ----------
class Pessoa {                      // declaração da classe Pessoa
private:                             // início da seção privada (encapsulamento)
    int id;                          // atributo id (inteiro)
    string nome;                     // atributo nome (string)
    string cpf;                      // atributo cpf (string, identificador)
public:                              // início da seção pública (métodos acessíveis)
    // Construtor: inicializa os atributos quando um objeto Pessoa é criado
    Pessoa(int id, const string& nome, const string& cpf)
        : id(id), nome(nome), cpf(cpf) // lista de inicialização dos atributos
    {
        cout << "Pessoa criada: " << nome << endl; // mensagem opcional para acompanhar criação
    }

    // Destrutor: chamado automaticamente quando o objeto é destruído
    ~Pessoa() {
        cout << "Pessoa destruída: " << nome << endl;
    }

    // Getter para id (retorna o id)
    int getId() const { return id; }

    // Getter para nome (retorna o nome)
    string getNome() const { return nome; }

    // Getter para cpf (retorna o cpf)
    string getCpf() const { return cpf; }

    // Setter para nome (altera o nome)
    void setNome(const string& n) { nome = n; }

    // Setter para cpf (altera o cpf)
    void setCpf(const string& c) { cpf = c; }

    // Método utilitário para imprimir informações da pessoa
    void printInfo() const {
        cout << "Pessoa [id=" << id << ", nome=" << nome << ", cpf=" << cpf << "]" << endl;
    }
}; // fim da classe Pessoa

// ---------- Classe Professor (herança) ----------
class Professor : public Pessoa {    // Professor herda publicamente de Pessoa
private:
    string disciplina;               // atributo específico do Professor
public:
    // Construtor: chama o construtor da classe base Pessoa e inicializa disciplina
    Professor(int id, const string& nome, const string& cpf, const string& disc)
        : Pessoa(id, nome, cpf), disciplina(disc) // chama Pessoa(...) e inicializa disciplina
    {
        cout << "Professor criado: " << getNome() << ", disciplina: " << disciplina << endl;
    }

    // Destrutor do Professor
    ~Professor() {
        cout << "Professor destruído: " << getNome() << endl;
    }

    // Getter para disciplina
    string getDisciplina() const { return disciplina; }

    // Método para imprimir info do professor (usa getNome da classe base)
    void printInfo() const {
        cout << "Professor [nome=" << getNome() << ", disciplina=" << disciplina << "]" << endl;
    }
}; // fim da classe Professor

// ---------- Classe Departamento (agregação) ----------
class Departamento {
private:
    vector<Professor*> professores;  // armazenamento de ponteiros para Professor
                                     // isso representa AGREGACAO: o Departamento referencia Professores,
                                     // mas NÃO é responsável por apagar (liberar) eles.
public:
    // Adiciona um professor (ponteiro) ao departamento
    void addProfessor(Professor* p) {
        professores.push_back(p);
    }

    // Imprime os professores do departamento
    void printProfessores() const {
        cout << "Departamento - Professores:" << endl;
        for (Professor* p : professores) {
            if (p)                              // checagem simples para evitar acessar ponteiro nulo
                p->printInfo();                // chama método do professor apontado
            else
                cout << "Ponteiro nulo" << endl;
        }
    }

    // Destrutor do Departamento: observa-se que NÃO deletamos os professores aqui.
    // Isso ilustra agregação (quem criou o professor deve ser responsável por deletá-lo).
    ~Departamento() {
        cout << "Departamento destruído (não deleta os professores)." << endl;
    }
}; // fim da classe Departamento

// ---------- Classe Apartamento (parte de composição) ----------
class Apartamento {
private:
    int numero;                       // número do apartamento
    string morador;                   // nome do morador
public:
    // Construtor do Apartamento
    Apartamento(int numero, const string& morador)
        : numero(numero), morador(morador)
    {
        cout << "Apartamento criado: " << numero << " - " << morador << endl;
    }

    // Destrutor do Apartamento
    ~Apartamento() {
        cout << "Apartamento destruído: " << numero << endl;
    }

    // Imprime info do apartamento
    void printInfo() const {
        cout << "Apartamento [" << numero << "] - morador: " << morador << endl;
    }
}; // fim da classe Apartamento

// ---------- Classe Predio (composição) ----------
class Predio {
private:
    vector<Apartamento> apartamentos; // vetor de Apartamento POR VALOR -> composição
                                      // quando o prédio for destruído, os apartamentos também são.
public:
    // Adiciona um apartamento (por cópia) ao prédio
    void addApartamento(const Apartamento& a) {
        apartamentos.push_back(a); // cópia do apartamento para dentro do prédio
    }

    // Imprime os apartamentos
    void printApartamentos() const {
        cout << "Prédio - Apartamentos:" << endl;
        for (const auto& a : apartamentos)
            a.printInfo(); // chama printInfo de cada Apartamento
    }

    // Destrutor do Prédio (apartamentos serão destruídos automaticamente)
    ~Predio() {
        cout << "Prédio destruído (apartamentos serão destruídos automaticamente)." << endl;
    }
}; // fim da classe Predio

// ---------- Função principal ----------
int main() {
    // Cria uma Pessoa na pilha (stack) - instanciação direta
    Pessoa p1(1, "Ana", "123.456.789-00"); // chama o construtor de Pessoa
    p1.printInfo();                        // imprime informações da pessoa

    // Cria um Professor dinamicamente (heap) usando new
    Professor* prof = new Professor(2, "Carlos", "987.654.321-00", "POO");
    // neste caso usamos new -> devemos dar delete depois (responsabilidade de quem alocou)

    // EXEMPLO DE AGREGACAO: Departamento guarda ponteiro para Professor, mas não é dono dele
    Departamento dept;
    dept.addProfessor(prof);  // adiciona a referência (ponteiro) ao departamento
    dept.printProfessores();  // imprime professores (usa prof->printInfo internamente)

    // EXEMPLO DE COMPOSIÇÃO: Predio possui Apartamentos por valor (o prédio gerencia o ciclo de vida)
    Predio pred;
    pred.addApartamento(Apartamento(101, "João"));  // temporário é copiado para dentro do prédio
    pred.addApartamento(Apartamento(102, "Maria"));
    pred.printApartamentos();

    // Uso de getters e setters (encapsulamento)
    cout << "Nome do professor: " << prof->getNome() << endl; // getter
    prof->setCpf("000.000.000-00");                          // setter
    cout << "CPF do professor atualizado: " << prof->getCpf() << endl;

    // Liberar memória alocada com new -> sempre lembrar do delete
    delete prof; // como o Departamento não 'deleta' os professores, nós deletamos aqui.
                 // após esse delete, o ponteiro 'prof' fica pendente (dangling) se não for setado a nullptr.
                 // Observação: dept ainda contém o ponteiro antigo; em código real você deveria
                 // remover/atualizar essa referência para evitar dangling pointers.

    // Fim do main: objetos locais (p1, dept, pred, etc.) são destruídos automaticamente
    return 0; // retorna 0 indicando fim bem-sucedido do programa
}

/* Pontos-chave (resumido)
    
class = molde; objeto = instância.

Construtor: mesmo nome da classe, sem retorno, inicializa atributos.

Destrutor: ~Classe() executado quando o objeto é destruído.

Encapsulamento: use private para proteger dados e public para expor métodos (get/set).

Associação: relação fraca entre objetos (não mostrada como dono explícito).

Agregação: objeto A referencia B (por ponteiro) sem controlar ciclo de vida de B. (ex.: Departamento com Professor*)

Composição: objeto A contém B por valor e controla seu ciclo de vida. (ex.: Predio com Apartamento)*/