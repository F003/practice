#include <stdio.h>

int main()
{
	float celsius, fahr;
	int lower, upper, step;
	lower = -100;
	upper = 100;
	step = 20;
	
	celsius = lower;
	while(celsius <= upper){
		fahr = 9.0/5.0 * celsius + 32.0;
		printf("%4.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
