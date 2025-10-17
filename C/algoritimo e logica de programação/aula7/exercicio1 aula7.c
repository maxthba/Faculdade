#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    char string[20];
    int contador=0;

    printf("digite um caractere: ");
    scanf(" %c", &c);
    getchar();

    printf("digite algo de ate 20 caracteres: ");
    scanf(" %[^\n]", string);
    
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == c){
            contador +=1;
        }
    }

    printf("o caractere apareceu %i vezes na frase", contador);

    return 0;
}
