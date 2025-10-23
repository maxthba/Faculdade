#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//estrutura do no
typedef struct paciente {
    char nome[20];
    int idade;
    int numero_chamada;
    struct paciente* next;
}paciente;

//estrutura de fila
typedef struct fila {
    paciente * primeiro;
    paciente * ultimo;
}fila;

// inicializa a fila (ponteiros nulos)
void init_fila(fila* f){
    f->primeiro = NULL;
    f->ultimo = NULL;
}

//funcao de criar um novo paciente
paciente * Criar_paciente(char nome[20], int idade, int numero_chamada){
    paciente* novo_paciente = (paciente*)malloc(sizeof(paciente));
    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade = idade;
    novo_paciente->numero_chamada = numero_chamada;
    novo_paciente->next = NULL;
    return novo_paciente;
}
//funcao de inserir paciente
fila* inserir_paciente(fila* f, char nome[20], int idade, int numero_chamada){
    paciente* novo_paciente = Criar_paciente(nome, idade, numero_chamada);
    
    if(f->ultimo == NULL){
        //nao tem nenhum paciente
        f->primeiro = novo_paciente;
        f->ultimo = novo_paciente;
    } else{
        f->ultimo->next = novo_paciente;
        f->ultimo = novo_paciente;
    }

    return f;
}

//remover paciente da fila
fila* remover_paciente(fila* f) {
    if(f->primeiro == NULL) return f; // fila nao possui paciente
    paciente* temp = f->primeiro;
    f->primeiro = f->primeiro->next;

    if(f->primeiro == NULL){
        f->ultimo = NULL;//fila ficou vazia apos a remocao
    }
    free(temp);
    return f;
}

//printar a fila
void printFila(fila* f){
    paciente* atual = f->primeiro;
    printf("Fila: ");
    while(atual != NULL){
        printf("\n\nNome: %s", atual->nome);
        printf("\nIdade: %i", atual->idade);
        printf("\nNumero_chamada: %i", atual->numero_chamada);
        atual = atual->next;
    }
}

//funcao para consultar idade mais velha
int maisVelha(fila* f){
    if(f->primeiro == NULL) return -1; // fila vazia
    paciente* atual = f->primeiro;
    int idade_mais_velha = f->primeiro->idade;
    while(atual != NULL){
        if(idade_mais_velha < atual->idade){
            idade_mais_velha = atual->idade;
        }
        atual = atual->next; // ESSENCIAL: avançar para o próximo
    }
    return idade_mais_velha;
}

//funcao para printar mais velhos
void printMaisVelho(fila* f, int idadeVelho){
    paciente* atual = f->primeiro;
    printf("Mais velhos: ");
    while (atual != NULL){
        if(idadeVelho == atual->idade){
            printf("\n\nNome: %s", atual->nome);
            printf("\nIdade: %i", atual->idade);
            printf("\nNumero_chamada: %i", atual->numero_chamada);
        }
        atual = atual->next;
    }
}

void menu(){
    fila f;
    init_fila(&f);

    int opcao;
    do
    {
        printf("\nMenu:\n"
        "1 - Adicionar paciente na fila\n"
        "2 - Atender proximo paciente\n"
        "3 - Exibir fila\n"
        "4 - Exibir pacientes mais velhos\n"
        "0 - sair\n\n"
        "Digite a opcao que deseja: ");
        scanf("%i", &opcao);
        switch (opcao){
            case 1: {
                char nome[20];
                int idade, numero_chamada;
                printf("Qual o nome do paciente: ");
                scanf("%19s", nome);

                printf("Qual a idade do paciente: ");
                scanf("%i", &idade);

                printf("Qual o numero de chamada do paciente: ");
                scanf("%i", &numero_chamada);
                inserir_paciente(&f, nome, idade, numero_chamada);
                printf("Cliente adicionado a fila");
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 2: {
                remover_paciente(&f);
                printf("Proximo Cliente...");
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 3: {
                printFila(&f);
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 4: {
                int idadeV = maisVelha(&f);
                if(idadeV == -1){
                    printf("Fila vazia.\n");
                } else {
                    printMaisVelho(&f, idadeV);
                }
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            default:
                break;
        }
    } while (opcao!=0); 
}

int main(){
    menu();
    return 0;
}