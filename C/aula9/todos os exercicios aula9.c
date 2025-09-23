#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// exercicio 1
bool par(int a){
    if(a%2==0){
        return true;
    }
    else{
        return false;
    }
}

//exercicio 2
double num_real(){
    double real;
    printf("\nDigite um numero real: ");
    scanf("%lf", &real);

    return real;
}

double fracio(double a){
    int inteiro = (int) a;
    return ((double)a - (int)inteiro);
}

//exercicio 3
int fat(int a){
    int soma=0;
    for (int i = 0; i<=a; i++){
        soma += i;
    }
    return soma;
}

//exercicio 4
int num_pares (int a, int b){
    int contador = 0;
    for (int i=a; i<b; i++){
        if(i%2 == 0){
            contador += 1;
        }
    }
    return contador;
}

//exercicio 5
int tam_str (char string[]){
    int tamanho = 0;
    while (string[tamanho] != '\0') {
    tamanho++;
    }
    return tamanho;
    
}

//exercicio 6
int qnt_char (char string[], char a){
    int qnt = 0;
    for (int i =0; string[i] != '\0'; i++){
        if(string[i] == a) {
            qnt ++;
        }
    }
    return qnt;
}

//exercicio 7
void cop_str(char origem[], char destino[]){
    int i = 0;
    while (origem[i] != '\0'){
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

//exercicio 8
int palindromo(char string[]) {
    int tamanho = tam_str(string);
    char string_inversa[tamanho + 1];
    int i;
    for (i = 0; i < tamanho; i++) {
        string_inversa[i] = string[tamanho - i - 1];
    }
    string_inversa[i] = '\0';

    for (i = 0; i < tamanho; i++) {
        if (string[i] != string_inversa[i]) {
            return 0;
        }
    }
    return 1;
}

//exercicio 9 
void upper(char string[]){
    for (int i = 0; string[i]!=0; i++){
        string[i] = toupper(string[i]);
    }
}

//exercicio 10
void printvector(int sz, int vec[sz]){
    for (int i=0; i<sz; i++){
        printf("%i\n", vec[i]);
    }
}

//exercicio 11
void swap(int*a, int*b){
    int trocar = *a;
    *a = *b;
    *b = trocar;
}

//exercicio 12
void ordenarcrescente(int sz, int vec[sz]){
    int troca;
    bool swap = true;
    while (swap){
        swap = false;
        for(int i = 0; i<=sz-1; i++){
            if(vec[i]>vec[i+1]){
                troca=vec[i];
                vec[i]=vec[i+1];
                vec[i+1]=troca;
                swap = true;
            }
        }
    }
}


//exercicio 13
void separaparimpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar) {
    *szPar = 0;
    *szImpar = 0;
    for (int i = 0; i < sz; i++) {
        if (vec[i] % 2 == 0) {
            vPar[*szPar] = vec[i];
            (*szPar)++;
        } else {
            vImpar[*szImpar] = vec[i];
            (*szImpar)++;
        }
    }
}

// exercicio 14
void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols]){
    for (int i = 0; i<nRows; i++){
        for(int j = 0; j<nCols; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

// exercicio 15
bool MultMatrix(int linhasA, int colunasA, int A[linhasA][colunasA], int linhasB, int colunasB, int B[linhasB][colunasB], int Mult[linhasA][colunasB]){
    if(colunasA != linhasB){
        return false;
    }
    else{
        for (int i = 0; i<linhasA; i++){
            for (int j = 0; j<colunasB; j++){
                Mult[i][j] = 0;
                for (int k = 0; k<colunasA; k++){
                    Mult[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return true;
    }
}

// exercicio 16
void EscolherExercicio(){
    int opcao;
    do {
        printf("\nMenu:\n"
        "1 - Retorna se o numero inteiro eh par.\n"
        "2 - Le um numero real e retorna a parte fracionada.\n"
        "3 - Retorna o fatorial de um inteiro positivo.\n"
        "4 - Escreve pares entre a e b.\n"
        "5 - Retorna o tamanho da string.\n"
        "6 - Retorna a quantidade de vezes que um caractere aparece na string.\n"
        "7 - Copia uma string para outra.\n"
        "8 - Retorne se a string eh um palindromo.\n"
        "9 - Converte todos os caracteres para maiusculo.\n"
        "10 - Imprime um vetor.\n"
        "11 - Faz o swap entre dois inteiros.\n"
        "12 - Ordenar um vetor em ordem crescente.\n"
        "13 - Separa elementos de um vetor em pares e impares.\n"
        "14 - Imprime uma matriz.\n"
        "15 - Multiplicacao de matriz\n"
        "0 - sair\n\n"
        "Digite a opcao que deseja: ");
        scanf("%i", &opcao);
        getchar();
        switch(opcao){
            case 1: {
                int a;
                printf("\ndigite um numero inteiro: ");
                scanf("%i", &a);

                bool ehpar = par(a);
                if (ehpar){
                    printf("\nEh par!!\n");
                }
                else {
                    printf("\nNao eh par!!\n");
                }
                break;
            }
            
            case 2 : {
                double numero = num_real();
                double parte_fracionada = fracio(numero);
                printf("\nParte fracionada: %lf\n", parte_fracionada);
                break;
            }
        }
    } while(opcao != 0);
}

int main(){
    EscolherExercicio();
}
