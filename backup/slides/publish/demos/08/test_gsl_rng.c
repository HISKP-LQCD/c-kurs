#include <stdio.h>
#include <gsl/gsl_rng.h>
int main (void) {
  const gsl_rng_type * generator_type;
  gsl_rng * r;
  gsl_rng_env_setup();
  generator_type = gsl_rng_ranlxd2;
  r = gsl_rng_alloc(generator_type);
  double u = gsl_rng_uniform(r);
  for(int i = 0; i < 50; i++) {
      u = gsl_rng_uniform (r);
      printf ("%.5f\n", u);
  }
  gsl_rng_free(r);
  return 0;
}
