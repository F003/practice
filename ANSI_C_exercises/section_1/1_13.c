#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_LENGHT 15
/* I assumed that sigle word takes no more that 27 characters.
That is the lenght of the longest word used in the work of Shakespeare:
honorificabilitudinitatibus. */

int main()
{
	int c, state, wl;
	int nw[MAX_LENGHT]; //number of words of certain lenght
	
	state = OUT;
	for (int i = 0; i < MAX_LENGHT; ++i)
		nw[i] = 0;
	while((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n' && c != ',' && c != '.' && c != ':' && c != ';') { //I think there is a better way to put it
			if (state)
				wl = 0;
			++wl;
		}
		else {
			//I assumed that input will not begin with whitespaces or punctuation
			nw[wl-1] = nw[wl-1] + 1;
			wl = 0;
			state = OUT;
		}
			
	}
	for (int i = 0; i < MAX_LENGHT; ++i){
		printf("%2d ", i + 1);
		for (int j = 0; j < nw[i]; ++j)
			putchar('|');
		putchar('\n');
	}

}
