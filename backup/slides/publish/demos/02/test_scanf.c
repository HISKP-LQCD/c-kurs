#include <stdio.h>
int main(void){
  printf("Geben Sie eine Ganzzahl und eine Dezimalzahl ein!\n");
  int ganzzahl;
  double dezimalzahl;
  scanf("%d %lf", &ganzzahl, &dezimalzahl);
  printf("ganzzahl = %d, dezimalzahl = %lf\n", ganzzahl, dezimalzahl);
  return 0;
}
