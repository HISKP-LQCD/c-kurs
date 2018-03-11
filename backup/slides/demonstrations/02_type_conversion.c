#include <stdio.h>
#include <limits.h>

int main(void) {
  double longreal = 980923.8990878971224230982983;
  float shortreal = 0.0;

  int integer = INT_MIN;
  unsigned int uns_integer = 0;

  printf("int: %d   unsigned int: %u \n\n", integer, uns_integer);

  integer = INT_MAX + 8787823;
  printf("integer overflow: %d \n\n", integer);

  shortreal = longreal;
  printf("double: %.36lf   float: %.16f \n\n", longreal, shortreal);
  
  return 0;
}

