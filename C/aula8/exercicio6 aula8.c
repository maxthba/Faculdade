#include <stdio.h>

int soma(int a, int*b)
{
    return (a + *b);
}

int main()
{
    int num1 = 3, num2 = 4;
    int s = soma(num1, &num2);
    printf("soma = %i", s);
    return 0;
}
