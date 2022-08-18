#include <stdio.h>
#include <limits.h>

#define U_MIN 0 /* for every unsigned variable, the smallest value is 0 */

unsigned long power(int base, int exponent); /* whole, positive exponentiation */
int size(long min, unsigned long max); /* with given whole minimum and maximun value returns size in bits */
int main()
{
	/* char */
	printf("\nChar\nSize: %d bits\nMin: %d\nMax: %d\n\n", CHAR_BIT, CHAR_MIN, CHAR_MAX);

	/* unsigned char */
	printf("Unsigned char\nSize: %d bits\nMin: %d\nMax: %d\n\n", size(U_MIN, UCHAR_MAX), U_MIN, UCHAR_MAX);

	/* signed char */
	printf("Signed char\nSize: %d bits\nMin: %d\nMax: %d\n\n", size(SCHAR_MIN, SCHAR_MAX), SCHAR_MIN, SCHAR_MAX);
	
	/* unsigned short */
	printf("Unsigned short\nSize: %d bits\nMIN: %d\nMax: %d\n\n", size(U_MIN, USHRT_MAX), U_MIN, USHRT_MAX);

	/* signed short */
	printf("Signed short\nSize: %d bits\nMIN: %d\nMax: %d\n\n", size(SHRT_MIN, SHRT_MAX), SHRT_MIN, SHRT_MAX);
	
	/* unsigned int */
	printf("Unsigned int\nSize: %d bits\nMIN: %d\nMax: %u\n\n", size(U_MIN, UINT_MAX), U_MIN, UINT_MAX);
	
	/* int */
	printf("Signed int\nSize: %d bits\nMIN: %d\nMax: %d\n\n", size(INT_MIN, INT_MAX), INT_MIN, INT_MAX);
	
	/* unsigned long */
	printf("Unsigned long\nSize: %d bits\nMIN: %d\nMax: %lu\n\n", size(U_MIN, ULONG_MAX), U_MIN, ULONG_MAX);

	/* signed long */
	printf("Signed long\nSize: %d bits\nMIN: %ld\nMax: %ld\n\n", size(LONG_MIN, LONG_MAX), LONG_MIN, LONG_MAX);

	return 0;
}

unsigned long power(int b, int e)
{
	unsigned long i;
	for (i = 1; e > 0; --e) 
		i = i * b;
	return i;
}

int size(long min, unsigned long max)
{
	int i;
	/* to make number of values storable in long they are devided by 4 before storing */
	unsigned long nvalues_dev8 = max - min;
	for (i = 0; power(2, i) <= nvalues_dev8; ++i)
		;
	i = i + 3; /* adjusting for nvalues being devided by 8 beforehand */
	return i;
}
