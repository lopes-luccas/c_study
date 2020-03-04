#include <stdio.h>

int main()
{
	double f, c1;
	int c2, f1;
	scanf("%lf", &f);
	c1 = (f - 32.0) * 5.0/9.0;
	f1 = f;
	c2 = (f1 - 32) * 5/9;
	printf("Celsius in double: %.2lf", c1);
	printf("\nCelsius in int: %d", c2);
	return 0;
}
