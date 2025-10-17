#include <stdio.h>
#include <stdlib.h>

int fatorial(int N){
    if(N == 0 || N == 1) return 1;
    else return (N * fatorial(N-1));
}

int main(){
    int N;
    printf("Digite um numero para calcular seu fatorial: ");
    scanf("%i", &N);

    int fat = fatorial(N);

    printf("O fatorial de %i e: %i\n", N, fat);
}