/*Faça um programa em C que lê um vetor de reais de 20 posições. A partir desse preenchimento, calcule a média
dos elementos lidos e quantos elementos são menores que a média.*/

#include <stdio.h>

int main()
{
    int x [20], media, qnt_e =0, i;

    for (i=0;i<20;i++){
        printf("Digite o valor de x[%i]", i);
        scanf("%i", &x[i]);
        media += x[i];
    }

    media = media / 20;

    for (i=0;i<20;i++){
        if(x[i]<media){
            qnt_e +=1;
        }
    }
    printf("quantidade menor que a media eh: %i", qnt_e);
    return 0;
}
