#include <stdio.h>

int main()
{
    int i, j, N, soma=0;
    printf("digite qual a ordem da matriz(menor que 20): ");
    scanf("%i", &N);

    while(N>20){
        printf("digite um numero valido (menor que 20): ");
        scanf("%i", &N);
    }
    int matriz[N][N];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("digite o valor do elemento[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
            if(i==j){
                soma +=matriz[i][j];
            }
        }
    }
    printf("matriz digitada completa: \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf(" %i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("A soma da diagonal principal eh = %i", soma);
    return 0;
}
