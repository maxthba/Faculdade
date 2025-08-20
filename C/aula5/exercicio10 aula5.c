/*imagine um vetor de inteiros de tamanho 10 e que tenha somente 6 posições inicializadas. Pergunta-se:
    1) Como você faria para inserir um novo elemento na posição 3?
    Obs.: Inserir um novo elemento nessa posição não significa vec[3] = (novo elemento) pois assim você estaria
sobrescrevendo o
    2) Como você faria para remover o elemento da posição 2?*/

#include <stdio.h>

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6};
    int tamanho = 6, novo_num, i, posicao = 3, remover_posicao = 2;

    novo_num = 100;

    for (i = tamanho; i > posicao; i--){ //novo elemento 3
        x[i] = x[i-1];
    }

    x[posicao] = novo_num;
    tamanho++;

    printf("vetor apos insercao: ");
    for(i = 0;i < tamanho; i++){
        printf(" %i ", x[i]);
    }

    for (i = remover_posicao; i < tamanho-1; i++){ //remove elemento
        x[i] = x[i+1];
    }

    tamanho --;

    printf("\nvetor apos remocao: ");
    for(i = 0;i < tamanho; i++){
        printf(" %i ", x[i]);
    }

    return 0;
}

