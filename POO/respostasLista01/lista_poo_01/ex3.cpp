#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cliente {
    string nome, email;
public:
    Cliente(const string& n, const string& e) : nome(n), email(e) {
        cout << "[construtor] Cliente: " << nome << "\n";
    }
    ~Cliente(){ cout << "[destrutor] Cliente: " << nome << "\n"; }
    string getNome() const { return nome; }
};

class ItemPedido {
    string produto;
    int qtd;
    double precoUnit;
public:
    ItemPedido(const string& p, int q, double pu)
        : produto(p), qtd(q), precoUnit(pu) {
        cout << "[construtor] Item: " << produto << "\n";
    }
    ~ItemPedido(){ cout << "[destrutor] Item: " << produto << "\n"; }
    double subtotal() const { return qtd * precoUnit; }
    string info() const {
        return produto + " x" + to_string(qtd) + " = " + to_string(subtotal());
    }
};

/* Pedido COMPÕE itens (vector<ItemPedido>) e AGREGA cliente (ponteiro) */
class Pedido {
    int numero;
    Cliente* cliente; // agregação
    vector<ItemPedido> itens; // composição
public:
    Pedido(int num, Cliente* c) : numero(num), cliente(c) {
        cout << "[construtor] Pedido #" << numero << "\n";
    }
    ~Pedido(){ cout << "[destrutor] Pedido #" << numero << "\n"; }

    void adicionar(const ItemPedido& it){ itens.push_back(it); }
    double total() const {
        double t=0.0; for (const auto& it : itens) t += it.subtotal(); return t;
    }
    void resumo() const {
        cout << "Pedido #" << numero << " de " << cliente->getNome() << ":\n";
        for (auto& it : itens) cout << " - " << it.info() << "\n";
        cout << "Total = " << total() << "\n";
    }
};

int main(){
    Cliente c("Alice", "alice@mail.com");
    Pedido p(101, &c);
    p.adicionar(ItemPedido("Teclado", 1, 199.9));
    p.adicionar(ItemPedido("Mouse", 2, 79.9));
    p.resumo();
    return 0;
}
