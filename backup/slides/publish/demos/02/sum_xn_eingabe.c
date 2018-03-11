#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* die Argumentenvariablen x, nmax und tolerance im Funktionskopf existieren innerhalb
 * der Funktion */
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
    if( xn < tolerance ){
      break;
    }
  }
  return S;
}

int main(void){
  printf("Geben Sie x, die maximale Anzahl an Iterationen und die Toleranz an!\n");
  /* die gleichnamigen Variablen x, nmax und tolerance, existieren nur in der 
     main-Funktion */

  double x;
  unsigned int nmax;
  double tolerance;
  // scanf wird in die Speicherbereiche von x, nmax und tolerance schreiben
  // und dabei annehmen, dass das x eine double-Variable ist,
  //                              nmax unsigned int ist und
  //                              tolerance auf eine double-Variable zurückführt
  int n_gelesene_objekte = scanf("%lf %u %lf", &x, &nmax, &tolerance);

  // sicher programmieren: Rückgabewert prüfen!
  if( n_gelesene_objekte != 3 ){
    printf("Fehler: es wurden %d Eingaben erwartet, aber nur %d eingelesen!\n",3,n_gelesene_objekte);
    exit(56);
  }

  double S = sum_xn( x, nmax, tolerance );
  printf("sum_xn = %lf\n",S);
  return 0;
}
