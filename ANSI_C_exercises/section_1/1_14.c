#include <stdio.h>
#define ASCII_START 9 //first ASCII character that I am considering as usefull is horizontal tab (ASCII 9)
#define ASCII_END 126 //the last usefull ASCII char that I acknowledged is tilde (ASCII 126)
#define NUMBER_OF_CHARACTERS 117 //126 - 9 = 117 characters that the app will be counting

int main()
{
	int c, nc[NUMBER_OF_CHARACTERS];

	for (int i = 0; i < (NUMBER_OF_CHARACTERS); ++i)
		nc[i] = 0;
	
	while ((c = getchar()) != EOF)
		if (c > ASCII_START || c < ASCII_END)
			++nc[c-ASCII_START];

	for (int i = 0; i < NUMBER_OF_CHARACTERS; ++i){
		printf("%3d ", i + ASCII_START);
		for (int j = 0; j < nc[i]; ++j)
			putchar('|');
		putchar('\n');
	}

}
