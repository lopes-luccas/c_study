#include <stdio.h>
#include <math.h>

int main()
{
	int a=10, b=15, c, x, x1, x2, delta;
	c = b - a;
	printf("a = b - c => c=%d", c);
	printf("\nDigite a:");
	scanf("%d", &a);
	x = a + b - c;
	printf("X = %d", x);
	a=1; 
	b=12;
	c= -13;
	delta = b*b-4*a*c;
	x1 = (-b+(sqrt(delta)))/2*a;
	x2 = (-b-(sqrt(delta)))/2*a;
	printf("\nx1= %d", x1);
	printf("\nx2= %d", x2);
	return 0;
}
