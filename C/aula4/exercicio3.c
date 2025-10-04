#include <stdio.h>

int main(){
    int num, fatorial;
    do
    {
        printf("Digite um numero: ");
        scanf("%i", &num);

        if(num == 0){
            break;
        }

        fatorial=1;
        for(int i=1; i<=num; i++){
            fatorial = fatorial*i;
        }

        printf("Fatorial do numero eh: %i\n", fatorial);
    } while (num !=0);
    return 0;
}