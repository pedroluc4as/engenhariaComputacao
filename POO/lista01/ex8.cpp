#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produto
{
private:
    string nome;
    float preco;
public:
    Produto(string nome, float preco)
    : nome(std::move(nome)), preco(preco) {}

    ~Produto(){cout << "destruído:'" << nome << "\n'";};
    string getNome() const { return nome; }
    float getPreco() const { return preco; }
};

class ItemCarrinho
{
private:
    const Produto* produto;
    int quantidade;
public:
    ItemCarrinho(const Produto* p, int qtd)
    : produto(p), quantidade(qtd) {}

    float getSubtotal() const {
        return produto->getPreco() * quantidade;
    }
    void exibir() const {
        cout << "      - " << produto->getNome() << " | Qtd: " << quantidade
             << " | Subtotal: R$" << getSubtotal() << endl;
    }
};

class CarrinhoDeCompras
{
private:
    vector <ItemCarrinho> itens;
public:
    CarrinhoDeCompras() {}

    void adicionarProduto(const Produto* produto, int quantidade) 
    {
        itens.push_back(ItemCarrinho(produto, quantidade));
    }

    float calcularTotal() const 
    {
        float total = 0.0f;

        for (const auto& item : itens) 
        {
            total += item.getSubtotal();
        }
        return total;
    }

    const vector<ItemCarrinho>& getItens() const 
    {
        return itens;
    }
};

class InformacoesPagamento
{
private:
    string metodo; 
public:
    InformacoesPagamento(string metodo)
    : metodo(std::move(metodo)) {}
    
    string getMetodo() const { return metodo; }
};

class Pedido
{
private:
    vector<ItemCarrinho> itensComprados; 
    InformacoesPagamento infoPagamento;
    float valorTotal;
public:
    Pedido(const CarrinhoDeCompras& carrinho, const InformacoesPagamento& info)
    : itensComprados(carrinho.getItens()), infoPagamento(info), valorTotal(carrinho.calcularTotal()) {}

    void exibir() const {
        cout << "PEDIDO GERADO" << endl;
        cout << "  Método de Pagamento: " << infoPagamento.getMetodo() << endl;
        cout << "  Itens do Pedido:" << endl;

        for (const auto& item : itensComprados) 
        {
            item.exibir();
        }
        cout << "  VALOR TOTAL: R$" << valorTotal << endl;
    }
};

int main() {
    // Produtos que existem na loja
    Produto p1("Notebook Gamer", 5000.0f);
    Produto p2("Cadeira de Escritório", 800.0f);
    Produto p3("Monitor 27 polegadas", 1200.0f);

    // 1. Cliente cria um carrinho e adiciona produtos
    CarrinhoDeCompras meuCarrinho;
    meuCarrinho.adicionarProduto(&p1, 1);
    meuCarrinho.adicionarProduto(&p2, 2);

    cout << "Total no carrinho: R$" << meuCarrinho.calcularTotal() << endl;
    cout << "\n... Finalizando a compra\n\n";

    // 2. Cliente fornece as informações de pagamento
    InformacoesPagamento pgto("Cartão de Crédito");

    // 3. O sistema gera um pedido a partir do carrinho e do pagamento
    Pedido meuPedido(meuCarrinho, pgto);
    meuPedido.exibir();

    return 0;
}