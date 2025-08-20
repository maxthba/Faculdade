/*Faça um programa que faz a leitura de um vetor X com N inteiros (N deve ser lido tb), com tamanho máximo
igual a 20. Percorra esse vetor identificando a posição do menor e maior. Imprimir o vetor lido, os índices
encontrados e respectivos valores.*/

#include <stdio.h>

int main()
{
    int i, N, maior, menor, vetor_maior, vetor_menor;
    
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
            vetor_maior = i;
            vetor_menor = i;
        }

        if (x[i]>maior){
            maior = x[i];
            vetor_maior = i;
        }

        if (x[i]<menor){
            menor = x[i];
            vetor_menor = i;
        }
    }

    printf("O valor maior foi: %i na posicao %i\n", maior, vetor_maior);
    printf("O valor menor foi: %i na posicao %i\n", menor, vetor_menor);
    return 0;
}
