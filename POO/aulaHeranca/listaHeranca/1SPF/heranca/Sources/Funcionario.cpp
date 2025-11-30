#include "../Headers/Funcionario.h"

Funcionario::Funcionario(int id, const std::string& nome, const std::string& doc)
    : id(id), nome(nome), documento(doc) {}

Funcionario::~Funcionario() = default;

int Funcionario::getId() const { return id; }
std::string Funcionario::getNome() const { return nome; }
std::string Funcionario::getDocumento() const { return documento; }