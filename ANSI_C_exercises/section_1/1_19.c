#include <stdio.h>

#define MAXLENGHT 1000

int get_line(char line[], int max);
void reverse (char s[], int len);

int main()
{
	int i, len;
	char line[MAXLENGHT];

	for (i = 0; (len = get_line(line, MAXLENGHT)) > 0; ++i) {
		if (i % 2 != 0)
			reverse(line, len - 2);
		printf("%s", line);
	}
	return 0;
}

int get_line(char line[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void reverse(char s[], int len)
{
	char newline[len];
	int i;
	
	for (i = 0; i < len; ++i)
		newline[i] = s[len - i];
	for (i = 0; i < len; ++i)
		s[i] = newline[i];
}


