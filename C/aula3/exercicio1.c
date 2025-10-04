// Sabendo que A=20, B=0, C=1 e D=10, informe se as expressões são Verdadeiras ou Falsas.
// a) (A – B + D) >= (C)
// b) (A > (A + D)) || (C > B)
// c) ((A * D) > (C + A)) && (A > B)
// d) (((A + B) / C) >= 0,9) && ((B * D) < 0)
// e) ((A + C)/D) > 0,3) && (((B –C)<0) ) || ((C+A) > D))
// f) (((A + C)/D) > 0,3) && ((B –C)<0) )) || ((C+A) > D)

#include <stdio.h>

int main(){
    int A=20, B=0, C=1, D=10;

    //A
    if ((A - B + D) >= (C)){
        printf("A eh verdadeiro\n");  
    }
    else{
        printf("A eh falso\n");
    }

    //B
    if ((A > (A + D)) || (C > B)){
        printf("B eh verdadeiro\n");  
    }
    else{
        printf("B eh falso\n");
    }

    //C
    if (((A * D) > (C + A)) && (A > B)){
        printf("C eh verdadeiro\n");
    }
    else{
        printf("C eh falso\n");
    }

    //D
    if (((double)(A + B) / C >= 0.9) && ((B * D) < 0)){
        printf("D eh verdadeiro\n");
    }
    else{
        printf("D eh falso\n");
    }

    //E
    if ((((double)(A + C)/D > 0.3) && ((B-C)<0)) || ((C+A) > D)){
        printf("E eh verdadeiro\n");
    }
    else{
        printf("E eh falso\n");
    }

    //F
    if ((((double)(A + C)/D > 0.3) && ((B-C)<0)) || ((C+A) > D)){
        printf("F eh verdadeiro\n");
    }
    else{
        printf("F eh falso\n");
    }

    return 0;
}