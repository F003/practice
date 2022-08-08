#include <stdio.h>

#define MAXLENGHT 1000
#define SPACES_IN_TAB 8

int get_line(char line[], int maxlenght);
void copy (char to[], char from[]);
void entab(char line[]);

int main()
{
	int len;
	char line[MAXLENGHT];

	while ((len = get_line(line, MAXLENGHT)) > 0) {
		entab(line);
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

void copy(char b[], char a[])
{
	int i;
	for (i = 0; (b[i] = a[i]) != '\0'; ++i)
		;
}

void entab(char line[])
{
	int i, j, nspaces, ntabs;
	char c, newline[MAXLENGHT];

	for (i = j = 0; (c = line[i]) != '\0'; ++i) {
		if (c != ' ' && c != '\t') {
			if (nspaces != 0) {
				ntabs = nspaces / SPACES_IN_TAB;
				nspaces = nspaces % SPACES_IN_TAB;
				while (ntabs != 0) {
					newline[j] = '\t';
					++j;
					--ntabs;
				}
				while (nspaces != 0) {
					newline[j] = ' ';
					++j;
					--nspaces;
				}
			}
			newline[j] = c;
			++j;
		}

		else if (c == ' ')
			++nspaces;
		else
			nspaces = nspaces + SPACES_IN_TAB;
	}

	copy(line, newline);
}
