#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100];
    printf("digite seu nome completo: ");
    scanf(" %[^\n]", string);

    for (int i = 0; string[i] != '\0'; i++){
        if(i==0){
            printf("%c", string[i]);
        }
        else if(string[i-1]==' '){
            printf("%c", string[i]);
        }
    }

    return 0;
}
