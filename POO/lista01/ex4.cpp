#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Medico
{
private:
    string nome;
    string idMed;
public:
    Medico(string nome, string idMed)
    : nome(std::move(nome)), idMed(std::move(idMed)) {}

    string getNome() const { return nome; }
};

class Paciente
{
private:
    string nome;
    string cpf;
public:
    Paciente(string nome, string cpf)
    : nome(std::move(nome)), cpf(std::move(cpf)) {}

    string getNome() const { return nome; }
};

class Anotacao
{
private:
    string data;
    string texto;
public:
    Anotacao(string data, string texto)
    : data(std::move(data)), texto(std::move(texto)) {}

    void exibir() const {
        cout << "    - [" << data << "]: " << texto << endl;
    }
};

class Prontuario
{
private:
    Paciente* paciente; 
    Medico* medico;     
    vector<Anotacao> anotacoes;
public:
    Prontuario(Paciente* p, Medico* m)
    : paciente(p), medico(m) {}

    void adicionarAnotacao(const Anotacao& anotacao) 
    {
        anotacoes.push_back(anotacao);
    }

    void exibir() const 
    {
        cout << "Prontuário do Paciente: " << paciente->getNome() << endl;
        cout << "Médico Responsável: Dr " << medico->getNome() << endl;
        cout << "Anotações:" << endl;

        if (anotacoes.empty()) 
        {
            cout << "  (Nenhuma anotação registrada)" << endl;
        } 
        
        else 
        {
            for (const auto& nota : anotacoes) 
            {
                nota.exibir();
            }
        }
    }
};

int main() {
    Medico medico1("Ana", "idMed-12345");
    Paciente paciente1("Carlos", "111.222.333-44");

    Prontuario prontuario1(&paciente1, &medico1);

    prontuario1.adicionarAnotacao(Anotacao("20/09/2025", "Paciente relata dor de cabeça."));
    prontuario1.adicionarAnotacao(Anotacao("22/09/2025", "Exames de sangue solicitados."));

    prontuario1.exibir();

    return 0;
}