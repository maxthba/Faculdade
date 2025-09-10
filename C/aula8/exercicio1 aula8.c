#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val1=10, val2=20;
    int*ponteiro1= &val1;
    int*ponteiro2= &val2; 

    int temp=val1;  
    *ponteiro1 = val2;
    *ponteiro2 = temp;

    printf("%i  %i", val1, val2);

    return 0;
}
