#include <stdio.h>
#include <string.h>

int main()
{
    char string[10];

    printf("digite algo: ");
    scanf(" %[^\n]", string);

    int tamanho = strlen(string);

    if (string[0]==string[tamanho-1]){
        printf("eh um palindromo");
    }
    else{
        printf("nao eh um palindromo");
    }
    
    return 0;
}
