#include <stdio.h>
#include <stdlib.h>

int soma(int N){
    if(N == 1) return 1;
    else return (N + soma(N-1));
}

int main(){
    int N;
    printf("Digite um numero para calcular a soma de 1 ate ele: ");
    scanf("%i", &N);
    int somatoria = soma(N);
    printf("A soma de 1 ate %i e: %i\n", N, somatoria);
    
    return 0;
}