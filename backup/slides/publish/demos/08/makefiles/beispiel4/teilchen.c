#include "kinEnerg.h"
#include "AblT.h"
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_rng.h>
int main(void){
  // GSL Zufallszahlengenerator initialisieren
  const gsl_rng_type * generator_type;
  gsl_rng * r;
  gsl_rng_env_setup();
  // sehr guten Zufallszahlengenerator wählen
  generator_type = gsl_rng_ranlxd2;
  r = gsl_rng_alloc(generator_type);
  double x[1000];
  for(unsigned int n = 0; n < 1000; n++ ){
    // im Intervall 0 bis 1 uniforme Zufallszahlen generieren 
    // und "rauschen" an den Cosinus anmultiplizieren
    x[n] = cos(n*0.01)+0.001*gsl_rng_uniform(r);
  }
  for(unsigned int n = 1; n < 999; n++ ){
    printf("%lf %lf %lf %lf\n", 0.01*n, x[n], AblT( x, n, 1000),
                                kinEnerg( x, 1.0, n, 1000 ) 
          );
  }
  // Zufallszahlengenerator deallokieren
  gsl_rng_free(r);
  return 0;
} 

