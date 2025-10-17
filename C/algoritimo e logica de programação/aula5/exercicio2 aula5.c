/*Faça um programa que faz a leitura de um vetor X com N inteiros (N deve ser lido tb), com tamanho máximo
igual a 20. Percorra esse vetor identificando o menor e maior valor. Imprimir o vetor lido e os valores 
encontrados.*/

#include <stdio.h>

int main()
{
    int i, N, maior, menor;
    
    printf("Digite o tamanho que deseja para o vetor(menor que 20): ");
    scanf("%i", &N);
    while (N>20){
        printf("Digite um tamanho valido para o vetor(menor que 20): ");
        scanf("%i", &N);
    }

    int x[N];
    
    for (i = 0;i<N;i++){
        printf("digite o valor de x[%i]: ", i);
        scanf("%i", &x[i]);

        if (i==0){
            menor = x[i];
            maior = x[i];
        }

        if (x[i]>maior){
            maior = x[i];
        }

        if (x[i]<menor){
            menor = x[i];
        }
    }

    printf("O valor maior foi: %i\nE o menor foi: %i", maior, menor);
    return 0;
}
