#include <stdio.h>

int main()
{
    /*a) falso
    int a = 3; 
    int*p = a;*/

    /*b) verdadeiro
    int a = 3;
    int*p = &a;*/

    /*c) falso
    int a = 3;
    int*p = *a;*/

    /*d) falso
    int a = 3;
    int*p = &a;
    p = 4;
    printf("%i", *p);*/

    /*e) falso
    int a = 3;
    int*p = &a;
    &p = 4;
    printf("%i", *p);*/

    /*f)
    int a = 3;
    int*p = &a;
    *p = 4;
    printf("%i", *p);*/
    
    return 0;
}
