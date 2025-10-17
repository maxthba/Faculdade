/*Faça um programa em C que lê um vetor de inteiros de 20 posições. A partir desse preenchimento, ordene esse
vetor em ordem decrescente (sem criar outro vetor). Em seguida, imprima esse vetor ordenado.*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x[20], i, troca;
    bool swap = true;

    for (i=0;i<20;i++){
        printf("digite o valor de x[%i]: ", i);
        scanf("%i", &x[i]);
    }
    do{
        swap = false;
        for(i=0;i<20;i++){
            if(x[i]>x[i-1]){
                troca = x[i];
                x[i]=x[i-1];
                x[i-1]= troca;
                swap = true;
            }
        }
    }
    while(swap == true);

    printf("x em ordem decrescente");
    for (i=0;i<20;i++){
        printf("\n%i\n", x[i]);
    }
    return 0;
}