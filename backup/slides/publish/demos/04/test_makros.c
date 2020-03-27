#include <stdio.h>
//#include "test_include.c"
#define MY_PI 3.1415
int main(void){
  printf("PI ist: %lf\n", MY_PI);
  #ifdef EULER
  printf("EULER ist: %lf\n", EULER);
  #else
  printf("EULER ist nicht definiert\n");
  #endif // ifdef(EULER) 
  return 0;
}
