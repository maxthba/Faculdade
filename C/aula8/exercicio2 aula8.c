#include <stdio.h>

int main()
{
    int variavel1=2, variavel2=3, variavel3;
    int*ponteiro1 = &variavel1;
    int*ponteiro2 = &variavel2;

    variavel3 = *ponteiro1 + *ponteiro2;

    ponteiro1= &variavel3;


    printf("variaveis 1: %i 2: %i 3: %i\n", variavel1, variavel2, variavel3);
    printf("ponteiros 1: %i 2: %i", *ponteiro1, *ponteiro2);

    return 0;
}
