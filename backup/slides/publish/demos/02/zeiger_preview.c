#include <stdio.h>
int main(void){
  int x = 4;
  printf("x = %d\n",x);
 
  int *zeiger_auf_x = &x; /* Adressoperator gibt einen Zeiger auf x des Typs (int*)
                             zurück */

  // Dereferenzierung gibt Zugriff auf den Wert der Variable, auf die der Zeiger zeigt
  printf("x = %d\n", *zeiger_auf_x);

  (*zeiger_auf_x) = 6;
  printf("x = %d, aber auch x = %d\n", *zeiger_auf_x, x);
  return 0;
}

