#include <stdio.h>

int soma (int a, int*b)
{
    return(a + *b);
}

int main()
{
    int num1 = 3, num2 = 4;
    int*p = &num2;
    int s = soma(*p, &num1);
    printf("soma = %i", s);
    return 0;
}
