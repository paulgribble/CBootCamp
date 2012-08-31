#include <stdio.h>
#include <stdlib.h>

int main() {
	char intString[] = "1234";
	char floatString[] = "328.4";
	int myInt = atoi(intString);
	double myDouble = atof(floatString);
	printf("intString=%s, floatString=%s\n", intString, floatString);
	printf("myInt=%d, myDouble=%.1f\n\n", myInt, myDouble);

	int a = 2;
	double b = 3.14;
	char myString1[64], myString2[64];
	sprintf(myString1, "%d", a);
	sprintf(myString2, "%.2f", b);
	printf("a=%d, b=%.2f\n", a, b);
	printf("myString1=%s, myString2=%s", myString1, myString2);
	return 0;
}
