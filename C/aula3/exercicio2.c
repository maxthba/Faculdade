#include <stdio.h>

int main(){
    int idade;
    double peso;

    printf("Digite sua idade: ");
    scanf("%i", &idade);

    printf("Digite seu peso: ");
    scanf("%lf", &peso);

    if((16<idade) && (idade<69) && (peso>=50)){
        printf("Esta apto a doar sangue");
    }

    else{
        printf("Nao esta apto");
    }

    return 0;
}