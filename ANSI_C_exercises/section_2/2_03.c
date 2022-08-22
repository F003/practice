#include <stdio.h>
#include <limits.h>

#define MAXLENGHT 12 /* to store in int hex can't be smaller than -80000000 with 3 volountary signs -0x and '\0' */
#define HEX 16

int get_line(char line[], int maxlenght);
void to_lower(char line[]);
int htoi(char s[]);
int str_len(char string[]);

int main()
{
	int len;
	char line[MAXLENGHT];
	while ((len = get_line(line, MAXLENGHT)) > 0) {
		printf("%d\n", htoi(line));
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

void to_lower(char line[])
{
	for (int i = 0; line[i] != '\0'; ++i)
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] = line[i] + 'a' - 'A';
	return;
}
int str_len(char str[])
{
	int i;
	for (i = 0; str[i] != '\n' && str[i] != '\0'; ++i)
		;
	return i;
}

int htoi(char hex[])
{
	to_lower(hex);
	int i;
	int negative = 0; /* if == 1 value will be multiplied by -1 before returning */
	unsigned int value = 0;
	int multiplier = 1; /* power of 16 that the new digit will be multiplied */
	const int len = str_len(hex);
	for (i = len - 1; i >= 0; --i) {
		
		// checks if hex is negative
		if (i == 0 && hex[i] == '-') {
			negative = 1;
		}

		// if prefix 0x/0X is added
		else if ((i == 1 || i == 2) && hex[i-1] == '0' && hex[i] == 'x'){
			--i;
		}
		// if digit is number used in dec
		else if (hex[i] >= '0' && hex[i] <= '9') {
			value = value + (hex[i] - '0') * multiplier;
			if (value > INT_MAX) {
				printf("Value too big or too small.\nERROR CODE: ");
				return 0;
			}
			multiplier = multiplier * HEX;
		}
		
		// if digit is coded as a letter
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			value = value + (hex[i] - 'a' + 10) * multiplier;
			if (value > INT_MAX) {
				printf("Value too big or too small.\nERROR CODE: ");
				return 1;
			} 
			multiplier = multiplier * HEX;
		} 
		
		// if input is not a digit or prefix in hex
		else {
			printf("Incorrect input.\nERROR CODE: ");
			return 2;
		}
	}
	if (negative == 1)
		return (int)(value * -1);
	else
		return (int)value;
 
}
