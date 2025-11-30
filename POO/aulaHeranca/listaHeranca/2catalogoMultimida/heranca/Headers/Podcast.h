#pragma once
#include "Midia.h"
#include <vector>

class Podcast : public Midia {
private:
    std::string host;
    std::vector<std::string> convidados;

public:
    Podcast(const std::string& titulo, int ano, double duracao,
            const std::string& host, const std::vector<std::string>& convidados);

    void abrir() const override;
    void reproduzir() const override;
    std::string infoDetalhada() const override;
    bool combina(const std::string& filtro) const override;
};
