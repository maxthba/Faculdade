#include <stdio.h>

int main()
{
    int i, j, L , C, menor, maior, soma;
    int matriz[7][7];
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("digite o valor do elemento[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
    for(i=0; i<10; i++){
        soma += matriz[4][i];
    }
    for(i=0; i<10; i++){
        if (i==0){
            menor = matriz[i][5];
        }
        else if(menor>matriz[i][5]){
            menor = matriz[i][5];
        }
    }
    for (i=0; i<10; i++){
        for(j=0; j<10; j++){
            if (i==0 && j==0){
                maior = matriz[i][j];
                L=i;
                C=j;
            }
            else if(i==j && maior<matriz[i][j]){
                maior = matriz[i][j];
                L=i;
                C=j;
            }
        }
    }
    printf("A soma da linha 4 eh: %i\nO menor numero da coluna 5 eh: %i\nO maior elemento da diagonal principal eh: %i na posicao [%i][%i]", soma, menor, maior, L, C );
    return 0;
}

