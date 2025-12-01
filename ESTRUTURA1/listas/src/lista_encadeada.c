#include "lista_encadeada.h"
#include "ec_rgb_colors.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void delay_ms(unsigned int ms);

struct No
{
    struct Estudante estudante;
    struct No *proximo;
    struct No *anterior;
};

struct ListaEnc
{
    struct No *cabeca;
    struct No *cauda;
    unsigned int quantidade;
};

static struct Estudante le_GetEstudante(int i);
static struct Estudante le_criaEstudante();
static struct Estudante le_LeEstudante();
static void le_ImprimeEstudante(struct Estudante e);

struct ListaEnc *le_CriaLista();
int le_InsereListaInicio(struct ListaEnc *lista);
int le_InsereListaInicio2(struct ListaEnc *lista, struct Estudante e);
int le_InsereListaFim2(struct ListaEnc *lista, struct Estudante e);
int le_InsereListaOrdenada2(struct ListaEnc *lista, struct Estudante e);
void le_ImprimeLista(struct ListaEnc *lista);
void le_EstudantesArquivo(struct ListaEnc *lista);
void le_BuscaImprimeRetroativo(struct ListaEnc *lista, char *chave, int n);

static struct Estudante le_criaEstudante()
{
    struct Estudante e = {0, 0, ""};
    return e;
}

static struct Estudante le_LeEstudante()
{
    struct Estudante e = le_criaEstudante();
    printf("ID: ");
    scanf("%d", &e.ID);
    getchar();
    if (e.ID == 0) return e;
    printf("Nota: ");
    scanf("%f", &e.nota);
    printf("Nome: ");
    getchar();
    scanf("%[^\n]", e.nome);
    return e;
}

static void le_ImprimeEstudante(struct Estudante e)
{
    printf("%d\t", e.ID);
    printf("%4.2f\t", e.nota);
    printf("%s\n", e.nome);
    delay_ms(1000);
}

static struct Estudante le_GetEstudante(int i)
{
    struct Estudante e;
    if (i == 0) { e.ID = -1; e.nota = 9.0; strcpy(e.nome, "John von Neumann"); }
    if (i == 1) { e.ID = -2; e.nota = 9.7; strcpy(e.nome, "Edgar Frank Codd"); }
    if (i == 2) { e.ID = -3; e.nota = 9.9; strcpy(e.nome, "Donald Ervin Knuth"); }
    if (i > 2) { e.ID = 0; e.nota = 0; strcpy(e.nome, ""); }
    return e;
}

void le_InsereTestes(struct ListaEnc *lista)
{
    struct Estudante e;
    printf("Inserindo estudantes de Teste...\n");
    for (int i = 0; i < 3; i++)
    {
        e = le_GetEstudante(i);
        le_InsereListaInicio2(lista, e);
    }
}

struct ListaEnc *le_CriaLista()
{
    struct ListaEnc *lista = (struct ListaEnc *) malloc(sizeof(struct ListaEnc));
    if (lista == NULL)
    {
        ec_imprimirCor("ERRO: Memoria insuficiente", "RED");
        return NULL;
    }
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->quantidade = 0;
    return lista;
}

static int le_ListaNaoInicializada(struct ListaEnc *lista)
{
    if (lista == NULL)
    {
        ec_imprimirCor("Lista nao inicializada!", "Y");
        return 1;
    }
    return 0;
}

int le_TamanhoLista(struct ListaEnc *lista, int imprime)
{
    if (le_ListaNaoInicializada(lista)) return 0;
    if (imprime == 1)
        ec_imprimirCor("Quantidade de elementos da lista: %d", "Y", lista->quantidade);
    return lista->quantidade;
}

int le_ListaVazia(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista) || lista->quantidade == 0)
    {
        ec_imprimirCor("Lista vazia ou nao inicializada!\n", "Y");
        return 1;
    }
    return 0;
}

int le_ListaCheia(struct ListaEnc *lista)
{
    (void)lista; // Silencia o warning de parametro nao utilizado
    return 0;
}

int le_InsereListaInicio2(struct ListaEnc *lista, struct Estudante e)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    struct No *no = (struct No *) malloc(sizeof(struct No));
    if(no == NULL)
    {
        ec_imprimirCor("Erro de alocacao!\n", "R");
        return 0;
    }
    no->estudante = e;
    no->proximo = lista->cabeca;
    no->anterior = NULL;
    if (lista->cabeca != NULL) lista->cabeca->anterior = no;
    lista->cabeca = no;
    if (lista->cauda == NULL) lista->cauda = no;
    lista->quantidade++;
    return 1;
}

int le_InsereListaInicio(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    ec_imprimirCor("Insercao no inicio\n", "G");
    struct Estudante e;
    do
    {
        e = le_LeEstudante();
        if(e.ID == 0) break;
        le_InsereListaInicio2(lista, e);
    } while (e.ID > 0);
    return 1;
}

int le_InsereListaFim2(struct ListaEnc *lista, struct Estudante e)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    struct No *no = (struct No *) malloc(sizeof(struct No));
    if(no == NULL) return 0;
    no->estudante = e;
    no->proximo = NULL;
    no->anterior = lista->cauda;
    if (lista->cauda != NULL) lista->cauda->proximo = no;
    lista->cauda = no;
    if (lista->cabeca == NULL) lista->cabeca = no;
    lista->quantidade++;
    return 1;
}

int le_InsereListaFim(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    ec_imprimirCor("Insercao no fim\n", "G");
    struct Estudante e;
    do
    {
        e = le_LeEstudante();
        if(e.ID == 0) break;
        le_InsereListaFim2(lista, e);
    } while (e.ID > 0);
    return 1;
}

int le_InsereListaOrdenada2(struct ListaEnc *lista, struct Estudante e)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    if (lista->cabeca == NULL || e.ID < lista->cabeca->estudante.ID) return le_InsereListaInicio2(lista, e);
    if (e.ID >= lista->cauda->estudante.ID) return le_InsereListaFim2(lista, e);
    
    struct No *atual = lista->cabeca;
    while (atual != NULL && atual->estudante.ID < e.ID) atual = atual->proximo;
    
    struct No *no = (struct No *) malloc(sizeof(struct No));
    if (!no) return 0;
    no->estudante = e;
    no->proximo = atual;
    no->anterior = atual->anterior;
    if (atual->anterior) atual->anterior->proximo = no;
    atual->anterior = no;
    lista->quantidade++;
    return 1;
}

int le_InsereListaOrdenada(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    ec_imprimirCor("Insercao Ordenada\n", "G");
    struct Estudante e;
    do
    {
        e = le_LeEstudante();
        if(e.ID == 0) break;
        le_InsereListaOrdenada2(lista, e);
    } while (e.ID > 0);
    return 1;
}

int le_RemoveTodos(struct ListaEnc *lista, int exige_confirmacao)
{
    if(le_ListaNaoInicializada(lista)) return 0;
    if (exige_confirmacao)
    {
        char c;
        printf("Confirmar remocao total (S/N)? ");
        scanf(" %c", &c);
        if (c != 'S' && c != 's') return 0;
    }
    struct No *atual = lista->cabeca;
    while(atual != NULL)
    {
        struct No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->quantidade = 0;
    return 1;
}

void le_DestroiLista(struct ListaEnc **lista)
{
    if (lista == NULL || *lista == NULL) return;
    le_RemoveTodos(*lista, 0);
    free(*lista);
    *lista = NULL;
}

void le_EnderecosNos(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista)) return;
    struct No *atual = lista->cabeca;
    while(atual != NULL)
    {
        // CAST para (void *) remove o warning do %p
        printf("No: %p | Ant: %p | Prox: %p | ID: %d\n", 
               (void*)atual, (void*)atual->anterior, (void*)atual->proximo, atual->estudante.ID);
        atual = atual->proximo;
    }
}

void le_ImprimeLista(struct ListaEnc *lista)
{
    if (le_ListaNaoInicializada(lista)) return;
    struct No *atual = lista->cabeca;
    while(atual != NULL)
    {
        le_ImprimeEstudante(atual->estudante);
        atual = atual->proximo;
    }
}

struct Estudante le_BuscaChave(struct ListaEnc *lista, char *chave)
{
    struct Estudante e = {0,0,""};
    if(le_ListaNaoInicializada(lista)) return e;
    struct No *atual = lista->cabeca;
    int idBusca = atoi(chave);
    while(atual != NULL)
    {
        if (idBusca > 0 && atual->estudante.ID == idBusca) return atual->estudante;
        if (strcmp(atual->estudante.nome, chave) == 0) return atual->estudante;
        atual = atual->proximo;
    }
    return e;
}

struct Estudante le_RemoveChave(struct ListaEnc *lista, char *chave)
{
    struct Estudante e = {0,0,""};
    if(le_ListaNaoInicializada(lista)) return e;
    struct No *atual = lista->cabeca;
    int idBusca = atoi(chave);
    while(atual != NULL)
    {
        int match = (idBusca > 0 && atual->estudante.ID == idBusca) || (strcmp(atual->estudante.nome, chave) == 0);
        if(match)
        {
            e = atual->estudante;
            if (atual->anterior) atual->anterior->proximo = atual->proximo;
            else lista->cabeca = atual->proximo;
            if (atual->proximo) atual->proximo->anterior = atual->anterior;
            else lista->cauda = atual->anterior;
            free(atual);
            lista->quantidade--;
            return e;
        }
        atual = atual->proximo;
    }
    return e;
}

void le_BuscaImprimeRetroativo(struct ListaEnc *lista, char *chave, int n)
{
    if(le_ListaNaoInicializada(lista)) return;
    struct No *atual = lista->cabeca;
    int idBusca = atoi(chave);
    struct No *encontrado = NULL;
    while(atual != NULL)
    {
        if ((idBusca > 0 && atual->estudante.ID == idBusca) || (strcmp(atual->estudante.nome, chave) == 0))
        {
            encontrado = atual;
            break;
        }
        atual = atual->proximo;
    }
    if (encontrado)
    {
        printf("--- Estudante Encontrado ---\n");
        le_ImprimeEstudante(encontrado->estudante);
        printf("--- %d Anteriores ---\n", n);
        struct No *ante = encontrado->anterior;
        for (int i=0; i<n && ante != NULL; i++)
        {
            le_ImprimeEstudante(ante->estudante);
            ante = ante->anterior;
        }
    }
    else ec_imprimirCor("Estudante nao encontrado\n", "R");
}

void le_EstudantesArquivo(struct ListaEnc *lista)
{
    if(le_ListaNaoInicializada(lista)) return;
    char arquivo[100];
    int op;
    printf("Arquivo: ");
    scanf(" %[^\n]", arquivo);
    FILE *f = fopen(arquivo, "r");
    if(!f) { ec_imprimirCor("Erro abrir arquivo\n", "R"); return; }
    printf("1-Inicio 2-Fim 3-Ordenado: ");
    scanf("%d", &op);
    struct Estudante e;
    while(fscanf(f, "%d;%f;%[^\n]", &e.ID, &e.nota, e.nome) == 3 || fscanf(f, "%d %f %[^\n]", &e.ID, &e.nota, e.nome) == 3)
    {
        if(op==1) le_InsereListaInicio2(lista, e);
        else if(op==2) le_InsereListaFim2(lista, e);
        else le_InsereListaOrdenada2(lista, e);
    }
    fclose(f);
}

void delay_ms(unsigned int ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
}