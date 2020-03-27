#include <string.h>
#include <stdio.h>
int main(void){
  // Wir wollen str kopieren, str hat 18 Zeichen (17+\0)
  //              012345678901234567890
  char str[20] = "Ich werde kopiert.";
  // str2 wird ein null-terminierter String mit 14+1 Zeichen zugewiesen
  // -> str2 hat 14+1 Zeichen
  char str2[15] = "01234567890123";

  // hier sieht noch alles gut aus!
  printf("str = %s, str2 = %s\n", str, str2); 

  // Wir kopieren str nach str2, in str2 steht aber nicht genug Speicher zur Verfügung!
  strcpy( str2, str );
  printf("str = %s, str2 = %s\n", str, str2);
  // auf meinem Rechner erhalte ich die Ausgabe:
  //   str = t., str2 = Ich werde kopiert.
  
  /* Dies bedeutet, dass die Speicherregionen von str und str2 genau hintereinander liegen.
   * In dem Moment, wo strcpy über das letzte Zeichen von str2 schreibt, 
   * werden die ersten Zeichen von str überschrieben */

  /* All dies, um zu sagen, dass man strcpy und Konsorten nicht benutzen sollte,
   * wenn es sich vermeiden lässt */

  return 0;
}
