#pragma once
#include <iostream>
#include <string>
#include <vector>

class Midia {
protected:
    std::string titulo;
    int ano;
    int duracaoSegundos;

public:
    Midia(std::string t, int a, int d) : titulo(t), ano(a), duracaoSegundos(d) {}
    virtual ~Midia() = default;

    virtual void reproduzir() const = 0;
    virtual void infoDetalhada() const = 0;
    
    virtual bool combina(const std::string& filtro) const = 0;

    std::string getTitulo() const { return titulo; }
};