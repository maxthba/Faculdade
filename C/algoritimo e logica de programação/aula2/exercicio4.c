#include <stdio.h>

int main(){
    double peso, altura;
    int imc;

    printf("Digite seu peso: ");
    scanf("%lf", &peso);

    printf("Digite sua altura: ");
    scanf("%lf", &altura);

    imc = peso/(altura*altura);

    printf("IMC: %i", imc);
    
    return 0;
}