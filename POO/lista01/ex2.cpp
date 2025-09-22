#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Usuario 
{
private:
    string id;
    string username;
public:
    Usuario(string id, string username)
    : id(std::move(id)), username(std::move(username)){}

    string getNome() const { return username; }
};

class Playlist
{
private:
    string nome;
    string estilo;
    vector <string> musicas;
public:
    Playlist(string nome, string estilo)
    : nome(std::move(nome)), estilo(std::move(estilo)) {}

    void adicionarMusica(const string& musica) 
    {
        musicas.push_back(musica);
    }

    void exibirMusicas() const {
        cout << "Playlist: " << nome << " (" << estilo << ")\n";
        if (musicas.empty()) {
            cout << "  (sem músicas)\n";
        } else {
            for (const auto& m : musicas) {
                cout << "  - " << m << "\n";
            }
        }
    }
};

class Perfil
{
private:
    Usuario *user;
    vector <Playlist> playlists;
public:
    Perfil(Usuario *user)
    : user(user) {}


    void adicionarPlaylist(const Playlist& p) {
        playlists.push_back(p);
    }

    void exibirPlaylists() const {
        cout << "Playlists do usuário: " << user->getNome() << "\n";
        if (playlists.empty()) {
            cout << "  (nenhuma playlist cadastrada)\n";
        } else {
            for (const auto& p : playlists) {
                p.exibirMusicas();
            }
        }
    }
};

// ---------------------------
// Teste
int main() {
    Usuario u1("001", "Sperandio");
    Perfil perfil(&u1);

    Playlist p1("Treino", "Hip Hop");
    p1.adicionarMusica("Lose Yourself - Eminem");
    p1.adicionarMusica("Till I Collapse - Eminem");

    Playlist p2("Relax", "Lo-fi");
    p2.adicionarMusica("Lofi Chill Beats");
    p2.adicionarMusica("Rain Sounds");

    perfil.adicionarPlaylist(p1);
    perfil.adicionarPlaylist(p2);

    perfil.exibirPlaylists();

    return 0;
}