#include <stdio.h>

int main()
{
    int i, j;
    int matriz[5][3];
    int matriz_t[3][5];

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            printf("digite o valor do elemento[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
            matriz_t[j][i] = matriz[i][j];
            }
        }

    printf("matriz original: \n");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf(" %i ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("matriz transposta: \n");
    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            printf(" %i ", matriz_t[i][j]);
        }
        printf("\n");
    }
    return 0;
}

