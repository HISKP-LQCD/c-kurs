#include "kinEnerg.h"
#include "AblT.h"
#include <stdio.h>
#include <math.h>
int main(void){
  double x[1000];
  for(unsigned int n = 0; n < 1000; n++ ){
    x[n] = cos(n*0.01);
  }
  for(unsigned int n = 1; n < 999; n++ ){
    printf("%lf %lf %lf %lf\n", 0.01*n, x[n], AblT( x, n, 1000),
                                kinEnerg( x, 1.0, n, 1000 ) 
          );
  }
  return 0;
} 

