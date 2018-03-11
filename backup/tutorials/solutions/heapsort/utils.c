#include "utils.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
void
print_time_diff( struct timeval* end, struct timeval* start, char* string ){
  double secs = (double)end->tv_sec + 1.0e-6*(double)end->tv_usec -
                (double)start->tv_sec - 1.0e-6*(double)start->tv_usec;
  printf("%s took: %lf seconds\n", string, secs);
}

void
parse_args( const int argc, char **argv, int* size, int* print_sorted ){
  if( argc < 2 ){
    print_usage();
  } else {
    (*size) = atoi( argv[1] );
  }
  if( argc == 3 ){
    (*print_sorted) = atoi( argv[2] );
  }
}

void
print_usage(void){
  printf("usage: ./heapsort <n> [ print sorted: 0,1 ]\n");
  exit(1);
}

