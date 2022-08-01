#include <stdio.h>
#define MAXLENGHT 1000
int get_line(line[], maxlenght);

int main()
{
	int characters, i;
	char line[MAXLENGHT];

	while ((ncharacters = get_line(line, MAXLENGHGT)) > -1){
		if (ncharacters > 0){
			for (i = 0; i < ncharacters; ++i)
				putchar(line[i]);
			putchar('\n);
		}

	return 0;
}
int get_line
