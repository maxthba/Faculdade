#include <stdio.h>

int main(){
    int valor1, valor2, resultado;
    int opcao;
    printf("Menu"
        "\n1-adicao"
        "\n2-subtracao"
        "\n3-multiplicacao"
        "\n4-divisao"
        "\nDigite a opcao desejada: ");
    scanf("%i", &opcao);

    switch (opcao){
    case 1:

        printf("Digite o primeiro valor: ");
        scanf("%i", &valor1);

        printf("Digite o segundo valor: ");
        scanf("%i", &valor2);

        resultado = valor1+valor2;
        printf("Resultado: %i", resultado);
        break;
        
    case 2:

        printf("Digite o primeiro valor: ");
        scanf("%i", &valor1);

        printf("Digite o segundo valor: ");
        scanf("%i", &valor2);

        resultado = valor1-valor2;
        printf("Resultado: %i", resultado);
        break;   
    
    case 3:

        printf("Digite o primeiro valor: ");
        scanf("%i", &valor1);

        printf("Digite o segundo valor: ");
        scanf("%i", &valor2);

        resultado = valor1*valor2;
        printf("Resultado: %i", resultado);
        break;

    case 4:

        printf("Digite o primeiro valor: ");
        scanf("%i", &valor1);

        printf("Digite o segundo valor: ");
        scanf("%i", &valor2);

        if(valor2 == 0){ 
            printf("Erro: Divisao por zero!");
        } else {
            resultado = valor1/valor2;
            printf("Resultado: %i", resultado);  // Corrigido: %i
        }
        break;
    }
    return 0;
}