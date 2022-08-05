#include <stdio.h>
#define MAXLENGHT 1000
int get_line(char line[], int maxlenght);
int get_lastchar(char line[], int lenght);

int main()
{
	int ncharacters, i, lastchar;
	char line[MAXLENGHT];

	while ((ncharacters = get_line(line, MAXLENGHT)) > 0) {
		if (ncharacters > 0){
			lastchar = get_lastchar(line, ncharacters);
			for (i = 0; i <= lastchar; ++i)
				putchar(line[i]);
			if (lastchar > 0)
				putchar('\n');
		}
	}

	return 0;
}

int get_line(char line[], int maxlenght)
{
	int c, i;

	for (i = 0; i < maxlenght - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

int get_lastchar(char line[], int len)
{
	int lastchar = len - 2;
	for (; lastchar > 0; --lastchar) 
		if (line[lastchar] != '\t' && line[lastchar] != ' ')
			break;
	return lastchar;
}


