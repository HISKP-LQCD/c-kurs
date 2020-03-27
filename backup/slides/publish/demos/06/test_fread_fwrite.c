#include <stdlib.h>
#include <stdio.h>
int main(void){
  double *x = malloc( 40*sizeof(double) );
  for( unsigned int i = 0; i < 40; i++ ){
    x[i] = (double)rand();
  }
  
  FILE* ausgabedatei = fopen("x.dat","r");
  if( ausgabedatei == NULL ){
    exit(22);
  }
  unsigned int rval = fwrite( (void*)x, sizeof(double), 40, ausgabedatei );
  if( rval != 40 ){
    printf("Fehler beim Schreiben\n");
  }
  if( ferror(ausgabedatei) ){
    printf("ferror != 0\n");
  }
  printf("feof = %d\n", feof(ausgabedatei) );
  fclose(ausgabedatei);
  return 0;
}
