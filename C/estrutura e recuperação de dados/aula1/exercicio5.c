#include <stdio.h>
#include <stdlib.h>

void troca(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void ordenarCrescente(int sz, int vet[sz]) {
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (vet[i] > vet[j]) {
                troca(&vet[i], &vet[j]);
            }
        }
    }
}

int main() {
    int vet[5] = {5, 2, 9, 1, 7};
    int sz = 5; 

    printf("Vetor original:\n");
    for (int i = 0; i < sz; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    ordenarCrescente(sz, vet);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < sz; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
