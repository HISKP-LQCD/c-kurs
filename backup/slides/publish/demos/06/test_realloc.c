#include <stdlib.h>
#include <stdio.h>
int main(void){
  double *x = malloc( sizeof(double)*20 );
  double *y = malloc( sizeof(double)*20 );
  double *temp = realloc( x, sizeof(double)*25 );
  if( temp == NULL ){
    printf("Fehlgeschlagen\n");
  } else {
    printf("%p %p\n", (void*)x, (void*)temp);
    x = temp;
  }

  return 0;
}
