#include <stdio.h>

double func(double omega){
  return 2*omega;
}

double void_func(){
  return (double)3234.32;
}

int main(void){
  double (*void_fp)();
  double (*fp)(double);

  fp = void_func;
  void_fp = func;

  double x = void_func();
  double y = (*fp)(32);
  double z = (*void_fp)(55);

  printf("%lf %lf %lf\n", x, y, z);

  return 0;
}
