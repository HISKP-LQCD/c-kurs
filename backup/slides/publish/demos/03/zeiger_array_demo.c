#include <stdio.h>
#include <stdlib.h>
int main(void){
  // statische Arrays a und c werden definiert
  double a[4] = {1.3,2.4,5.4,6.0};
  double c[4] = {4.4,3.7,2.4,8.0}; 
  // einem Zeiger auf double, b, des Typs (double*) wird die Adresse des ersten Elements
  // von a zugewiesen
  double* b = a;
  // wir hätten auch schreiben können: double* b = &a[0];

  /* Achtung: es wird oft geschrieben: 
   *   double *b = a;
   * Dies bedeutet exakt das gleiche, wie double* b = a, ist aber schwerer zu lesen.
   * Der Grund ist, dass man schreiben kann:
   * double *z1, *z2, fliesskommazahl;
   * z1 und z2 sind Zeiger auf double, fliesskommazahl wird ein double sein...
   */

  // a und b zeigen jetzt auf die gleichen Daten
  printf("a[0] = %lf, b[0] = %lf\n", a[0], b[0]);

  // wir können b aber auch auf c zeigen lassen
  b = c;

  // a und b zeigen jetzt auf verschiedene Daten
  printf("a[0] = %lf, b[0] = %lf\n", a[0], b[0]);

  /* Zeiger und Arrays sind nicht das gleiche
   * Der Compiler weiß, wie viele Elemente im array 'a' sind, und kann uns diese Größe in Bytes mitteilen
   * Der Compiler weiß jedoch nicht, wie viele Elemente sich hinter dem Zeiger 'b' verstecken
   * er gibt uns also die Größe des Datentyps (double*) zurück */
  printf("sizeof(a) = %lu, sizeof(b) = %lu\n", sizeof(a), sizeof(b) );

  return 0;
}
