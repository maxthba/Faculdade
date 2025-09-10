#include <stdio.h>

int main()
{
    double variavel1=5, variavel2=2;
    double*ponteiro1 = &variavel1;
    double*ponteiro2 = &variavel2;

    double variavel3 = *ponteiro1 * *ponteiro2;

    ponteiro2 = &variavel3;
    *ponteiro2 = variavel3/2;

    printf("variaveis 1: %.2f 2: %.2f\nPonteiros 1: %.2f 2: %.2f", variavel1, variavel2, *ponteiro1, *ponteiro2);
    return 0;
}
