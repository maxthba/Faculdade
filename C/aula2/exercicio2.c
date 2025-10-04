#include <stdio.h>

int main(){
    int segundos, minutos, horas;
    printf("Digite quantos segundos: ");
    scanf("%i", &segundos);

    minutos = segundos/60;
    segundos =  segundos % 60;

    horas = minutos/60;
    minutos = minutos % 60;

    printf("%i Horas %i Minutos %i Segundos", horas, minutos, segundos);

    return 0;
}