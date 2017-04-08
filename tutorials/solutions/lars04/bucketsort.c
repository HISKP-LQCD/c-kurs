#include "bucketsort.h"

int bucket_sort(unsigned short *array, unsigned len) {

	unsigned *buckets, max, i, array_index;
	unsigned short k;

	/* Finde das Maximum des arrays. */
	for (i=0; i<len; i++)
		if (array[i] > max) max = array[i];

	/* Da wir auch in array[max] mindestens einmal
	 * etwas eintragen wollen, m�ssen wir eine
	 * Speicherzelle mehr als max allokieren. */
	max += 1;

	/* Allokiere Speicher f�r die Buckets. */
	if ( (buckets = malloc(max*sizeof(int))) ) {
		/* Alle Buckets zu 0 initialisieren. */
		memset(buckets, 0, max*sizeof(int));
		/* F�r jeden eintrag im array erh�hen wir nun den
		 * Wert des entsprechenden Buckets um eins. */
		for (i=0; i<len; i++)
			buckets[array[i]]++;
		/* Wir m�ssen nun den Array neu beschreiben: */
		array_index = 0;
		/* F�r jede m�gliche Zahl, die vorkommen kann, */
		for (k=0; k<max; k++)
			/* iteriere durch den entsprechenden Bucket
			 * und f�lle array langsam auf. */
			for (i=0; i<buckets[k]; i++)
				array[array_index++] = k;
		/* Wir k�nnen nun den Speicher f�r die Buckets
		 * wieder freigeben. */
		free(buckets);
		return 0;
	} else {
		return 1;
	}
}

