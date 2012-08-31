/* go.c
   Takes one input argument from the command line, an integer,
   and returns 1 if the number is prime, and 0 if it is not.

   Compile with: gcc -o go go.c primes.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("error: must provide a single integer value to test\n");
    return 1;
  }
  else {
    int n = atoi(argv[1]);
    int prime = isPrime(n);
    printf("isPrime(%d) = %d\n", n, prime);
    return 0;
  }
}

