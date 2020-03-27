#include <stdio.h>
#include <math.h>

double root_to(double *p) { return *p=sqrt(*p); }
double square_to(double *p) { return *p*=*p; }

int main() {
    double a = 9;
    double b = 7;
    printf("%f\n",square_to(&a));
    printf("%f\n",root_to(&a));
    printf("%f\n",b);
    return 0;
}