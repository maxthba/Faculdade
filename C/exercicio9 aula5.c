/*Faça um programa que declara um vetor de inteiros com 10 posições e um contador que indicará o tamanho
utilizado (iniciando em 0). Peça ao usuário digitar números inteiros positivos para serem armazenados nesse
vetor. Quando o usuário quiser parar de preencher o vetor, deverá digitar um número negativo. Ao final
imprima o vetor com os valores preenchidos.*/

#include <stdio.h>

int main()
{
    int x[10], cont=0, check_num, i;

    while (cont<10){
        printf("Digite o valor de x[%i]", cont);
        scanf("%i", &check_num);

        if (check_num>0){
            x[cont]=check_num;
            cont++;
        }
        else{
            break;
        }
    }

    for (i=0;i<cont;i++){
        printf("\nx[%i]: %i", i, x[i]);
    }
    return 0;
}
