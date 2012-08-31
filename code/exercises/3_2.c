// gcc -Wall -o go 3_2.c -lm

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
  double a, b, c, x1, x2;
  a = 1.2;
  b = 2.3;
  c = -3.4;
  x1 = (-b + sqrt((b*b) - (4*a*c))) / (2*a);
  x2 = (-b - sqrt((b*b) - (4*a*c))) / (2*a);
  printf("%.2f x^2 + %.2f x + %.2f = 0\n", a, b, c);
  printf("x = %.5f and %.5f\n", x1, x2);
  return 0;
}
