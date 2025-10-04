#include <stdio.h>

int main(){
    int soma =0, valor1, valor2, valor3, maior;
    
    printf("Digite o valor1: ");
    scanf("%i", &valor1);
    soma +=valor1;
    maior = valor1;

    printf("Digite o valor2: ");
    scanf("%i", &valor2);
    soma +=valor2;
    if (valor2>maior){
        maior = valor2;
    }

    printf("Digite o valor3: ");
    scanf("%i", &valor3);
    soma +=valor3;
    if (valor3>maior){
        maior = valor3;
    }

    if(soma-maior >= maior){
        printf("Triangulo valido!!");
    }
    else{
        printf("Triangulo invalido!!");
    }
    
    return 0;
}