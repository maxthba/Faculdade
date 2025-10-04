#include <stdio.h>

int main(){
    double nota;

    printf("Digite uma nota de 0 a 10: ");
    scanf("%lf", &nota);

    while (nota<0 || nota>10){
        printf("Digite uma nota de 0 a 10: ");
        scanf("%lf", &nota);
    }
    
    if(nota<5){
        printf("Insuficiente!!");
    }

    else if(nota>=5 && nota<6.9){
        printf("Regular!!");
    }

    else if(nota>=7 && nota<8.9){
        printf("Bom!!");
    }

    else if(nota>=9){
        printf("Exelente!!");
    }
    return 0;
}