#include <stdio.h>

int soma(int a, int*b)
{
    return(a + *b);
}

int main()
{
    int num1 = 3, num2 = 4;
    int*p = &num2;
    int s = soma(num1, p);
    printf("Soma = %i", s);
    return 0;
}
