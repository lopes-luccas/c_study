#include <stdio.h>
int main() 
{
	double peso;
	char address[30], sexo[10];
	int idade, cep;
	// CEP(INT) tem valor de inteiro; ex: 06940010 
	
	printf("Peso em quilogramas:");
	scanf("%lf", &peso);
	printf("\nIdade:");
	scanf("%d", &idade);
	printf("\nSexo:");
	scanf("%s", &sexo);
	printf("\nEndereco:");
	scanf("%s", &address);
	printf("\nCEP:");
	scanf("%d", &cep);
	
	printf("Peso: %.2lf Kg.", peso);
	printf("\nSexo: %s", sexo);
	printf("\nIdade: %d anos.", idade);
	printf("\nEndereco: %s", address);
	printf("\nCEP: %d", cep);
	
	return 0;
}
