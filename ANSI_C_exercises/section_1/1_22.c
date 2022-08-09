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

	while ((len = get_line(line, MAXLENGHT)) > 0) {
			lbr_pointer = 0;
			linebreaker(line, len);
	}

	return 0;
}

void linebreaker(char line[], int len)
{
	/* skipping whitespaces on beggining of lines */ 
	while ((line[lbr_pointer] == ' ' || line[lbr_pointer] == '\t') && lbr_pointer < len-1)
		++lbr_pointer;
	/* string is printeble in single line */
	if (len - lbr_pointer <= MAXPRINTSIZE + 1) {
		
		while (lbr_pointer < len-1) {
			putchar(line[lbr_pointer]);
			++lbr_pointer;
		}
		putchar('\n');
	}

	/* string is not printable in a single line */
	else {
		int i = lbr_pointer + MAXPRINTSIZE;
		while (i > lbr_pointer && line[i] != '\t' && line[i] != ' ') /* searching for viable breaking point */
			--i;

		/* viable breaking point have been found */
		if (i != lbr_pointer) {
			while (lbr_pointer < i) {
				putchar(line[lbr_pointer]);
				++lbr_pointer;
			}
		}

		/* breaking point not found - printing '...' instead of additional characters */
		else {
			while (lbr_pointer < i + MAXPRINTSIZE - 3) { 
				putchar(line[lbr_pointer]);
				++lbr_pointer;
			}
			while (line[lbr_pointer] != ' ' && line[lbr_pointer] != '\t' && line[lbr_pointer] != '\n')
				++lbr_pointer;
			printf("...");
		}
		putchar('\n');
		linebreaker(line, len); /* using the same function for the rest of a string */
	}
}

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
