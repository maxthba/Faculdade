#include <stdio.h>

int main()
{
    double x [20], y[20], z[20];
    int i;

    for(i=0;i<20;i++){
        printf("digite o valor de x[%i]: ", i);
        scanf("%lf", &x[i]);

        printf("digite o valor de y[%i]: ", i);
        scanf("%lf", &y[i]);

        z[i] = x[i]*y[i];
    }
    printf("x y z");
    for(i=0;i<20;i++){
        printf("%.2lf %.2lf %.2lf\n", x[i], y[i], z[i]);
    }
    return 0;
}
