Matrix matrixmult(Matrix A, Matrix B)
{
  // fill in the code here
  // printf("so far matrixmult does nothing\n");
  Matrix C;
  if (A.ncols != B.nrows) {
    printf("error: ncols of A does not equal nrows of B\n");
  }
  else {
    int i, j, k;
    double count;
    for (i=0; i<A.nrows; i++) {
      for (j=0; j<B.ncols; j++) {
	count = 0.0;
	for (k=0; k<A.ncols; k++) {
	  count += A.data[i*A.ncols + k] * B.data[k*B.ncols + j];
	}
	C.data[i*A.nrows + j] = count;
      }
    }
    C.nrows = A.nrows;
    C.ncols = B.ncols;
  }
  return C;
}
