#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 10

float convert(int);

int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %7.1f\n", fahr, convert(fahr));
	return 0;
}

float convert(int fahrenheit)
{
	float celsius;

	celsius = (5.0/9.0) * (fahrenheit - 32);
	return celsius;
}
