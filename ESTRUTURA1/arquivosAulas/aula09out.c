//soma subtração e multiplicação de dois valores
#include <stdio.h>
#include <stdlib.h>

void opera(int x, int y, int *soma, int *sub, int *mult, int *div){
    *soma = x + y;
    *sub  = x - y;
    *mult = x * y;
};

int main(){
    int plus = 0, less = 0, mult = 0, div = 0;

    opera(20, 5, &plus, &less, &mult, &div);

    printf("soma: \n", plus);
    printf("sub: \n", less);
    printf("mult: \n", mult);
    printf("div: \n", div);

    return 0;
}