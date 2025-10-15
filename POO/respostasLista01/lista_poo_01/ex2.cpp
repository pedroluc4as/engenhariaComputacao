#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Musica {
    string titulo, artista;
    int duracaoSeg;
public:
    Musica(const string& t, const string& art, int d)
        : titulo(t), artista(art), duracaoSeg(d) {
        cout << "[construtor] Musica: " << titulo << "\n";
    }
    ~Musica(){ cout << "[destrutor] Musica: " << titulo << "\n"; }

    string info() const {
        return titulo + " - " + artista + " (" + to_string(duracaoSeg) + "s)";
    }
};

/* Playlist COMPÕE músicas (vector<Musica>) */
class Playlist {
    string nome;
    vector<Musica> faixas; // composição
public:
    Playlist(const string& n) : nome(n) {
        cout << "[construtor] Playlist: " << nome << "\n";
    }
    ~Playlist(){ cout << "[destrutor] Playlist: " << nome << "\n"; }

    void adicionar(const Musica& m){ faixas.push_back(m); }
    void listar() const{
        cout << "Playlist '" << nome << "':\n";
        for (auto& m : faixas) cout << " - " << m.info() << "\n";
    }
};

/* Usuario AGREGA Playlists (não é dono do ciclo de vida) */
class Usuario {
    string nome;
    vector<Playlist*> playlists; // agregação
public:
    Usuario(const string& n) : nome(n) {
        cout << "[construtor] Usuario: " << nome << "\n";
    }
    ~Usuario(){ cout << "[destrutor] Usuario: " << nome << "\n"; }

    void vincular(Playlist* p){ playlists.push_back(p); }
    void listar() const{
        cout << "Usuario " << nome << " possui " << playlists.size() << " playlists.\n";
        for (auto* p : playlists) p->listar();
    }
};

int main(){
    Playlist rock("Rock");
    rock.adicionar(Musica("Back In Black", "AC/DC", 255));
    rock.adicionar(Musica("Creep", "Radiohead", 238));

    Usuario u("Beto");
    u.vincular(&rock); // agregação: guarda ponteiro, não deleta

    u.listar();
    return 0;
}
