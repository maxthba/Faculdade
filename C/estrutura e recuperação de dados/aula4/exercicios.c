#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//criando a estrutura de no
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//estrutura de Pilha
typedef struct Pilha {
    Node* top;
} Pilha;

//funcao de criar no
Node* criandoNode(int value){
    Node* novo_Node = (Node*) malloc(sizeof(Node));
    novo_Node -> value = value;
    novo_Node -> next = NULL;
    return novo_Node;
}

//funcao de inserir valor no topo da pilha
Pilha* push(Pilha* p, int value){
    Node* novo_node = criandoNode(value);
    novo_node->next = p->top;
    p->top = novo_node;
    return p;
}

//remove elemento e retorna elemento do topo da pilha
Pilha* pop(Pilha* p){
    if(p->top == NULL) return p;
    Node* temp = p->top;
    p->top = p->top->next;
    free(temp);
    return p;
}

//funcao para exibir a pilha
void printPilha(Pilha* p){
    Node* atual = p->top;
    printf("\nPilha (topo->embaixo): ");
    while(atual != NULL){
        printf("\n%i", atual->value);
        atual = atual->next;
    }
}

int main(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->top = NULL;

    p = push(p, 10);
    p = push(p, 20);
    p = push(p, 30);

    printPilha(p);

    p = pop(p);

    printPilha(p);
    return 0; 
}