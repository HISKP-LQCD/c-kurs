#include <stdio.h>
#include <string.h>
int main(void){
  char quelle[50] = "Dies_ist_ein_etwas_längerer_String.";
  double x = 4.2;
  double y = 6.2;
  double z = 3.4;
  char ziel[10] = "123456789";

  // vor strcpy
  printf("x = %lf, y = %lf, z = %lf\n", x, y, z);

  printf("Vor: %s %s\n", quelle, ziel);
  
  
  strcpy(ziel, quelle);
  
  // nach strcpy
  printf("%s\n", (char*)&x);
  printf("x = %lf, y = %lf, z = %lf\n", x, y, z);

  return 0;
}
