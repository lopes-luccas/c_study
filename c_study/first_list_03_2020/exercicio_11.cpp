#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	double an, a1, n, r;
	r = 2;
	printf("Digite a razão:");
	scanf("%lf", &r);
	printf("\nDigite a1:");
	scanf("%lf", &a1);
	printf("\nDigite qual termo deseja encontrar:");
	scanf("%lf", &n);
	an = a1 + (n-1)*r;
	printf("Resultado: %.2lf", an);
	
	
}
