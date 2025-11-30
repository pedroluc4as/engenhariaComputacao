#pragma once
#include "Midia.h"

class Video : public Midia {
private:

public:
    Video(const std::string& titulo, int ano);

    void abrir() const override;
    void reproduzir() const override;
    std::string infoDetalhada() const override;
    bool combina(const std::string& filtro) const override;
};
