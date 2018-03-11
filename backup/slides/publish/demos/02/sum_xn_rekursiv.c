#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double sum_xn(const double x, const double S, const double xn, const double tolerance){
  if( fabs(x) > 1 ){
    printf("sum_xn - Fehler: kann nicht mit |x| > 1 aufgerufen werden!\n");
    exit(55);
  }
  // wenn x^n schon kleiner ist als unsere Toleranz, beenden wir die Rekursion
  // der Rückgabewert 'S' wird dann durch den Funktionsbaum zurückgeschleift
  if( xn < tolerance ){
    return S;
  } else {
    /* Haben wir unser Ziel noch nicht erreicht, rechnen wir die nächste Potenz von x aus,
     * inkrementieren die Summe und übergeben beide dann an sum_xn für die nächste Rekursion */
    return sum_xn( x, S+xn, xn*x, tolerance );
  }
}

int main(void){
  // dieser Aufruf wird sehr oft rekursieren und fehlschagen -> stack overflow!!
  double S = sum_xn( 0.99999, 0.0, 1.0, 1e-24 );
  printf("sum_xn = %lf\n", S);
  return 0;
}
