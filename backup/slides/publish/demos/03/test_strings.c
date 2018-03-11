#include <stdio.h>
int main(void){
  // weist begruessung den Wert Hallo, Welt!\n\0 zu
  char begruessung[20] = "Hallo, Welt!\n";
  printf("%s", begruessung);
  // in C werden null-terminierte char-Arrays als 'strings' interpretiert
  // wir können, z.B., den string früher beenden
  begruessung[4] = '\0';
  printf("\n %s \n", begruessung);
  double x = 4.2;
  // auf keinen Fall so etwas machen!
  // x wird als string intepretiert (also als null-terminiertes char-Array)
  printf("\n %s \n", (char*)&x );

  // auf keinen Fall machen!
  char *c = (char*)&x;

  c[5] = 'a';

  printf("\n Oh nein! x = %lf \n", x);

  return 0;
}
