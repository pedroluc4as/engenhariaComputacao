#include<stdio.h>

int main()
{
    int a = 5;
    int *pa;
    pa = &a;

    printf("\n O endereço do ponteiro %p", &pa);
    printf("\n O endereço da variável que foi atribuída ao ponteiro %p", pa);
    printf("\n O valor da variável sendo impresso pelo ponteiro %d", *pa);

    printf("\n O endereço da variável a %p \n", &a);

    return 0;
}
