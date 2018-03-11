#include <stdlib.h>
#include <stdio.h>
int main(void){
  double *x;
  for( unsigned int i = 0; i < 100; ++i ){
    x = malloc( sizeof(double) * (i+1) );
    // beim (1+n)'ten Durchlauf der Schleife, wird die Adresse des zuvor
    // allokierten Speichers vergessen -> Speicherleck
    // diesen Speicher können wir nicht mehr freigeben...
    if( x == NULL ){
      printf("Allokation fehlgeschlagen! Programm wird beendet.\n");
      exit(123);
    }
  }
  free(x); // nur der zuletzt allokierte Speicherbereich (i=99) wird hier freigegeben
  return 0;
}
