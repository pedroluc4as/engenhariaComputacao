#include "../Headers/Video.h"
#include <iostream>
#include <sstream>

Video::Video(const std::string& titulo, int ano)
    : Midia(titulo, ano) {}

void Video::abrir() const {
    std::cout << "Abrindo video: " << titulo << "\n";
}

void Video::reproduzir() const {
    std::cout << "Reproduzindo video: " << titulo << "\n";
}

std::string Video::infoDetalhada() const {
    std::ostringstream oss;
    oss << "Video: " << titulo << " (" << ano << ")\n";
    return oss.str();
}

bool Video::combina(const std::string& filtro) const {
    return titulo.find(filtro) != std::string::npos;
}