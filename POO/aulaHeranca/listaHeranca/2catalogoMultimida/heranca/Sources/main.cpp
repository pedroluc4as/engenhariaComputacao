#include <iostream>
#include <memory>
#include <vector>
#include "../Headers/GerenciadorMidia.h"
#include "../Headers/Musica.h"
#include "../Headers/Video.h"
#include "../Headers/Podcast.h"

int main() {
    GerenciadorMidia g;

    g.add(std::unique_ptr<Musica>(new Musica("Shape of You", 2017, 4.3, "Ed Sheeran", 320)));
    g.add(std::unique_ptr<Video>(new Video("Aula do Professor Beto", 2025)));
    g.add(std::unique_ptr<Podcast>(new Podcast("Aprendendo POO com Beto", 2025, 90, "Args",
        {"Step", "Make"})));

    g.list();
    g.openAll();
    g.filter("Ed");
    g.filter("1080p");

    return 0;
}
