#include <stdio.h>
#include <string.h>

int main()
{
    char string1[10], string2[10];
    int tamanho;

    printf("digite algo: ");
    scanf(" %[^\n]", string1);
    getchar();
    tamanho = strlen(string1);

    
    for (int i = 0; i < tamanho; i++){
        string2[tamanho-1-i] = string1[i];
    }
    string2[tamanho] = '\0';
    
    printf("%i\n", tamanho);
    printf("string original: %s\nstring invertida: %s", string1, string2);
    return 0;
}
