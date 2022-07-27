#include <stdio.h>

#define IN 1	//wewnątrz słowa
#define OUT 0	//poza słowem

/* zliczanie wieszy, słów i znaków */
int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("\n%d %d %d\n", nl, nw, nc);
}
