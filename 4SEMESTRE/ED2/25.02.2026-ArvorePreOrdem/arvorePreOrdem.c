#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No *criarNo(int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        printf("Fechando o programa...\n");
        return 0;
    }
    novoNo->valor = valor; //novoNo recebe o valor passado como parametro
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    //define a esq e direita da arvore como NULL,
    //pois o No ainda nao possui filhos pois acabou de ser criado!
    return novoNo; //retorna o novo no Vazio, 
    //porem apenas com o valor do No passado por parametro
}

void preOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int main()
{
    No *raiz = criarNo(50);
    raiz->esquerda = criarNo(28);
    raiz->direita = criarNo(80);
    raiz->esquerda->esquerda = criarNo(12);
    raiz->direita->direita = criarNo(96);
    raiz->esquerda->direita = criarNo(39);
    raiz->direita->direita->direita = criarNo(100);


    printf("Valores em pre ordem: ");
    preOrdem(raiz);
    printf("\n");

    return 0;
}