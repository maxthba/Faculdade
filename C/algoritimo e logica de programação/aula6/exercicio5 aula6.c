#include <stdio.h>

int main()
{
    int i, j, k, a, b, l, c, aux;
    printf("digite a linha da matriz A:  ");
    scanf("%i", &a);

    printf("digite a coluna da matriz A:  ");
    scanf("%i", &b);

    printf("digite a linha da matriz B:  ");
    scanf("%i", &l);

    printf("digite a coluna da matriz B:  ");
    scanf("%i", &c);

    if (b!=l){
        printf("Impossivel fazer esta conta");
        return 1;
    }
    else{
        int matrizA[a][b];
        int matrizB[l][c];
        int matrizC[a][c];

        for(i=0; i<a; i++){
            for (j=0; j<b; j++){
                printf("digite o valor do elemento[%i][%i] da matriz A: ", i, j);
                scanf("%i", &matrizA[i][j]);
            }
        }
        for(i=0; i<l; i++){
            for (j=0; j<c; j++){
                printf("digite o valor do elemento[%i][%i] da matriz B: ", i, j);
                scanf("%i", &matrizB[i][j]);
            }
        }
        for (i=0; i<a; i++){
            for(j=0; j<c; j++){
                matrizC[i][j]=0;
                for(k=0; k<l; k++){
                    aux += matrizA[i][k]*matrizB[k][j];
                }

                matrizC[i][j]=aux;
                aux=0;
            }
        }


        printf("matrizA completa: \n");
        for(i=0; i<a; i++){
            for(j=0; j<b; j++){
                printf(" %i ", matrizA[i][j]);
            }
            printf("\n");
        }
        printf("matrizB completa: \n");
        for(i=0; i<l; i++){
            for(j=0; j<c; j++){
                printf(" %i ", matrizB[i][j]);
            }
            printf("\n");
        }
        printf("matrizC completa: \n");
        for(i=0; i<a; i++){
            for(j=0; j<c; j++){
                printf(" %i ", matrizC[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}

