#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// exercicio 1
int par(int a){
    bool par;
    if(a%2==0){
        par = true;
    }
    else{
        par = false;
    }
    return par;
}

//exercicio 2
double num_real(){
    double real;
    printf("Digite um numero real: ");
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

int main(){
}
