#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura de clientes
typedef struct Cliente {
    char nome[20];
    long long cpf;
    long long contato_de_celular;

    struct Cliente* next;
} Cliente;

static Cliente* head = NULL;

//funcao para criar novo cliente
Cliente* criar_novo_cliente(char nome[20], long long cpf, long long Contato_de_celular) {
    Cliente* novo_cliente = (Cliente*)malloc(sizeof(Cliente));
    strncpy(novo_cliente ->nome, nome, sizeof(novo_cliente -> nome));
    novo_cliente -> cpf = cpf;
    novo_cliente -> contato_de_celular = Contato_de_celular;
    novo_cliente -> next = NULL;
    return novo_cliente;
}

//inserir cliente na frente da lista
Cliente* inserir_front(Cliente* head, char nome[20], long long cpf, long long contato_de_celular ){
    Cliente* novo_cliente = criar_novo_cliente(nome, cpf, contato_de_celular);
    novo_cliente -> next = head;
    return novo_cliente;
}

//funcao que instere cliente no final da lista
Cliente* inserir_back(Cliente* head, char nome[20], long long cpf, long long contato_de_celular){
    Cliente* novo_cliente = criar_novo_cliente(nome, cpf, contato_de_celular);
    if(head == NULL) return novo_cliente;

    Cliente* current = head;
    while (current -> next != NULL) current = current->next;
    current -> next = novo_cliente;
    return head;
}

//insere o cliente na posicao passada
Cliente* inserir_em(Cliente* head, char nome[20], long long cpf, long long contato_de_celular, int pos){
    if(pos<=0 || head == NULL) return inserir_front(head, nome, cpf, contato_de_celular);

    Cliente* current = head;
    int index = 0;

    while(current->next != NULL && index != pos - 1){
        current = current -> next;
        index++;    
    }

    Cliente* novo_cliente = criar_novo_cliente(nome, cpf, contato_de_celular);
    novo_cliente -> next = current -> next;
    current -> next = novo_cliente;
    return head;
}

//remover cliente da frente da lista
Cliente* remover_front(Cliente* head){
    if(head == NULL) return NULL;
    Cliente* temp = head;
    head = head ->next;
    free(temp);
    return head;
}

//remover cliente do final da lista
Cliente* remover_back(Cliente* head){
    if(head == NULL) return NULL;
    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    Cliente* current = head;
    while(current -> next -> next != NULL) current = current -> next;
    free(current -> next);
    current -> next = NULL;
    return head;
}

//remover cliente na posicao definida
Cliente* remover_pos(Cliente* head, int pos){
    if(head == NULL || pos<0) {
        printf("Posicao invalida!\n");
        return head;
    }
    if(pos == 0) return remover_front(head);

    Cliente* current = head;
    int index = 0;
    while(current -> next != NULL && index < pos -1){
        current = current -> next;
        index++;
    }  
    
    if(current -> next == NULL) {
        printf("Posicao nao existe!\n");
        return head;
    }
    
    Cliente* temp = current -> next;
    current -> next = temp -> next;
    free(temp);
    return head;
}

//funcao para exibir clientes
void exibir_clientes(Cliente* head){
    Cliente* current = head;
    printf("\nLista de clientes:\n");
    int index = 0;
    while(current != NULL){
        printf("Posicao: %i\n", index+1);
        printf("Nome: %s\n", current->nome);
        printf("CPF: %lld\n", current->cpf);
        printf("Celular: %lld\n", current->contato_de_celular);
        printf("\n");
        current = current -> next;
        index++;
    }
    printf("...\n");
}

//funcao de buscar cliente por cpf
Cliente* pesquisar_cpf(Cliente* head, long long cpf){
    Cliente* current = head;
    while(current != NULL){
        if(current->cpf == cpf){
            printf("Cliente encontrado:\n");
            printf("Nome: %s\n", current->nome);
            printf("CPF: %lld\n", current->cpf);
            printf("Celular: %lld\n", current->contato_de_celular);
            return current;
        }
        current = current -> next;
    }
    printf("Cliente nao encontrado.\n");
    return NULL;
}

//opcao 1 cadastrar cliente
void cadastrar_cliente(){
    int opcao;
    printf("\nComo desejar cadastrar o cliente\n"
    "1 - Frente da lista\n"
    "2 - Final da lista\n"
    "3 - Posicao Definida\n"
    "Digite uma opcao: ");
    scanf("%i", &opcao);
    
    switch (opcao) {
        case 1: {
            char nome[20];
            long long cpf;
            long long contato_de_celular;

            printf("\nDigite o Nome do cliente: ");
            scanf("%19s", nome);

            printf("Digite o cpf do cliente: ");
            scanf("%lld", &cpf);

            printf("Digite o telefone de contato do cliente: ");
            scanf("%lld", &contato_de_celular);

            head = inserir_front(head, nome, cpf, contato_de_celular);
            printf("Cliente cadastrado com sucesso!\n");
            break;
        }
        case 2: {
            char nome[20];
            long long cpf;
            long long contato_de_celular;

            printf("\nDigite o Nome do cliente: ");
            scanf("%19s", nome);
            
            printf("Digite o cpf do cliente: ");
            scanf("%lld", &cpf);
            
            printf("Digite o telefone de contato do cliente: ");
            scanf("%lld", &contato_de_celular);

            head = inserir_back(head, nome, cpf, contato_de_celular);
            printf("Cliente cadastrado com sucesso!\n");
            break;
        }
        case 3: {
            char nome[20];
            long long cpf;
            long long contato_de_celular;
            int pos;

            printf("\nDigite o Nome do cliente: ");
            scanf("%19s", nome);
            
            printf("Digite o cpf do cliente: ");
            scanf("%lld", &cpf);
            
            printf("Digite o telefone de contato do cliente: ");
            scanf("%lld", &contato_de_celular);
            
            printf("Digite a posição (0 para frente): ");
            scanf("%d", &pos);

            head = inserir_em(head, nome, cpf, contato_de_celular, pos);
            printf("Cliente cadastrado com sucesso!\n");
            break;
        }
        default:
            printf("Opcao invalida!\n");
    }
}

//opcao 2 excluir cliente
void Remover_cliente(){

    int opcao;
    printf("\nComo desejar remover cliente\n"
    "1 - Frente da lista\n"
    "2 - Final da lista\n"
    "3 - Posicao Definida\n"
    "Digite uma opcao: ");
    scanf("%i", &opcao);

    switch(opcao){
        case 1: {
            if(head == NULL){
                printf("Lista vazia!\n");
            } else {
                head = remover_front(head);
                printf("Cliente removido com sucesso!\n");
            }
            break;
        }
        case 2: {
            if(head == NULL){
                printf("Lista vazia!\n");
            } else {
                head = remover_back(head);
                printf("Cliente removido com sucesso!\n");
            }
            break;
        }
        case 3: {
            if(head == NULL){
                printf("Lista vazia!\n");
            } else {
                int pos;
                printf("\nDigite a posicao: ");
                scanf("%i", &pos);
                Cliente* temp = head;
                head = remover_pos(head, pos);
                if(head != temp || pos == 0){
                    printf("Cliente removido com sucesso!\n");
                }
            }
            break;
        }
        default:
            printf("opcao invalida\n");
    }

}

//funcao de menu principal
void Menu(){
    int opcao;
    do {
        printf("\nMenu:\n"
        "1 - Cadastrar cliente\n"
        "2 - Excluir cliente\n"
        "3 - Exibir cliente\n"
        "4 - Consultar cliente por cpf\n"
        "0 - sair\n\n"
        "Digite a opcao que deseja: ");
        scanf("%i", &opcao);
        
        switch(opcao){
            case 1: {
                cadastrar_cliente();
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 2: {
                Remover_cliente();
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 3: {
                exibir_clientes(head);
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 4: {
                long long cpf_p;
                printf("\nDigite o cpf do cliente que deseja consultar: ");
                scanf("%lld", &cpf_p);
                pesquisar_cpf(head, cpf_p);
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera o Enter
                break;
            }
            case 0: {
                break;
            }
        }
    } while(opcao != 0);
}

int main(){
    Menu();
    return 0;
}