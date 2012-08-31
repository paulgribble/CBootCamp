// gcc -Wall -o go 4_2.c

#include <stdio.h>

int main(int argc, char **argv)
{
  double x2 = 612;
  double x0 = 10;
  double xi;
  int i;
  for (i=0; i<5; i++) {
    xi = x0 - ( ((x0*x0) - x2) / (2*x0) );
    printf("x%d = %.12f, x%d = %.12f\n", i, x0, i+1, xi);
    x0 = xi;
  }
  return 0;
}
