#include <stdio.h>
#include <stdlib.h>

void trocarEndereco(int *x, int *y)
{
    int *aux;

    aux = &x;
    x = &y; 
    y = &aux; 
}

int main()
{
    int a = 10;
    int b = 5000;

    trocarEndereco(&a, &b);
    printf("a = %d\nb = %d\n", a, b);

    return 0;
}