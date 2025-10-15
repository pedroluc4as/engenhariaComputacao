#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
    string nome; double preco;
public:
    Produto(const string& n, double p) : nome(n), preco(p){
        cout << "[construtor] Produto: " << nome << "\n";
    }
    ~Produto(){ cout << "[destructor] Produto: " << nome << "\n"; }
    string getNome() const { return nome; }
    double getPreco() const { return preco; }
};

/* Item do carrinho AGREGA Produto (ponteiro) */
class ItemCarrinho {
    Produto* produto; int qtd;
public:
    ItemCarrinho(Produto* p, int q) : produto(p), qtd(q){
        cout << "[construtor] ItemCarrinho de " << (p ? p->getNome() : "?") << "\n";
    }
    ~ItemCarrinho(){ cout << "[destructor] ItemCarrinho\n"; }
    double subtotal() const { return (produto ? produto->getPreco() : 0.0) * qtd; }
    string info() const {
        return (produto ? produto->getNome() : "?") + string(" x") + to_string(qtd) +
               " = " + to_string(subtotal());
    }
};

/* Carrinho COMPÕE itens */
class Carrinho {
    veconstrutor<ItemCarrinho> itens; // composição
public:
    Carrinho(){ cout << "[construtor] Carrinho\n"; }
    ~Carrinho(){ cout << "[destructor] Carrinho\n"; }
    void add(const ItemCarrinho& it){ itens.push_back(it); }
    double total() const { double t=0; for (auto& i : itens) t+=i.subtotal(); return t; }
    void listar() const { for (auto& i : itens) cout << " - " << i.info() << "\n"; }
};

class Pagamento {
    string modo, status;
public:
    Pagamento(const string& m) : modo(m), status("pendente"){
        cout << "[construtor] Pagamento (" << modo << ")\n";
    }
    ~Pagamento(){ cout << "[destructor] Pagamento (" << modo << ")\n"; }
    void aprovar(){ status = "aprovado"; }
    void reprovar(){ status = "reprovado"; }
    string getStatus() const { return status; }
};

/* Pedido COMPÕE carrinho e pagamento */
class Pedido {
    int numero;
    Carrinho carrinho;  // composição
    Pagamento pagamento; // composição
public:
    Pedido(int num, const string& modoPgto)
        : numero(num), carrinho(), pagamento(modoPgto) {
        cout << "[construtor] Pedido #" << numero << "\n";
    }
    ~Pedido(){ cout << "[destructor] Pedido #" << numero << "\n"; }

    Carrinho& getCarrinho(){ return carrinho; }
    Pagamento& getPagamento(){ return pagamento; }

    void fechar(bool aprovar){
        if (aprovar) pagamento.aprovar(); else pagamento.reprovar();
        cout << "Pedido #" << numero << " total=" << carrinho.total()
             << " status=" << pagamento.getStatus() << "\n";
    }
};

int main(){
    Produto p1("Livro", 80.0), p2("Headset", 250.0);

    Pedido ped(5001, "pix");
    ped.getCarrinho().add(ItemCarrinho(&p1, 2));
    ped.getCarrinho().add(ItemCarrinho(&p2, 1));

    ped.getCarrinho().listar();
    ped.fechar(true); // aprova pagamento
    return 0;
}
