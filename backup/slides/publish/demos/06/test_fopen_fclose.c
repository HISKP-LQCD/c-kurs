#include <stdlib.h>
#include <stdio.h>
int main(void){
  FILE* sw = fopen("sw.txt","r");
  if( sw == NULL ){
    printf("Fehler 1\n");
    exit(21);
  }
  fclose(sw);
  sw = fopen("..\\06\\sw.txt","r");
  if( sw == NULL ){
    printf("Fehler 2\n");
    exit(21);
  }
  fclose(sw);
  return 0;
}
