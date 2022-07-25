#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c, state;

	state = IN;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t')
			state = OUT;
		else{
			if (!state){
				state = IN;
				putchar('\n');
			}
			putchar(c);
		}
	}
}
