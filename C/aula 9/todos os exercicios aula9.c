#include <stdio.h>
#include <stdbool.h>

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
int main(){
    int fatorial = fat(10);
    printf("%i", fatorial);
}
