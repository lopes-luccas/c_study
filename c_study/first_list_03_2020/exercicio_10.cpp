#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	double number_one, number_two, produto, square;
	scanf("%lf", &number_one);
	scanf("%lf", &number_two);
	printf("Soma: %.2lf", number_one + number_two);
	produto = number_one * number_two * number_two;
	printf("\nProduto do primeiro número pelo quadrado do segundo: %.2lf", produto);
	square = pow(number_one,2);
	printf("\nQuadrado do primeiro: %.2lf", square);
	return 0;
}
