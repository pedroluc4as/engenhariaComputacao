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
    Usuario(string id, string nome)
    : id(std::move(id)), username(std::move(username)){}
};

class Playlist
{
private:
    string nome;
    string estilo;
    int qtdMsc;
public:
    Playlist(string nome, string estilo, int qtdMsc)
    : nome(std::move(nome)), estilo(std::move(estilo)), qtdMsc(std::move(qtdMsc)) {}

};