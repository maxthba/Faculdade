#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

//exercicio3
int fat(int a){
    int soma=0;
    for (int i = 0; i<=a; i++){
        soma += i;
    }
    return soma;
}

//exercicio4
int num_pares (int a, int b){
    int contador = 0;
    for (int i=a; i<b; i++){
        if(i%2 == 0){
            contador += 1;
        }
    }
    return contador;
}

//exercicio5
int tam_str (char string[]){
    return strlen(string);
}

//exercicio6
int qnt_char (char string[], char a){
    int qnt = 0;
    for (int i =0; string[i] != '\0'; i++){
        if(string[i] == a) {
            qnt ++;
        }
    }
    return qnt;
}

//exercicio7
void cop_str(char origem[], char destino[]){
    int tamanho = strlen(destino);
    strncpy(destino, origem, sizeof(tamanho));
    destino[tamanho-1] = '\0';
}
int main(){
    char string_org[] ="oi tudo bem";
    char string_destino[strlen(string_org)+1];
    cop_str(string_org, string_destino);

    printf("String de origem: %s\n", string_org);
    printf("String de destino: %s\n", string_destino);
    return 0;
}
