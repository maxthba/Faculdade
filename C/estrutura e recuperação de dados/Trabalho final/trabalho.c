#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um contato (sem acentos)
typedef struct Contato {
	char nome[50];
	char celular[15];
	struct Contato* esquerda;
	struct Contato* direita;
} Contato;

// Compara os nomes (retorno <0, =0, >0) (sem acentos)
int compararNomes(const char* nome1, const char* nome2) {
	return strcmp(nome1, nome2);
}

// Protótipo de inserir (usado antes da definição)
Contato* inserir(Contato* raiz, Contato* novo);
Contato* buscar(Contato* raiz, const char* nome);
Contato* remover(Contato* raiz, const char* nome);
void listar(Contato* raiz);
void menu();
void ImprimirArvoreDeContatos(Contato* raiz);

int main() {
	Contato* raiz = NULL;
	int opcao;
	do {
		menu();
		scanf("%d", &opcao);
		switch (opcao) {
			case 1: {
				// Adicionar contato
				Contato* novo = (Contato*)malloc(sizeof(struct Contato));
				printf("Nome: ");
				scanf("%s", novo->nome);
				printf("Celular: ");
				scanf("%s", novo->celular);
				novo->esquerda = NULL;
				novo->direita = NULL;
				raiz = inserir(raiz, novo);
				break;
			}
			case 2: {
				// Buscar contato
				char nome[50];
				printf("Nome para buscar: ");
				scanf("%s", nome);
				Contato* encontrado = buscar(raiz, nome);
				if (encontrado) {
					printf("Contato encontrado: %s, Celular: %s\n", encontrado->nome, encontrado->celular);
				} else {
					printf("Contato nao encontrado.\n");
				}
				break;
			}
			case 3: {
				// Remover contato
				char nome[50];
				printf("Nome para remover: ");
				scanf("%s", nome);
				raiz = remover(raiz, nome);
				break;
			}
			case 4: {
				// Imprimir contatos
				printf("Contatos:\n");
				ImprimirArvoreDeContatos(raiz);
				break;
			}
			case 5: {
				printf("Saindo...\n");
				break;
			}
			default: {
				printf("Opcao invalida! Tente novamente.\n");
			}
		}
	} while (opcao != 5);
	return 0;
}

//funcao de inserir contato
Contato* inserir(Contato* raiz, Contato* novo) {
	if (novo == NULL) { //verifica se contato novo esta vazio
		return raiz;
	}
	if (raiz == NULL) { //verifica se raiz esta vazia
		return novo; // novo vira raiz
	}

	int comparacao = compararNomes(novo->nome, raiz->nome); //compara os nomes para ver se e maior ou menor
	if (comparacao < 0) { //caso o nome seja menor ele ira para a esquerda
		raiz->esquerda = inserir(raiz->esquerda, novo);
	} else if (comparacao > 0) { //caso o nome seja maior ele ira para a direita
		raiz->direita = inserir(raiz->direita, novo);
	} else { // nome duplicado
		// Atualiza celular e descarta novo nó extra
		strcpy(raiz->celular, novo->celular);
		free(novo);
	}
	return raiz;
}

Contato* buscar(Contato* raiz, const char* nome) {
	// Busca binaria recursiva na arvore por nome
	if (raiz == NULL) {
		return NULL; // nao encontrado
	}
	int comparacao = compararNomes(nome, raiz->nome);
	if (comparacao == 0) {
		return raiz; // encontrado
	} else if (comparacao < 0) { // se nome for menor
		return buscar(raiz->esquerda, nome); // procura a esquerda
	} else {
		return buscar(raiz->direita, nome); // procura a direita
	}
}

Contato* remover(Contato* raiz, const char* nome) {
	if (raiz == NULL) {
		return NULL; // nada a remover
	}

	int comparacao = compararNomes(nome, raiz->nome);
	if (comparacao < 0) { // caso o nome seja menor
		raiz->esquerda = remover(raiz->esquerda, nome);
	} else if (comparacao > 0) { //caso o nome seja maior
		raiz->direita = remover(raiz->direita, nome);
	} else {
		// Encontrou o nó a remover
		if (raiz->esquerda == NULL && raiz->direita == NULL) {
			// Caso 1: folha
			free(raiz);
			return NULL;
		} else if (raiz->esquerda == NULL) {
			// Caso 2: apenas filho à direita
			Contato* temp = raiz->direita;
			free(raiz);
			return temp;
		} else if (raiz->direita == NULL) {
			// Caso 2: apenas filho à esquerda
			Contato* temp = raiz->esquerda;
			free(raiz);
			return temp;
		} else {
			// Caso 3: dois filhos -> usar sucessor (minimo da subarvore direita)
			Contato* sucessor = raiz->direita;
			while (sucessor->esquerda != NULL) {
				sucessor = sucessor->esquerda;
			}
			// Copia dados do sucessor para a raiz
			strcpy(raiz->nome, sucessor->nome);
			strcpy(raiz->celular, sucessor->celular);
			// Remove sucessor (que agora está duplicado)
			raiz->direita = remover(raiz->direita, sucessor->nome);
		}
	}
	return raiz;
}

void ImprimirArvoreDeContatos(Contato* raiz) {
	// Percorre em ordem alfabetica (in-order): esquerda, raiz, direita
	if (raiz == NULL) {
		return;
	}
	ImprimirArvoreDeContatos(raiz->esquerda);
	printf("Nome: %s | Celular: %s\n", raiz->nome, raiz->celular);
	ImprimirArvoreDeContatos(raiz->direita);
}

void menu() {
	printf("\nMenu:\n");
	printf("1. Adicionar contato\n");
	printf("2. Buscar contato\n");
	printf("3. Remover contato\n");
	printf("4. Listar contatos\n");
	printf("5. Sair\n");
	printf("Escolha uma opcao: ");
}