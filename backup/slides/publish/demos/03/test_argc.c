#include <stdio.h>
int main(int argc, char **argv){
  // Der Programmaufruf $ ./test_argc 1 2 3 4
  // wird hier '5' ausgeben, weil der Name des Prgramms (genauer, wie es aufgerufen wurde)
  // als erses Argument übergeben wird
  printf("Anzahl Argumente: %d\n", argc);
  return 0;
}
