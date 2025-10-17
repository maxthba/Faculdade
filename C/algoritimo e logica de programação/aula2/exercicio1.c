#include <stdio.h>

int main(){
    int A = 5;
    int B = 13;

    int temp = 0;

    temp = A;
    A = B;
    B = temp;

    printf("A = %i \nB = %i", A, B );

    return 0;
}
 