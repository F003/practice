#include <stdio.h>

/* zliczanie liczby wierszy strumienia wejściowego */
int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf ("%d\n", nl);
}
