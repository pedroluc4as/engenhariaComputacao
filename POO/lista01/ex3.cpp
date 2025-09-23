#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ItemPedido
{
private:
    string produto;
    int qtdProduto;
    float precoUni;
public:
    ItemPedido(string produto, int qtdProduto, float precoUni)
    : produto(std::move(produto)), qtdProduto(qtdProduto), precoUni(precoUni) {}

    float getValor() const 
    {
        return qtdProduto * precoUni;
    }
};

class Pedido
{
private:
    string id;
    vector <ItemPedido> itens;
public:
    Pedido(string id)
    : id(std::move(id)) {}
    void registrarItem(const ItemPedido& item) 
    {
        itens.push_back(item);
    }

    float getValorTotal() const {
        float total = 0.0f;
        for (const auto& item : itens) {
            total += item.getValor();
        }
        return total;
    }
};

class Cliente
{
private:
    string nome;
    string id;
    vector <Pedido> pedidos;
public:
    Cliente(string nome, string id)
    : nome(std::move(nome)), id(std::move(id)) {}

    void registrarPedido(const Pedido& pedido) 
    {
        pedidos.push_back(pedido);
    }

};

class Loja
{
private:
    string nome;
    string id;
    vector <Cliente> clientes;
public:
    Loja(string nome, string id) 
    : nome(std::move(nome)), id(std::move(id)) {}

    void adicionarCliente(const Cliente& cliente) 
    {
        clientes.push_back(cliente);
    }
};

int main() {
    Loja minhaLoja("Minha Loja", "001");

    Cliente c1("Sperandio", "123");
    
    ItemPedido item1("Livro C++", 2, 50.0);
    ItemPedido item2("Mouse", 1, 75.50);
    
    Pedido pedido1 ("PED01");
    pedido1.registrarItem(item1);
    pedido1.registrarItem(item2);

    c1.registrarPedido(pedido1); 
    minhaLoja.adicionarCliente(c1);
    
    cout << "Valor total do pedido: R$" << pedido1.getValorTotal() << endl;

    return 0;
}