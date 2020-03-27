#include <stdio.h>
int main(void){
  int x = 42;
  double pi = 3.14;
  char c = 55;
  /* %c druckt das 55. Zeichen in der ASCII-Zeichentabelle
   * wir möchten jedoch char als ganz kleines int missbrauchen 
   *     -> Typecasting (char) -> (int)
   * Achtung: dahinter verbergen sich viele Gefahren! */
  printf("x = %d, pi = %lf,\n c = %d\n", x, pi, (int)c);
  return 0;
}
