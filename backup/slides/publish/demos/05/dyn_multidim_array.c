#include <stdlib.h>
#include <stdio.h>
int main(void){
  unsigned int N_z = 27;
  unsigned int N_s = 13;
  double *matrix_mem = malloc( N_z*N_s*sizeof(double) );
  double **Matrix = malloc( N_z*sizeof(double*) );
  for( unsigned int z = 0; z < N_z; z++ ){
    Matrix[z] = matrix_mem + N_s*z;
  }
  Matrix[2][1] = 0.3;
  printf("Matrix[2][1] = %lf, Matrix[2][1] = %lf\n", 
          Matrix[2][1],       *(Matrix[2]+1) );

  free(Matrix);
  free(matrix_mem);
  return 0;
}
