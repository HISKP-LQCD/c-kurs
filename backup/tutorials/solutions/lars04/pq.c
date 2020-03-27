int solve_quadratic_equation(
 /* IN */  double a,
 /* IN */  double b,
 /* IN */  double c,
 /* OUT */ double *solution_large,
 /* OUT */ double *solution_small
) {
    /* Wir prüfen *natürlich* nie, ob eine double-Variable "gleich" 0 ist,
       sondern prüfen, ob die Zahl betragsmäßig kleiner als unsere minimale
       Präzision ist. */
    double p,q;
    if (fabs(a) < PRECISION) { 
        /* Die Gleichung ist nicht quadratisch, sondern linear: */
        if (fabs(b) < PRECISION) {
            /* Die Gleichung ist von der Form c = 0. Wenn c numerisch
               gleich 0 ist, so hat die Gleichung unendlich viele Lösungen,
               in diesem Fall geben wir -1 zurück. Andernfalls gibt es 
               keine Lösung. */
            return 0 - (fabs(c) < PRECISION);
        } else {
            /* Dieser Fall ist einfach: */
            *solution_large = *solution_small = -c/b;
            return 1;
        }
    } else {
        double wurzelterm;
        
        /* Normalisiere die Gleichung zu x² + p x + q = 0 */
        p = b / a; 
        q = c / a;
        wurzelterm = (p*p)/4 - q;
    
        if ( wurzelterm < 0 ) /* irrationale Loesung */
            return 0;
        else wurzelterm  = sqrt(wurzelterm);

        /* Wende die p-q-Formel an. Die Funktion zum Berechnen einer 
           Quadratwurzel gibt es unter dem Namen sqrt in stdlib.h: */
        *solution_large = -(p/2) + wurzelterm;
        *solution_small = -(p/2) - wurzelterm;
        
        /* Wir prüfen, ob sich die beiden Lösungen überhaupt maßgeblich
           unterscheiden. Falls dem so ist, gibt es zwei Lösungen, andern-
           falls genau eine. */
        return 1 + (wurzelterm > PRECISION);
    }
}
