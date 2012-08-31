// gcc -Wall -o go 6_1_go.c

#include <stdio.h>

#define MAXDATA 1024

typedef struct {
  double data[MAXDATA];
  int nrows;
  int ncols;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);

int main(int argc, char *argv[])
{
  Matrix A = { {1.2, 2.3,
		3.4, 4.5,
		5.6, 6.7},
	       3,
	       2};
  Matrix B = { {5.5, 6.6, 7.7,
		1.2, 2.1, 3.3},
	       2,
	       3}; 
  printmat(A);
  printmat(B);

  //  Matrix C = matrixmult(A, B);
  //  printmat(C);

  return 0;
}

// your code goes below...

void printmat(Matrix M)
{
  // fill in the code here
  printf("so far printmat does nothing\n");
}

Matrix matrixmult(Matrix A, Matrix B)
{
  // fill in the code here
  printf("so far matrixmult does nothing\n");
  Matrix C;
  return C;
}

