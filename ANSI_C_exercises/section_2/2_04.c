#include <stdio.h>
#define MAXLENGHT 1000
#define DELETE "qwerty" //characters to delete

int get_line(char line[], int maxlenght);
void squeeze(char line[], char delete[]);

int main()
{
	int c;
	char line[MAXLENGHT], delete[MAXLENGHT] = DELETE;
	while ((c = get_line(line, MAXLENGHT)) > 0) {
		squeeze(line, delete);
		printf("%s", line);
	}
	return 0;
}

int get_line(char line[], int max)
{
	int c, i;
	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

void squeeze(char line[], char del[])
{
	int i, j, k;

	for (i = j = 0; line[i] != '\0'; ++i) {
		for (k = 0; del[k] != '\0' && del[k] != line[i]; ++k)
			;
		if (del[k] == '\0')
			line[j++] = line[i];
	}
	line[j] = '\0';
	return;
}
