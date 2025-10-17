#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool EhPar(int a){
    if(a%2==0){
        return true;
    }
    else{
        return false;
    }
}

int Fatorial(int a){
    if(a<0){
        return -1;
    }
    
    if(a==0){
        return 1;
    }

    int fatorial = 1;
    for(int i = 1; i<=a; i++){
        fatorial = fatorial*i;
    }

    return fatorial;
}

void Troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int TamanhoString(char string[]){
    int tamanho = 0;
    for(int i = 0; string[i]!='\0'; i++){
        tamanho++;
    }
    return tamanho;
}

int ContarCaractere(char string[], char c){
    int contador = 0;
    for(int i = 0; string[i]!='\0'; i++){
        if(tolower(string[i])==tolower(c)){
            contador++;
        }
    }
    return contador;
}

int EhPalindromo(char string[]){
    int tamanho = TamanhoString(string);
    for (int i = 0; i<tamanho/2; i++){
        if(tolower(string[i])!=tolower(string[tamanho-1-i])){
            return 0;
        }
    }
    return 1;
}

void ConverterParaMaiusculas(char string[]){
    for(int i = 0; string[i]!='\0'; i++){
        string[i]=toupper(string[i]);
    }
}

void PrintVector(int sz, int vet[sz]){
    for(int i = 0; i<sz; i++){
        printf("%i\n", vet[i]);
    }
}

void OrdenarCrescente(int sz, int vet[]){
    bool swap = true;
    while (swap){
        swap = false;
        for (int i = 0; i<sz-1; i++){
            if(vet[i]>vet[i+1]){
                Troca(&vet[i], &vet[i+1]);
                swap = true;
            }
        }
    }
    
}

void PrintMatriz(int nl, int nc, int matriz[nl][nc]){
    for (int i = 0; i<nl; i++){
        for(int j = 0; j<nc; j++){
            printf(" %i ", matriz[i][j]);
        }
    printf("\n");
    }
}

struct pessoa {
    char nome[50];
    int idade;
};

char* NomeMaisVelho(struct pessoa* p1, struct pessoa* p2){
    if (p1->idade>p2->idade){
        return p1->nome;
    }
    else{
        return p2->nome;
    }
}
int main(){
    struct pessoa p1;
    strcpy(p1.nome, "Max Thomazini");
    p1.idade = 20;

    struct pessoa p2;
    strcpy(p2.nome, "Gabriela tulio");
    p2.idade = 19;

    char* nomemaisvelho = NomeMaisVelho(&p1, &p2);

    printf("Nome da pessoa mais velha: %s", nomemaisvelho);


    return 0;
}