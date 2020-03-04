#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	double quant_real, cotacao_dolar;
	printf("Valor em real:");
	scanf("%lf", &quant_real);
	printf("Cotação do dolar:");
	scanf("%lf", &cotacao_dolar);
	printf("Quantidade dolar US$%.2lf.", quant_real * cotacao_dolar);	
	return 0;
}
