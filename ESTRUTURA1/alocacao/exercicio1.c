#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10000000

int main()
{
    int *inteiros;
    int cont = 0;

    inteiros = malloc (10000000 * sizeof(int));

    inteiros[1] = 3;

    for(int i = 0; i < TAMANHO; i++)
    {
        if(inteiros[i] == 0)
        {
            cont++;
        }
    }
    printf("%d\n",cont);

    free(inteiros);
    
    return 0;
}