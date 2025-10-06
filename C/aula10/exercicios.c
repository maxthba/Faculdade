#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//1
struct pessoa{
    char nome[50];
    int idade;
};

//1 e 2
void printpessoa(struct pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("Idade: %i\n", p->idade);
}

//3
char* nome_mais_velha(struct pessoa * p1, struct pessoa * p2){
    if(p1->idade > p2->idade){
        return p1->nome;
    }
    else{
        return p2->nome;
    }
}

//4
struct pessoa cria(char*nome, int idade){
    struct pessoa pessoa_criada;
    int i;
    for (i = 0; nome[i] != '\0' && i<49 ; i++){
        pessoa_criada.nome[i] = nome[i];
    }
    pessoa_criada.nome[i] = '\0';

    pessoa_criada.idade = idade;
    return pessoa_criada;
}

//5
bool demaior(struct pessoa p1){
    if (p1.idade>=18){
        return true;
    }
    else{
        return false;
    }
}

//6
void mostra (int tamanho_vet, struct pessoa p[tamanho_vet]){
    for(int i = 0; i<tamanho_vet; i++){
        printf("%d %s\n", i, p[i].nome);
    }
}

//7 
int indice(int tamanho, struct pessoa p[tamanho], char* nome){ 
    for (int i = 0; i < tamanho; i++){
        if(strcmp(p[i].nome, nome) == 0){  
            return i;
        }
    }
    return -1;  
}

//8
struct pessoa maisvelha(int tamanho, struct pessoa p[tamanho]){
    int idademaior, indice;
    for(int i = 0; i<tamanho; i++){
        if(i==0){
            idademaior = p[i].idade;
            indice = i;
        }
        else if(idademaior<p[i].idade){
            idademaior = p[i].idade;
            indice = i;
        }
    }
    return p[indice];
}

//9
void reordenar(int tamanho, struct pessoa p[tamanho]){
    bool troca = true;
    while (troca){
        troca = false;
        for(int i = 0; i<tamanho-1; i++){
            if(strcmp(p[i].nome, p[i+1].nome) > 0){
                struct pessoa temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;

                troca = true;
            }
        }
    }
}

//10
struct aluno {
    char nome[50];
    float nota1, nota2, nota3;
};

void leraluno(struct aluno a1){
    printf("Nome: %s\n", a1.nome);
    printf("Nota1: %.2f\n", a1.nota1);
    printf("Nota2: %.2f\n", a1.nota2);
    printf("Nota3: %.2f\n", a1.nota3);
}

double mediaaluno(struct aluno a1){
    return (a1.nota1 + a1.nota2 + a1.nota3)/3.0;
}

bool aprovado(struct aluno a1){
    double media = mediaaluno(a1);
    if(media>=6){
        return true;
    }
    else{
        return false;
    }
}

//11
struct turma{
    struct aluno alunos[30];
    int quantidade;  
};

int melhores(struct turma a1, struct aluno resultado[]){
    double mediamaior = mediaaluno(a1.alunos[0]); 
    
    for(int i = 1; i < a1.quantidade; i++){  
        double media_atual = mediaaluno(a1.alunos[i]);
        
        if(media_atual > mediamaior){
            mediamaior = media_atual;
        }
    }
    
    int contador = 0;
    for(int i = 0; i < a1.quantidade; i++){
        double media_atual = mediaaluno(a1.alunos[i]);
        if(media_atual == mediamaior){
            resultado[contador] = a1.alunos[i];
            contador++;
        }
    }
    
    return contador;
}

//12
struct produto{
    int codigo, quantidade;
    char nome[50];
    double preco;
};

struct loja{
    struct produto produtos[100];
    int total;
};

void cadastrar(struct loja *loja){
    int quantidade;
    printf("Quantos produtos deseja cadastrar?: ");
    scanf("%i", &quantidade);
    loja->total = quantidade;
    for(int i = 0; i<quantidade; i++){
        printf("Digite o codigo do produto: ");
        scanf("%i", &loja->produtos[i].codigo);

        getchar();
        printf("Digite o nome do produto: ");
        scanf("%[^\n]", loja->produtos[i].nome);

        printf("Digite o preco do produto: ");
        scanf("%lf", &loja->produtos[i].preco);

        printf("Digite a quantidade do produto: ");
        scanf("%i", &loja->produtos[i].quantidade);
    }
}

struct produto* prod_busca(struct loja*loja, int codigo_busca){  
    for(int i = 0; i < loja->total; i++){
        if(loja->produtos[i].codigo == codigo_busca){
            return &loja->produtos[i];
        }
    }
    
    return NULL; 
}

void alteracao(struct loja*loja){
    int codigo_busca;
    printf("Digite o codigo do produto para alterar a quantidade: ");
    scanf("%i", &codigo_busca);

    struct produto* produto_encontrado = prod_busca(loja, codigo_busca);

    if(produto_encontrado != NULL){
        printf("\nProduto encontrado:\n");
        printf("Codigo: %d\n", produto_encontrado->codigo);
        printf("Nome: %s\n", produto_encontrado->nome);
        printf("Quantidade atual: %d\n", produto_encontrado->quantidade);
        
        int nova_quantidade;
        printf("Digite a nova quantidade: ");
        scanf("%d", &nova_quantidade);
        produto_encontrado->quantidade = nova_quantidade;
    } 

    else {
        printf("Produto com codigo %d nao encontrado!\n", codigo_busca);
    }
}

int main(){
    
    return 0;
}