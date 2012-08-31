// gcc -Wall -o go 9_1.c

#include <stdio.h>

int main(int argc, char *argv[])
{
  char *provinces[] = { "British Columbia", "Alberta", "Saskatchewan", 
                        "Manitoba", "Ontario", "Quebec", "New Brunswick",
                        "Nova Scotia", "Prince Edward Island", "Newfoundland",
                        "Yukon", "Northwest Territories", "Nunavut" };
  int i, j;
  char tmpchar;
  for (i=0; i<13; i++) {
    printf("provinces[%d] = %c", i, provinces[i][0]);
    j=1;
    while (provinces[i][j] != 0) {
      tmpchar = provinces[i][j];
      if ((provinces[i][j] >= 'a') && (provinces[i][j] <= 'z')) {
	tmpchar = provinces[i][j] - 32;
      }
      printf("%c", tmpchar);
      j++;
    }
    printf("\n");
  }
  return 0;
}
