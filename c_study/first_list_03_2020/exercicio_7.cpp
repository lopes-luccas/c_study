#include <stdio.h>
#include <locale.h>
int main()
{
	double metro;
	setlocale(LC_ALL, "Portuguese");
	scanf("%lf", &metro);
	printf("Valor em metro: %.2lfm.", metro);
	printf("\nValor em decimetro: %.2lfdm.", metro*10);
	printf("\nValor em centímetro: %.2lfcm.", metro*100);
	printf("\nValor em milímetro: %.2lfmm.", metro*1000);
	
	return 0;
}
