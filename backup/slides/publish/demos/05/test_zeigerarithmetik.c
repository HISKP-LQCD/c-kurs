#include <stdio.h>
int main(void){
  double x[4] = { 1.2, 2.3, 4.5, 6.6 };
  double *z1_x = &x[0];
  double *z2_x = &x[1];

  printf("x[0] = %lf, x[1] = %lf, x[2] = %lf, x[3] = %lf\n",x[0],x[1],x[2],x[3]);

  printf("x[3] = %lf, *(z1_x+1) = %lf, *(z2_x-1) = %lf,\
          z1_x[1] = %lf\n", x[3], *(z1_x+1), *(z2_x-1), z1_x[1]);
  
  return 0;
}
