#include <stdio.h>
#include <stdbool.h>

int main(){
    int num;
    bool eh_primo = true;

    printf("Digite um numero: ");
    scanf("%i", &num);

    for(int i = 2; i<num-1; i++){
        if (num%i == 0){
            eh_primo = false;
        }
    }

    if(eh_primo){
        printf("Eh primo!!");
    }

    else{
        printf("Nao eh primo!!");
    }
    return 0;
}