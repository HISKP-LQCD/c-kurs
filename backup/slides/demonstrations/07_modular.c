#include<stdio.h>
double square(double);

int main(void){
  const double x = 0.4;
  double xsq = square(0.4);
  printf("%lf\n",xsq);
  return 0;
}
