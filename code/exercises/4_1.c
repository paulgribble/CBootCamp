// gcc -Wall -o go 4_1.c

#include <stdio.h>
 
int main(int argc, char **argv)
{
  int i;
  for (i=1; i<=100; i++)
    {
      if (!(i % 3) && !(i % 5))
	printf("%d FizzBuzz", i);
      else if (!(i % 3))
	printf("%d Fizz", i);
      else if (!(i % 5))
	printf("%d Buzz", i);
      else
	printf("%d", i);
      printf("\n");
    }
  return 0;
}
