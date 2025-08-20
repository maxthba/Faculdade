/*Faça um programa em C que lê um vetor de inteiros positivos de 20 posições. A partir desse preenchimento,
percorra esse vetor identificando a quantidade de números pares e a quantidade de múltiplos de 5. Em seguida
imprima essas informações.*/

#include <stdio.h>
int main()
{
    int qnt_p = 0, qnt_5 =0, x[20], i;

    for (i=0; i<20;i++){
        printf("digite o valor de x[%i]: ", i);
        scanf("%i", &x[i]);
        
        if(x[i]%2 == 0){
            qnt_p +=1;
        }
        if(x[i]%5 == 0){
            qnt_5 +=1;
        }
    }
    printf("pares: %i\n", qnt_p);
    printf("divisiveis por 5: %i", qnt_5);
    return 0;
}
