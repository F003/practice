#include <stdio.h>

#define MAXLENGHT 1000

int get_line(char line[], int maxlenght);

int main()
{
	int i;
	char line[MAXLENGHT];
	while ((i = get_line(line, MAXLENGHT)) > 0)
		printf("%s", line);
	return 0;
}	

int get_line(char s[], int max)
{
	int c, i;

	//for (i = 0; i < max-1 &&  (c=getchar()) != EOF &&  c != '\n'; ++i)
	//	s[i] = c;
	int cont = 1; // bool, if true loop will continue
	i = 0;
	while (cont)
		if (i < max-1) {
			if ((c = getchar()) != EOF) {
				if (c != '\n')
					s[i++] = c;
				else
					cont = 0;
			} 
			else
				cont = 0;
		}
		else
			cont = 0;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
