#include <stdio.h>
#include <string.h>

int main()
{
    char primeira, ultima;
    char string[25];

    printf("digite nome e sobrenome: ");
    scanf(" %[^\n]", string);
    int tamanho = strlen(string);

    primeira = string[0];
    ultima = string [tamanho-1];

    printf("string final: %s\ntamanho: %i\nprimeira: %c ultima: %c", string, tamanho, primeira, ultima);

    return 0;
}
