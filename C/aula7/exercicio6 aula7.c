#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char vogais[]= "aeiou";
    char consoantes[]= "bcdfghjklmnpqrstvwxyz" ;

    char string[20];
    printf("digite qualquer coisa: ");
    scanf(" %[^\n]", string);
    int contadorV=0;
    int contadorC=0;

    for (int i = 0; string[i] != '\0'; i++){
        char caractere = tolower(string[i]);
        for (int x = 0; vogais[x] != '\0'; x++){
            if(caractere == vogais[x]){
                contadorV += 1;
            }
        }
        for (int x = 0; consoantes[x] != '\0'; x++){
            if(caractere == consoantes[x]){
                contadorC += 1;
            }
        }

    }

    printf("Vogais = %i\nConsoantes = %i", contadorV, contadorC);

    return 0;
}
