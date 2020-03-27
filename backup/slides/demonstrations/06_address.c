#include <stdio.h>

int x = 3.2;
int main(void){
  printf("Die Adresse von x ist %lx\n",(unsigned long int)&x);
  return 0;
}

