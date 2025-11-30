#include "../Headers/Podcast.h"
#include <iostream>
#include <sstream>

Podcast::Podcast(const std::string& titulo, int ano, double duracao,
                 const std::string& host, const std::vector<std::string>& convidados)
    : Midia(titulo, ano), host(host), convidados(convidados) {}

void Podcast::abrir() const {
    std::cout << "Abrindo podcast: " << titulo << " com " << host << "\n";
}

void Podcast::reproduzir() const {
    std::cout << "Reproduzindo podcast " << titulo << " (host: " << host << ")\n";
}

std::string Podcast::infoDetalhada() const {
    std::ostringstream oss;
    oss << "Podcast: " << titulo << " (" << ano << ")\n"
        << "Host: " << host << "\n"
        << "Convidados: ";
    for (auto& c : convidados) oss << c << " ";
    oss << "\n";
    return oss.str();
}

bool Podcast::combina(const std::string& filtro) const {
    if (titulo.find(filtro) != std::string::npos || host.find(filtro) != std::string::npos)
        return true;
    for (auto& c : convidados)
        if (c.find(filtro) != std::string::npos)
            return true;
    return false;
}
