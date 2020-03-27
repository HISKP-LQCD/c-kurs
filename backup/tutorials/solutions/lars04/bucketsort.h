#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_

#include <malloc.h>
#include <string.h>

/* Rückgabe: 0 bei Erfolg,
 *           1 bei Speicherversagen */
int bucket_sort(unsigned short *array, unsigned length);

#endif /* BUCKETSORT_H_ */
