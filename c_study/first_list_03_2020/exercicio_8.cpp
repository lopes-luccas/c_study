#include <stdio.h>

int main()
{
	int value;
	scanf("%d", &value);
	printf("Valor: %d", value);
	for(int i=1; i<=10;i++){
		printf("\n%d * %d = %d",value, i, value * i);
	}
	return 0;
}
