// program should be called detab, but I've chosen to stay with consistent naming 
#include <stdio.h>
#define MAXLENGHT 1000000
#define SPACES_IN_TAB 8

int main()
{
	int j, i = 0;
	char c, input[MAXLENGHT];
	while (i < MAXLENGHT - 1 && (c=getchar()) != EOF){
		input[i] = c;
		if (c == '\t')
			for (j = 0;	j < SPACES_IN_TAB; ++j) {
				input[i] = ' ';
				++i;
			}
		else
			++i;
	}
	input[i] = '\0';

	printf("%s", input);
	
	return 0;
}
