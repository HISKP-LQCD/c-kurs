#include "dbl_bintree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv) {
  int size; 
  int print_sorted = 1;
  parse_args(argc, argv, &size, &print_sorted);

  struct timeval end;
  struct timeval start;

  // memory to hold our unsorted data
  double *unsorted = malloc( size*sizeof(double) );
  // memory to hold pointers to our sorted data
  double **sorted = malloc( size*sizeof(double*) );
  assert( unsorted != NULL ); assert( sorted != NULL );
  
  // for testing a sorting algorithm, rand() is fine
  srand(time(NULL));
  for( int i = 0; i < size; i++ ){
    unsorted[i] = rand();
  }
  // init complete binary tree
  // fill with data to make balanced binary tree
  // enforce heap condition everywhere
  // in the first iteration, the largest element will be at the top of the heap
  // already
  gettimeofday( &start, NULL );
  dbl_heap_t* heap = init_dbl_heap( unsorted, size );
  gettimeofday( &end, NULL );
  print_time_diff( &end, &start, "init_dbl_heap" );

  dbl_bt_node_t* tail_node = NULL;
  gettimeofday( &start, NULL ); 
  for( int i = 0; i < size; i++ ){
    // the largest element is at the root node
    sorted[i] = heap->bt->root->data;
    
    // find a tail node somewhere at the bottom of the heap
    tail_node = find_tail_node_dbl_bt( heap->bt->root );
    
    // swap the root node (the largest element) with this tail node
    swap_data_dbl_bt( heap->bt->root, tail_node );
    // remove largest element from heap by dereferencing it
    tail_node->data = NULL;
    (heap->size)--;
    
    // restore heap property
    heapify_dbl_bt( heap->bt->root );
  }
  gettimeofday( &end, NULL );
  print_time_diff( &end, &start, "heapsort" );

  if( print_sorted ){
    for( int i = 0; i < size; i++ ){
      printf("%lf\n", *sorted[i]);
    }
  }

  free_dbl_heap(heap);
  free(unsorted); free(sorted);
  return 0;
}

