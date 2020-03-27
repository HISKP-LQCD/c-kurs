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
  x[32] = 3.2; // x kann jetzt wie ein Array verwendet werden
  printf("x[32] = %lf\n", x[32]);
  free(x);
  return 0;
}
