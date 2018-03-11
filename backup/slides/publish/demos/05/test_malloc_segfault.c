#include <stdlib.h>
#include <stdio.h>
int main(void){
  int l = 2;
  int k = 40;
  int n = l+k;
  double *x = malloc( sizeof(double) * n );
  if( x == NULL ){
    printf("Speicherallokation fehlgeschlagen! Programm wird beendet.\n");
    exit(123);
  }
  x[32] = 3.2;
  printf("x[32] = %lf\n", x[32]);
  free(x);
  
  // dynamischer Speicher für zwei double
  double *x_dyn = malloc( 2*sizeof(double) );
  if( x_dyn == NULL ){
    printf("Speicherallokation fehlgeschlagen! Programm wird beendet.\n");
    exit(123);
  }
  x_dyn[0] = 34.2;
  /* Zugriff auf Elemente ausserhalb des reservierten
   * Speicherbereichs resultiert in Segmentation Fault
   * kann mit valgrind überprüft werden */
  printf("%lf\n", x_dyn[-1]);
  x_dyn[-1] = 4.2;
  free(x_dyn);
  
  return 0;
}
