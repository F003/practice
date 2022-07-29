#include <stdio.h>
#define ASCII_NOT_WHITESPACE 93 //number of non whitespace characters the app will be counting

int main()
{
	int c, nc[ASCII_NOT_WHITESPACE], tab, newline, space;
	tab = newline = space = 0;

	for (int i = 0; i < (ASCII_NOT_WHITESPACE); ++i)
		nc[i] = 0;
	
	while ((c = getchar()) != EOF){
		if (c >= '!' && c <= '~') // first and last not whitespace character that I am considering
			++nc[c-'!']; //exclamation marks will be counted in nc[0] and the row assigned to char will be its value - 33(value that represents !)
		else if (c == '\t')
			++tab;
		else if (c == '\n')
			++newline;
		else if (c == ' ')
			++space;
	}
	
	printf("\n\n\n     tab ");
	for (int i = 0; i < tab; ++i)
		putchar('|');
	printf("\nnew line ");
	for (int i = 0; i < newline; ++i)
		putchar('|');
	printf("\n   space ");
	for (int i = 0; i < space; ++i)
		putchar('|');
	for (int i = 0; i < ASCII_NOT_WHITESPACE; ++i){
		printf("\n       %c ", i + '!');
		for (int j = 0; j < nc[i]; ++j)
			putchar('|');
	}
	putchar('\n');

}
