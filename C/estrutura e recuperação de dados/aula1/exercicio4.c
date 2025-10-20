#include <stdio.h>
#include <stdlib.h>
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

void vetprimo (int*sz, int vet[], int num){
    *sz = 0;
    for (int i = 0; i<=num; i++){
        if (ehprimo(i) == true){
            vet[*sz] = i;
            (*sz)++;            
        }
    }
}

int main(){
    int num = 9, sz = 0;
    int vet[sz+1];
    vetprimo(&sz, vet, num);
    for (int i = 0; i<sz; i++){
        printf("%i", vet[i]);
    }
    return 0;
}