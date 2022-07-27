#include <stdio.h>


/* zliczenie znaków strumienia wejściowego; pierwsza wersja */
int main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
