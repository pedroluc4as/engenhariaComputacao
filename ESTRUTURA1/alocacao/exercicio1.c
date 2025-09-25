#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10000000

int main()
{
    int *vetorInteiros;
    int cont = 0;

    vetorInteiros = malloc (TAMANHO * sizeof(int));

    vetorInteiros[1] = 3;

    for(int i = 0; i < TAMANHO; i++)
    {
        if(vetorInteiros[i] == 0)
        {
            cont++;
        }
        if (cont == TAMANHO)
        {
            printf("todas as posições zeradas!\n");
        }
        
    }
    printf("quantidade de posições zeradas = %d \n",cont);

    free(vetorInteiros);
    vetorInteiros = NULL;
    
    return 0;
}