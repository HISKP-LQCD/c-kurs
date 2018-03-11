// Copyright © 2017 Martin Ueding <dev@martin-ueding.de>
// Licensed under the MIT license

// Implementierung des Primzahlentests.

#include <stdio.h>

int main(int argc, char **argv)
{
  // Zahl, die eventuell eine Primzahl ist, im Pseudocode $c$ genannt.
  int const kandidat = 27;

  // Bis wir einen Teiler gefunden haben, nehmen wir an, dass es sich um eine
  // Primzahl handelt.
  int is_prime = 1;

  // Wir müssen alle Teiler durchgehen. Allerdings müssen wir nur solange
  // suchen, bis wir $teiler = \sqrt{kandidat}$ ist. Ab diesem Punkt gibt es
  // keine weiteren Teiler mehr, die wir nicht schon gefunden hätten.
  // Angenommen wir haben 16 als Kandidat. Den Teiler 8 brauchen wir nicht
  // prüfen, da wir 2 schon geprüft haben.
  for (int teiler = 2; teiler * teiler < kandidat; ++teiler)
    {
      // Teilt der Teiler den Kandidaten glatt (Rest ist Null), so kann es sich
      // nicht mehr um eine Primzahl handeln. Wir setzen also `is_prime` auf
      // »unwahr« und brechen die `for`-Schleife ab.
      if (kandidat % teiler == 0)
        {
          is_prime = 0;
          break;
        }
    }

  if (is_prime)
    {
      printf("%d ist eine Primzahl.\n", kandidat);
    }
  else
    {
      printf("%d ist keine Primzahl.\n", kandidat);
    }

  return 0;
}
