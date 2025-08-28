#include <stdio.h>

int main()
{
    int i, j, L , C, maior;
    int matriz[5][5];

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("digite o valor do elemento[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
            if(i==0 && j==0){
                maior = matriz[i][j];
                L=i;
                C=j;
            }
            else if (maior<matriz[i][j]){
                maior = matriz[i][j];
                L=i;
                C=j;
            }
        }
    }

    printf("O maior numero dentro da matriz eh %i na linha %i coluna %i", maior, L, C);
    return 0;
}
