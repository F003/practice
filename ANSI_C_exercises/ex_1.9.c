#include <stdio.h>


int main()
{
	int c;
	char last_c;

	while ((c = getchar()) != EOF){
		if (c != ' ' || last_c != ' ')
			putchar(c);
		last_c = c;
	}
}
