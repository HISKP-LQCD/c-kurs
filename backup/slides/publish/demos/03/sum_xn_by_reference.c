#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// die Funktion sum_xn wird mit einem Argument erweitert, welches ein Zeiger auf ein double
// ist
double sum_xn(double *z_S, const double x, const unsigned int nmax, const double tolerance){
  if( fabs(x) > 1 ){
    printf("sum_xn - Fehler: kann nicht mit |x| > 1 aufgerufen werden!\n");
    exit(55);
  }
  double xn = 1.0;
  for(unsigned int n = 0; n < nmax; ++n){
    // um die Summe zu inkrementieren, muss der Zeiger z_S derefernziert werden
    *z_S += xn;
    xn *= x;
    if( xn < tolerance){
      break;
    }
  }
  return *z_S;
}

int main(void){
  double S = 0.0;
  // wir übergeben die Speicheradresse von S, also einen Zeiger auf S
  sum_xn( &S, 0.8, 1000, 1e-12 );
  printf("sum_xn = %lf\n",S);
  return 0;
}
