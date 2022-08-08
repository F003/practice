#include <stdio.h>
#define MAXLENGHT 1000 /* max lenght of a single line */
#define MAXPRINTSIZE 80 /* maximum lenght of an line on output */

int get_line(char line[], int maxlen);
void linebreaker(char line[], int len); /* breaks line into multiple lines */

int lbr_pointer = 0; /* tells linebreaker where it should begin its work */

int main()
{
	char line[MAXLENGHT];
	int len;

	while ((len = get_line(line, MAXLENGHT)) > 0)
			linebreaker(line, len);

	return 0;
}

void linebreaker(char line[], int len)


		

int get_line(char line[], int max)
{
	int c, i;
	max = max - 1;

	for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}
