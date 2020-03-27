#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double* array;
  array = (double*) malloc(sizeof(double)*4);

  double staticarray[4] = {1.0,2.0,3.0,4.0};

  double *pointatarray = staticarray;

  printf("sizeof(array): %ld bytes\n",sizeof(array));
  printf("sizeof(double*): %ld bytes\n", sizeof(double*));
  printf("sizeof(double): %ld bytes\n", sizeof(double));
  printf("sizeof(staticarray): %ld bytes\n", sizeof(staticarray));
  printf("sizeof(pointatarray): %ld bytes\n", sizeof(pointatarray));
  printf("%lf\n", pointatarray[2]);
  return 0;
}
