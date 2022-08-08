#include <stdio.h>

#define MAXLENGHT 1000
#define SPACES_in_TAB 8

int get_line(char line[], int maxlenght);
int entab(char line[]);
void copy (char to[], char from[]);

int main()
{
	int len;
	char line[MAXLENGHT];

	while ((len = get_line(line[], MAXLENGHT)) > 0) {
		entab(line);
		printf("%s", line);
	}
	return 0;
}

int getline(char line[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
