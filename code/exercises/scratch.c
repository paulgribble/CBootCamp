#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double *data;
  //  double data[MAXDATA];
  int nrows;
  int ncols;
} Matrix;

void printmat(Matrix M);

int main(int argc, char *argv[])
{
  Matrix A;
  
  A.nrows = 3;
  A.ncols = 2;

  A.data = malloc(A.nrows*A.ncols*sizeof(double));

  A.data[0] = 1.2;
  A.data[1] = 2.3;
  A.data[2] = 3.4;
  A.data[3] = 4.5;
  
  printmat(A);

  free(A.data);
}


void printmat(Matrix M)
{
  // fill in the code here                                             
  // printf("so far printmat does nothing\n");                         
  int i, j;
  printf("[\n");
  for (i=0; i<M.nrows; i++) {
    for (j=0; j<M.ncols; j++) {
      printf("%6.3f ", M.data[i*M.ncols + j]);
    }
    printf("\n");
  }
  printf("]\n\n");
}

