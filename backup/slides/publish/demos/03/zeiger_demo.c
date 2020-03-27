#include <stdio.h>
int main(void){
  double x = 4.2;
  double y = 5.4;
  int k = 3;
  
  /* wir weisen den Zeigern auf double, z_x und z2_x, die Adresse von x zu
   * können also jetzt über z_x, z2_x und x selbst auf x zugreifen */
  double *z_x = &x;
  double *z2_x = &x;

  // um an den Wert von x ranzukommen, müssen wir die Zeiger dereferenzieren
  printf("x = %lf aber auch *z_x = %lf und *z2_x = %lf\n", x, *z_x, *z2_x);

  // wir können x, über den Zeiger z_x, den Wert 7.2 zuweisen
  *z_x = 7.2;

  printf("x = %lf aber auch *z_x = %lf und *z2_x = %lf\n", x, *z_x, *z2_x);

  /* wir können den zeiger z2_x aber auch auf ein anderes Objekt zeigen lassen
   * z.B. y ! */
  z2_x = &y;

  printf("x = %lf aber auch *z_x = %lf, jetzt aber nicht mehr: *z2_x = %lf\n", x, *z_x, *z2_x);
  
  /* NULL ist ein spezieller Zeiger, der auf nichts deutet (genauer gesagt, deuter er auf die Adresse "0")
   * NULL hat den Wert eines "void"-Zeigers, wir müssen also ein explizites Typecast nutzen */
  z2_x = (double*) NULL;

  /* Diese Adresse ist vom Betriebsystem reserviert und man darf nicht darauf zugreifen
   * es wird hier ein Segmantation Fault auftreten, weil wir versuchen NULL zu derferenzieren */
  printf("%lf aber auch %lf und %lf\n", x, *z_x, *z2_x);

  return 0;
}
