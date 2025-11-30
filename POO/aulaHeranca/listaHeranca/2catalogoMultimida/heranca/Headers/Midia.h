#pragma once
#include <string>

class Midia {
protected:
    std::string titulo;
    int ano;

public:
    Midia(const std::string& titulo, int ano);
    virtual ~Midia();

    virtual void abrir() const = 0;
    virtual void reproduzir() const = 0;
    virtual std::string infoDetalhada() const = 0;
    virtual bool combina(const std::string& filtro) const = 0;

    std::string getTitulo() const { return titulo; }
};
