#pragma once
#include "Midia.h"

class Musica : public Midia {
private:
    std::string artista;
    int bitrate;

public:
    Musica(const std::string& titulo, int ano, double duracao,
           const std::string& artista, int bitrate);

    void abrir() const override;
    void reproduzir() const override;
    std::string infoDetalhada() const override;
    bool combina(const std::string& filtro) const override;
};
