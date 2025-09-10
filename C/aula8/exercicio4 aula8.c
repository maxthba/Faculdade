#include <stdio.h>

int main()
{
    int num1 = 1, num2 = 2, num3 = 3;
    int*ponteiro1 = &num1;
    int*ponteiro2 = &num2;
    int*ponteiro3 = &num3;
    
    *ponteiro1 = 10;

    ponteiro1 = ponteiro2;
    *ponteiro1 = 20;

    ponteiro1 = ponteiro3;
    *ponteiro1 = 30;
    printf("num1: %i\nnum2: %i\nnum3: %i", num1, num2, num3);
    return 0;
}
