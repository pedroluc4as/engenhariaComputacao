#include <stdio.h>
#include <stdlib.h>

#define TAM 20000000

int main()
{
    int *v;
    long int quant, i;

    v = malloc(TAM * sizeof(int));

    quant =0;
    for (i=0; i <TAM; i++)
    {
        if (v[i] == 0) 
            quant ++;
    }

    if (quant == TAM)
        printf("TODAS as posições zeradas!\n");
    else
        printf("quantidade de posições zeradas: %ld\n", quant);

    free(v);
    v = NULL;
}