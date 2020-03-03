#include <iostream>

int main(int argc, char** argv) {
	float media,nota_bimestre1, nota_bimestre2, nota_bimestre3, nota_bimestre4;
     scanf("%f", &nota_bimestre1);
     scanf("%f", &nota_bimestre2);
     scanf("%f", &nota_bimestre3);
	 scanf("%f", &nota_bimestre4);
	 media = (nota_bimestre1+nota_bimestre2+nota_bimestre3+nota_bimestre4)/4;
	 printf("Média das notas: %.2f", media);
	return 0;
}
