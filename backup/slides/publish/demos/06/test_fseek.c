#include <stdlib.h>
#include <stdio.h>
int main(void){
  FILE* fp = fopen("format.txt","r");
  if( fp == NULL ){
    printf("Fehler 1\n");
    exit(21);
  }
  double x;
 
  printf("Dateicursor bei: %ld\n", ftell(fp) );
  fscanf(fp, "Test %lf\n", &x);
  printf("%lf\n",x);

  // Dateicursor an den Anfang der Datei bewegen
  fseek(fp, 0, SEEK_SET);

  printf("Dateicursor bei: %ld\n", ftell(fp) );
  x = 4.2;
  int elements = fscanf(fp, "Test %lf\n", &x);
  printf("%lf\n",x);
  printf("elements = %d\n", elements);

  fclose(fp);
  
  return 0;
}
