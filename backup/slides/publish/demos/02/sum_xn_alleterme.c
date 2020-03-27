#include <stdio.h>
int main(void){
  const double x = 0.8;
  const int nmax = 100;
  /* Initialisierung funktioniert nur mit numerischer Konstante für ANZAHL
     hier wird das erste Element explizit, alle anderen implizit auf 0.0
     initialisiert */
  double S[100] = {0.0};
  double xn = 1.0;
  // Arrays sind von 0 bis n-1 indiziert!
  for(unsigned int n = 0; n < (nmax-1); ++n){
    S[n+1] = S[n] + xn;
    xn *= x;
  }
  for(unsigned int n = 0; n < nmax; ++n){
    printf("S[%d] = %lf\n", n, S[n]);
  }
  return 0;
}
