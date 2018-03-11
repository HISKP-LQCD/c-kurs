#ifndef UTILS_H
#define UTILS_H
#include <sys/time.h>
void print_time_diff( struct timeval* end, struct timeval* start, char* string );
void parse_args(const int argc, char **argv, int* size, int* print_sorted);
void print_usage(void);
#endif
