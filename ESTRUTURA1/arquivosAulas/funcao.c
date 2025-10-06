#include <stdio.h>
#include <stdlib.h>

int soma (int x, int y);

int main()
{
    int a = 1, b;
    int s;

    while(a > 0)
    {
        printf("informe dois numeros: ");
        scanf("%d %d", &a, &b);

        s = soma(a, b);
        printf("%d \n", s);
    }
}

    int soma(int x , int y)
    {
        int s;
        s = x + y;

        return s;
    }