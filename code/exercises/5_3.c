// gcc -Wall -o go 5_3.c

#include <stdio.h>

int isprime(int n);

int main(int argc, char *argv[])
{
  int i = 0;
  int count = 0;
  while (count<1000) {
    if (isprime(i) == 1)
      {
	printf("%d: %d\n", count+1, i);
	count++;
      }
    i++;
  }
  return 0;
}


int isprime(int n)
{
  if (n<=1) return 0;
  int i;
  for (i=2; (i*i)<=n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
