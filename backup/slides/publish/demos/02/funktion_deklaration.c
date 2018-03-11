#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Signatur der Funktion wird dem Compiler bekannt gemacht
double sum_xn(const double, const unsigned int, const double);

int main(void){
  /* durch die Deklaration, weiß der Compiler, dass er hier eine Funktion aufzurufen hat, weil
     die Signatur passt */
  double S = sum_xn( 0.8, 1000, 1e-12 );
  printf("sum_xn = %lf\n",S);
  return 0;
}

// Funktion wird defnitiert
double sum_xn(const double x, const unsigned int nmax, const double tolerance){
  if( fabs(x) > 1 ){
    printf("sum_sn - Fehler: ein Aufruf mit |x|>1 ist nicht moeglich!\nDas Programm wird beendet.");
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

