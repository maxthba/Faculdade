/*Faça um programa que faz a leitura de um vetor X com N inteiros (N deve ser lido tb), com tamanho máximo
igual a 20. Gere um segundo vetor Y com os valores do vetor X em ordem inversa. Imprimir o vetor X e vetor com a
ordem inversa.*/

#include <stdio.h>

int main()
{
    int i, N;
    
    printf("Digite o tamanho que deseja para o vetor(menor que 20): ");
    scanf("%i", &N);
    while (N>20){
        printf("Digite um tamanho valido para o vetor(menor que 20): ");
        scanf("%i", &N);
    }

    int x[N], y[N];

    for(i=0; i<N; i++){
        printf("Digite o valor da posicao x[%i]: ", i);
        scanf("%i", &x[i]);
    }
    for (i=0; i<N; i++){
        y[i] = x[N-1-i];
        }

    printf("\nX Y\n");

    for(i=0; i<N; i++){
        printf("\n%i %i\n", x[i], y[i]);
    }

    return 0;
}
