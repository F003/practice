#include <stdio.h>


/* zliczenie znaków strumienia wejściowego; pierwsza wersja */
int main()
{
	double nc;
	
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc); 
}
