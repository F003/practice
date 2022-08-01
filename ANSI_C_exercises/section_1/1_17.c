#include <stdio.h>
#define MAXLENGHT 1000
#define MINLENGHT 80

int get_line(char line[], int maxlen);

int main()
{
	char line[MAXLENGHT];
	int len;

	while ((len = get_line(line, MAXLENGHT)) > 0)
		if (len >= MINLENGHT)
			printf("%s\n", line);
	return 0;
}

int get_line(char s[], int max)
{
		int i, c;

		for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
			s[i] = c;
		s[i] = '\0';
		return i;
}
