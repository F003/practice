#include <stdio.h>
#include <limits.h>

#define U_MIN 0 /* for every unsigned variable, the smallest value is 0 */

int power(int base, int exponent); /* whole, positive exponentiation */
int size(int min, int max); /* with given whole minimum and maximun value returns size in bits */
int main()
{
	/* char */
	printf("Char\nSize: %d bits\nMin: %d\nMax: %d\n\n", CHAR_BIT, CHAR_MIN, CHAR_MAX);

	/* unsigned char */
	printf("Unsigned char\nSize: %d bits\nMin: %d\nMax: %d\n\n", size(U_MIN, UCHAR_MAX), U_MIN, UCHAR_MAX);

	/* signed char */
	printf("Signed char\nSize: %d bits\nMin: %d\nMax: %d\n\n", size(SCHAR_MAX, SCHAR_MIN), SCHAR_MIN, SCHAR_MAX);

	return 0;
}

int power(int b, int e)
{
	int i;
	for (i = 1; e > 0; --e) 
		i = i * b;
	return i;
}
/* not working yet */
int size(int min, int max)
{
	int i;
	for (i = 0; power(2, i) <= max - min; ++i)
		;
	return i;
}
