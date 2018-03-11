#include <stdio.h>
int main(void){
  struct Position_st{
    double x;
    double y;
  };
  
  struct Position_st t;
  t.x = 1.1;
  t.y = 1.2;
  printf("x = %lf, y = %lf\n",t.x, t.y); 

  return 0;
}
