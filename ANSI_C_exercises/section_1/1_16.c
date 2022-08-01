#include <stdio.h>
#define MAXLINE 1000
#define NMAXLINES 1000
#define MAXOUT 64

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len, i;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0){
		printf("\n%4d\t",len);
		for (i = 0; i < len - 1 && i < MAXOUT; ++i)
			putchar(line[i]);
		if (len >= MAXOUT)
			printf("...");
		putchar('\n');
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
		

