#include <stdio.h>

int main(){
    double salario_inicial, percentual, salario_final;

    printf("Digite o salario: ");
    scanf("%lf", &salario_inicial);

    printf("Digite o percentual de reajuste: ");
    scanf("%lf", &percentual);
    
    salario_final = salario_inicial*(1+percentual/100);

    printf("Salario Final: %.2lf", salario_final);

    return 0;
}