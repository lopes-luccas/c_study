#include <stdio.h>

int main()
{
	int age;
	char name[30]; 
	printf("Nome:\n");
	scanf("%s", &name);
	printf("Idade: \n");
	scanf("%d", &age);
	printf("%s tem %d anos.", name, age);
}
