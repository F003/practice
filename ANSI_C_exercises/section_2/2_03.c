#include <stdio.h>
#include <limits.h>

#define MAXLENGHT 12 /* to store in int hex can't be smaller than -80000000 with 3 volountary signs -0x and '\0' */

int get_line(char line[], int maxlenght);
void to_lower(char line[]);
int htoi(char s[]);
int str_len(char string[]);

int main()
{
	int len;
	char line[MAXLENGHT];
	while ((len = get_line(line, MAXLENGHT)) > 0) {
		printf("%s", htoi(line));
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

char to_lower(char line[])
{
	for (int i = 0; line[i] != '\0'; ++i)
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] = line[i] + 'a' - 'A';
	return;
}
int str_len(char str[])
{
	for (int i = 0; str[i] != '\0'; ++i)
		;
	return i;
}

int htoi(char hex[])
{
	to_lower(hex);
	int i, negative;
	unsigned int value;
	int i = negative = 0;
	while (i < const str_len(hex)) {
		if (hex[0] == '-')
			negative = 1;

		if (

}
