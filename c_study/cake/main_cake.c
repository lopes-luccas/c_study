#include <stdio.h>
#include <stdlib.h>
#define XICARACHA 200
// Acima está duas bibliotecas e uma constante
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
int -> inteiro
float -> real
char -> caractere
*/

int main(int argc, char *argv[]) {
	int qnt_porcao = 1;
	float xicara_cha_leite = 1;
	float xicara_oleo_soja = 1;
	int ovos = 4;
	float farinha_trigo = 2;
	float achocolatado = 1;
	float fermento = 1;
	float acucar = 1;
	
	
	while (qnt_porcao != 0){
	    printf("Enter the number of people:");
        scanf("%d", &qnt_porcao);
        xicara_cha_leite *= qnt_porcao * XICARACHA;
        xicara_oleo_soja *= qnt_porcao * XICARACHA;
        ovos *= qnt_porcao;
        farinha_trigo *= qnt_porcao;
        achocolatado *= qnt_porcao;
        fermento *= qnt_porcao;
        acucar *= qnt_porcao;

        //printf("%d", qnt_porcao);
        printf("Quantity for %d: \n", qnt_porcao);
        printf("Leite: %.2f ml| Óleo de soja: %.2f ml | Ovos: %d | Farinha de trigo: %.2f g| Achocolatado:  %.2f g | Fermento: %.2f g | Açucar: %.2f g| \n", 
		printf("Óleo de soja: %.2f ml")
		printf("Ovos: %d")
		xicara_cha_leite, xicara_oleo_soja, ovos, farinha_trigo, achocolatado, 
		fermento, acucar);
	    xicara_cha_leite = 1;
        xicara_oleo_soja = 1;
	}
	return 0;
}
