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
    return (a - inteiro);
}

//exercicio 3
int fat(int a){
    int mult=1;
    for (int i = 1; i<=a; i++){
        mult = mult*i ;
    }
    return mult;
}

//exercicio 4
int num_pares (int a, int b){
    int contador = 0;
    for (int i=a; i<=b; i++){
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
bool palindromo(char string[]) {
    int tamanho = tam_str(string);
    for (int i = 0; i < tamanho / 2; i++) {
        if (string[i] != string[tamanho - 1 - i]) {
            return false;
        }
    }
    return true;
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
        for(int i = 0; i < sz-1; i++){
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
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }
            
            case 2: {
                double numero = num_real();
                double parte_fracionada = fracio(numero);
                printf("\nParte fracionada: %lf\n", parte_fracionada);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 3: {
                int numero;
                printf("\nDigite um numero inteiro: ");
                scanf("%i", &numero);
                int fatorial = fat(numero);
                printf("\nO fatorial de %i eh: %i\n", numero, fatorial);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 4: {
                int num1, num2;
                printf("\nDigite o numero de inicio: ");
                scanf("%i", &num1);
                printf("\nDigite o numero de final: ");
                scanf("%i", &num2);

                int pares = num_pares(num1, num2);
                printf("\n A quantidade de pares entre %i e %i eh: %i\n", num1, num2, pares);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 5: {
                char string[100];
                printf("\nDigite algo para a string de no maximo 100 caracteres: ");
                scanf("%[^\n]", string);
                getchar();
                int tamanho = tam_str(string);
                printf("\nO tamanho da string eh: %i\n", tamanho);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 6: {
                char string[100];
                printf("\nDigite uma string: ");
                scanf("%[^\n]", string);
                getchar();

                char n;
                printf("\nDigite um caractere para ver quantas vezes ele aparece na string: ");
                scanf("%c", &n);
                getchar();

                int quantas_vezes = qnt_char(string, n);

                printf("\nA quantidade de vezes que o caractere apareceu na string eh: %i\n", quantas_vezes);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 7: {
                char string1[100];
                printf("\nDigite uma string: ");
                scanf("%[^\n]", string1);
                getchar();

                char string2[tam_str(string1)];
                cop_str(string1, string2);
                printf("String copiada com sucesso!!\n"
                        "String original: %s\n"
                        "String copia: %s\n", string1, string2);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 8: {
                char string[100];
                printf("\nDigite uma string de ate 100 caracteres: ");
                scanf("%[^\n]", string);
                getchar();
                bool check = palindromo(string);
                if (check){
                    printf("\nEh um palindormo!!!\n");
                }
                else{
                    printf("\nNao eh um palindromo!!!\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 9: {
                char string[100];
                printf("\nDigite uma string de ate 100 caracteres: ");
                scanf("%[^\n]", string);
                getchar();
                
                upper(string);
                printf("\nString maiuscula: %s\n", string);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 10: {
                int N;
                printf("\nDigite o tamanho do vetor: ");
                scanf("%i", &N);
                int vetor[N];
                for (int i=0; i<N; i++){
                    printf("\nDigite o valor [%i]: ", i);
                    scanf("%i", &vetor[i]);
                }
                printf("\n");
                printvector(N, vetor);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 11: {
                int a, b;
                printf("\nDigite o numero a: ");
                scanf("%i", &a);
                printf("\nDigite o numero b: ");
                scanf("%i", &b);
                int *A = &a;
                int *B = &b;
                swap(A, B);
                printf("Apos o swap:\n"
                    "a: %i\n"
                    "b: %i\n", *A, *B);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 12: {
                int N;
                printf("\nDigite o tamanho desejado para o vetor: ");
                scanf("%i", &N);
                int vetor[N];

                for(int i=0; i<N; i++){
                    printf("\nDigite o valor de vetor[%i]: ", i);
                    scanf("%i", &vetor[i]);
                }
                ordenarcrescente(N, vetor);
                printf("\nVetor orneado: ");
                printf("\n");
                printvector(N, vetor);
                printf("\n");
                printf("\nPressione Enter para continuar...");
                getchar();
            }

            case 13: {
                int N;
                printf("\nDigite o tamanho desejado para o vetor: ");
                scanf("%i", &N);
                int vetor[N];

                for(int i=0; i<N; i++){
                    printf("\nDigite o valor de vetor[%i]: ", i);
                    scanf("%i", &vetor[i]);
                }
                
                int szPar, szImpar;
                int vetpar[N], vetimpar[N]; // tamanho máximo N
                
                separaparimpar(N, vetor, vetpar, vetimpar, &szPar, &szImpar);
                
                printf("\nNumeros Pares:\n");
                printvector(szPar, vetpar);
                
                printf("\nNumeros Impares:\n");
                printvector(szImpar, vetimpar);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 14: {
                int l, c;
                printf("\nDefina a ordem de linhas da matriz: ");
                scanf("%i", &l);

                printf("\nDefina a ordem de colunas da matriz: ");
                scanf("%i", &c);

                int matriz[l][c];
                for(int i=0; i<l; i++){
                    for (int j=0; j<c; j++){
                        printf("Digite o valor [%i][%i]: ", i, j);
                        scanf("%i", &matriz[i][j]);
                    }
                }
                printf("\n");
                printf("Matriz: \n");
                PrintMatrix(l, c, matriz);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 15: {
              int l1, c1, l2, c2;
                printf("\nDefina a ordem de linhas da matriz1: ");
                scanf("%i", &l1);

                printf("\nDefina a ordem de colunas da matriz1: ");
                scanf("%i", &c1);

                int matriz1[l1][c1];
                for(int i=0; i<l1; i++){
                    for (int j=0; j<c1; j++){
                        printf("Digite o valor [%i][%i]: ", i, j);
                        scanf("%i", &matriz1[i][j]);
                    }
                }  

                printf("\nDefina a ordem de linhas da matriz2: ");
                scanf("%i", &l2);

                printf("\nDefina a ordem de colunas da matriz2: ");
                scanf("%i", &c2);

                int matriz2[l1][c1];
                for(int i=0; i<l2; i++){
                    for (int j=0; j<c2; j++){
                        printf("Digite o valor [%i][%i]: ", i, j);
                        scanf("%i", &matriz2[i][j]);
                    }
                }
                
                int matriz_mult[l1][c2];
                bool mult = MultMatrix(l1, c1, matriz1, l2, c2, matriz2, matriz_mult);
                if(mult){
                    printf("\nMatriz resultado:\n");
                    PrintMatrix(l1, c2, matriz_mult);
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 0: {
                break;
            }
        }
    } while(opcao != 0);
}

int main(){
    EscolherExercicio();
}
