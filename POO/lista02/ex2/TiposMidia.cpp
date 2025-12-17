#pragma once
#include "Midia.cpp"

class Musica : public Midia {
private:
    std::string artista;
    int bitrate; 

public:
    Musica(std::string t, int a, int d, std::string art, int bit)
        : Midia(t, a, d), artista(art), bitrate(bit) {}

    void reproduzir() const override {
        std::cout << "Tocando Musica: " << titulo << " - " << artista << " [" << bitrate << "kbps]\n";
    }

    void infoDetalhada() const override {
        std::cout << "[Musica] " << titulo << " (" << ano << ") | Artista: " << artista << "\n";
    }

    bool combina(const std::string& filtro) const override {
        return titulo.find(filtro) != std::string::npos || artista.find(filtro) != std::string::npos;
    }
};

class Video : public Midia {
private:
    std::string resolucao;
    std::string codec;

public:
    Video(std::string t, int a, int d, std::string res, std::string cod)
        : Midia(t, a, d), resolucao(res), codec(cod) {}

    void reproduzir() const override {
        std::cout << "Reproduzindo Video: " << titulo << " em " << resolucao << " (" << codec << ")\n";
    }

    void infoDetalhada() const override {
        std::cout << "[Video] " << titulo << " (" << ano << ") | Res: " << resolucao << "\n";
    }

    bool combina(const std::string& filtro) const override {
        return titulo.find(filtro) != std::string::npos || resolucao.find(filtro) != std::string::npos;
    }
};

class Podcast : public Midia {
private:
    std::string host;
    std::vector<std::string> convidados;

public:
    Podcast(std::string t, int a, int d, std::string h, std::vector<std::string> conv)
        : Midia(t, a, d), host(h), convidados(conv) {}

    void reproduzir() const override {
        std::cout << "Transmitindo Podcast: " << titulo << " com host " << host << "\n";
    }

    void infoDetalhada() const override {
        std::cout << "[Podcast] " << titulo << " | Host: " << host << " | Convidados: " << convidados.size() << "\n";
    }

    bool combina(const std::string& filtro) const override {
        if (titulo.find(filtro) != std::string::npos || host.find(filtro) != std::string::npos) return true;
        for (const auto& c : convidados) {
            if (c.find(filtro) != std::string::npos) return true;
        }
        return false;
    }
};