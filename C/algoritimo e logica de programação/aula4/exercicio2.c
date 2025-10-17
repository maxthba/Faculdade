#include <stdio.h>

int main(){
    int num, menor =100000, maior = 0, qnt = 0;

    do
    {
        printf("Digite um numero: ");
        scanf("%i", &num);
        qnt += 1;

        if (num == 0){
            break;
        }

        if(maior<num){
            maior=num;
        }

        if(menor>num){
            menor=num;
        }

    } while (num != 0);
    
    printf("Maior: %i Menor: %i Quantos numeros foram digitados: %i", maior, menor, qnt);
    return 0;
}