#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double sum_xn(const double x, const unsigned int nmax, const double tolerance){
  if( fabs(x) > 1 ){
    printf("sum_xn - Fehler: kann nicht mit |x| > 1 aufgerufen werden!\n");
    exit(55);
  }
  double S = 0.0;
  double xn = 1.0;
  for(unsigned int n = 0; n < nmax; ++n){
    S += xn;
    xn *= x;
    if( xn < tolerance){
      break;
    }
  }
  return S;
}

int main(void){
  double S = sum_xn( 0.8, 1000, 1e-12 );
  printf("sum_xn = %lf\n",S);
  return 0;
}
