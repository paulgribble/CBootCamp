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
