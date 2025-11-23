#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Pilha;

void inicia_Pilha(Pilha *p) { 
    p->top = NULL; 
}

int vazia(Pilha *p) { 
    return p->top == NULL; 
}

void push(Pilha *p, const char *texto) {
	Node *n = (Node *) malloc(sizeof(Node));
	if (!n) return;
	size_t len = strlen(texto) + 1;
	n->data = (char *) malloc(len);
	if (!n->data) { free(n); return; }
	memcpy(n->data, texto, len);
	n->next = p->top;
	p->top = n;
}

char *pop(Pilha *p) {
    if (vazia(p)) return NULL;
    Node *tmp = p->top;
    char *ret = tmp->data; 
    p->top = tmp->next;
    free(tmp);
    return ret;
}

void clear(Pilha *p) {
	while (!vazia(p)) {
		char *s = pop(p);
		free(s);
	}
}


void imprimirRec(Node *no) {
	if (no == NULL) return;
	imprimirRec(no->next);
	printf("%s\n", no->data);
}

void ImprimirTexto(Pilha *p) {
	if (vazia(p)) {
		printf("(frase vazia)\n");
		return;
	}
	imprimirRec(p->top);
}

static Pilha undo;
static Pilha redoo; 

int main(void) {
	inicia_Pilha(&undo);
	inicia_Pilha(&redoo);

	int opcao;
	char entrada[256];
	for (;;) {
		printf("=============================\n");
		printf("Digite a opcao desejada:\n");
		printf("0 - Digitar nova palavra da frase\n");
		printf("1 - Desfazer (Undo)\n");
		printf("2 - Refazer (Redo)\n");
		printf("3 - Imprimir a frase\n");
		printf("4 - Sair\n");
		printf("Qual opcao? ");
		if (scanf("%d", &opcao) != 1) {
			printf("Entrada invalida. Encerrando.\n");
			break;
		}
		getchar();

		switch (opcao) {
		case 0: {
			printf("Digite a nova palavra: ");
			if (!fgets(entrada, sizeof(entrada), stdin)) break; 
			entrada[strcspn(entrada, "\n")] = '\0';
			if (entrada[0] == '\0') {
				printf("Palavra vazia ignorada.\n");
			} else {
				push(&undo, entrada);
				clear(&redoo); 
				printf("Adicionada: %s\n", entrada);
			}
			break; }
		case 1: { 
			char *palavra = pop(&undo);
			if (!palavra) {
				printf("Nada para desfazer.\n");
			} else {
				push(&redoo, palavra);
				free(palavra); 
				printf("Desfeito.\n");
			}
			break; }
		case 2: { 
			char *palavra = pop(&redoo);
			if (!palavra) {
				printf("Nada para refazer.\n");
			} else {
				push(&undo, palavra);
				free(palavra);
				printf("Refeito.\n");
			}
			break; }
		case 3:
			printf("Frase atual (cada palavra em uma linha):\n");
			ImprimirTexto(&undo);
			break;
		case 4:
			printf("Saindo...\n");
			clear(&undo);
			clear(&redoo);
			return 0;
		default:
			printf("Opcao invalida.\n");
		}
	}

    clear(&undo); 
    clear(&redoo);
    return 0;
}


