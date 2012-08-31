// gcc -Wall -o go 6_3.c

#include <stdio.h>

int fib(int n);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("error: please pass a number\n");
    return 1;
  }
  else {
    int n = atoi(argv[1]);
    if (n<0) {
      printf("error: n must be >= 0\n");
      return 1;
    }
    else {
      printf("fib(%d)=%d\n", n, fib(n));
      return 0;
    }
  }
}

int fib(int n)
{
  int i;
  if ((n==0) | (n==1)) return n;
  int a = 0;
  int b = 1;
  int tmp;
  for (i=0; i<n; i++) {
    tmp = b;
    b = a+b;
    a = tmp;
  }
  return a;
}

