// gcc -Wall -o go 4_3.c

#include <stdio.h>

int main(int argc, char **argv)
{
  int n=6;
  int i, j;
  for (i=1; i<=n; i++) {
    for (j=0; j<(n-i); j++) { printf(" "); }
    for (j=(n-i); j<(n-i)+((2*i)-1); j++) { printf("*"); }
    printf("\n");
  }
  return 0;
}
