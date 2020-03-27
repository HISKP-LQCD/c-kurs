#include <stdio.h>
int main(void){
  double *z1, *z2, x;
  x = 0.2;

  z1 = &x;

  z1[0] = 4.2;

  printf("%lf\n", x);
  printf("%lf, %lf\n", *z1, *z2);
}
