#include <stdio.h>

int main()
{
	double soma, custo, porc_distribuidor=0.28, porc_impostos=0.45;
	scanf("%lf", &custo);
	soma = custo + porc_distribuidor * porc_impostos * custo;
	printf("Soma: %.3lf", soma);
	return 0;
}
