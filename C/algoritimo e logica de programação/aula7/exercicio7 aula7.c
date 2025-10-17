#include <stdio.h>
#include <string.h>

int main()
{
    char string[20];
    printf("digite palavras com espaco entre elas: ");
    scanf(" %[^\n]", string);

    for (int i = 0; string[i]!='\0'; i++){
        if(string[i] == ' '){
            printf("\n");
        }
        else{
            printf("%c", string[i]);
        }
    }


    return 0;
}
