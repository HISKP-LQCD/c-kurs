#include <string.h>
#include <stdlib.h>
int main(void){
  double *x = malloc(20*sizeof(double));
  double *y = malloc(20*sizeof(double));
  double z[20];
  // 15 Elemente aus x nach y kopieren
  memmove( (void*)y, (void*)x, 15*sizeof(double));

  // 15 Element von x auf 0 setzen
  memset( (void*)x, 0, 15*sizeof(double));

  memset( (void*)z, 0, 20*sizeof(double));
  memset( (void*)y, 0, 100*sizeof(double));

  return 0;
} 
