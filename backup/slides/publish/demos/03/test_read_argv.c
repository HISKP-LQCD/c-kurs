#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
  // argv ist ein Array von strings (null-terminierte char-Arrays)
  for(unsigned int i = 0; i < argc; ++i){
    // wir können uns also jedes Argument einfach so ausgeben lassen
    printf("Argument %d: %s\n", i, argv[i]);
  }
  // Die Funktion atoi erlaubt es, einen String der nur eine Ganzzahl entält in
  // einen Integer zu verwandeln
  printf("%d\n", atoi(argv[1]) );

  // wenn das erste Argument von test_read_argv also ein integer ist
  // können wir es auch einer Variable zuweisen
  int k = atoi(argv[1]);
  printf("%d\n", k);
  return 0;
}
