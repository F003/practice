#include <stdio.h>

int main()
{
	int c, ns, nt, nl;

	ns = 0;
	nt = 0;
	nl = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ')
			++ns;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("\n\tNumber of spaces:\t%6d\n\tNumber of tabs:%3d\n\tNumber of lines:\t%6d\n", ns, nt, nl);

	
}
