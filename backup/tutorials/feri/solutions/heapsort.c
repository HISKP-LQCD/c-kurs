#include<stdlib.h>
#include<stdio.h>

// versickere a[i] bis hoechstens a[m]
void versickere(int a[], int i, const int m) {
  while(2*i+1 <= m) { // a[i] hat linken Nachfolger
    int j = 2*i+1;    // a[j] ist linker Nachfolger
    if(j < m) {
      if(a[j] < a[j+1]) j++;
      // a[j] ist jetzt groesster Nachfolger
    }
    if(a[i] < a[j]) { // Vertausche mit groesserem Nachfolger
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      i = j;
    }
    else i = m;
  } // Heapbedingung wieder erfuellt
  return;
}

void HeapSort(int a[], const int N) {
  // erzeuge Heap
  for(int i = (N/2)-1; i >= 0; i--) {
    versickere(a, i, N-1);
  }

  // Sortiere durch versickern
  for(int i = N-1; i > 0; i--) {
    int t = a[i];
    a[i] = a[0];
    a[0] = t;
    versickere(a, 0, i-1);
  }
  return;
}

int main() {
  int a[] = {1,6,7,3,4,5,2,8};
  const int N = 8;
  printf("Eingabearray:\n");
  for(int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  HeapSort(a, N);

  printf("Sortiertes Array:\n");
  for(int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
