#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	double an, a1=1, a2, a3=7, a4, n=3, r, soma;
	r = (a3-a1)/(n-1);
	n=2;
	a2 = a1 + (n - 1)*r;
	printf("a2 = %.2lf", a2);
	n = 4;
    a4 = a1 + (4 - 1)*r;
	printf("\na4 = %.2lf", a4);
	soma = a2+a4;
	printf("\nSoma de a2 + a4 = %.2lf", soma);
	return 0;
}
