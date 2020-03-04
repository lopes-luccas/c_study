#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	double an, a1, a3, q, n, q_elevate, x, y, produto;
	printf("Digite a1:");
	scanf("%lf", &a1);
	printf("\nDigite a posição do termo:");
	scanf("%lf", &n);
	printf("\nDigite a razão:");
	scanf("%lf", &q);
	q_elevate = pow(q,n-1);
	an = a1*q_elevate;
	printf("a%.0lf é igual a: %.2lf", n, an);
	a1 = 1; 
	a3 = 16;
	/*16 = 1 * q^(n-1)
	q^(n-1) = a1/a3;
	q = sqrt(a1/a3, n-1);*/
	n = 3;
	q = pow(a3/a1, 1/(n-1));
	n = 2;
	q_elevate = pow(q,n-1);
	x = a1 * q_elevate;
	n = 4;
	q_elevate = pow(q,q-1);
	y = a1 * q_elevate;
	produto = x*y;
	printf("\nProduto igual a: %.2lf", produto);
	return 0;
}
