#include <stdio.h>

int main(){
    int senha = 123;
    int tentativa =0;
    int t_senha;

    while (tentativa<3){
        printf("Digite a senha: ");
        scanf("%i", &t_senha);

        if (t_senha == senha)
        {
            printf("Acesso liberado!!\n");
            break;
        }

        else{
            printf("Acesso negado!!\n");
            tentativa ++;
        }
    }

    if(tentativa==3){
        printf("\nLimite maximo de tentativas excedido. Usuario bloqueado!\n");
    }
    return 0;
}