#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Variables:
	double an, a1=0.1, a2=2.5, q, n=3;
	q = pow(a2/a1, 1/(n-1));
	printf("\nQ = %.2lf", q);
	return 0;
}
