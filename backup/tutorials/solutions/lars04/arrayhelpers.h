#ifndef ARRAYHELPERS_H_
#define ARRAYHELPERS_H_

#include <stdio.h>

void array_print   (int *array, int length); /* array ausgeben */
void array_sort    (int *array, int length); /* array sortieren */
void array_rotate1 (int *array, int length); /* array um 1 rotieren */
void array_reverse (int *array, int length); /* array umdrehen */

/* Array um k Stellen rotieren */ 
void array_rotate  (int *array, int length, int k);

/* suche das array needle im array haystack und liefere
 * die position des ersten Auftretens. Falls needle nicht
 * in haystack vorkommt, liefere -1. */
int  array_search  (int *haystack, int haystack_length,
                    int *needle,   int needle_length);

#endif /*ARRAYHELPERS_H_*/
