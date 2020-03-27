#include <stdio.h>
int main(void){
  int ganzzahl;
  double dezimalzahl;
  int n_zeichen = scanf("%d %lf", &ganzzahl, &dezimalzahl);
  printf("Es wurden %d Zeichen gelesen. Die Eingabe lautete %d %f\n",n_zeichen, ganzzahl, dezimalzahl);
}
