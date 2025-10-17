#include <stdio.h>
#include <stdbool.h>

bool ehprimorec(int N, int divisor){
    if(divisor == 1) return true;
    if (N % divisor == 0) return false;
    else return ehprimorec(N, divisor -1);
}

bool ehprimo (int N) {
    if(N <=2) return (N ==2);
    else return ehprimorec(N, N-1);
}

int main(){
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%i", &numero);

    if(ehprimo(numero)) printf("O numero %i eh primo.\n", numero);
    else printf("O numero %i nao eh primo.\n", numero);
}