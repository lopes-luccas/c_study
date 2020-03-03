#include <stdio.h>

int main()
{
	char a;
	printf("Enter a character:");
	scanf("%c", &a);
	printf("\n %c = %d em decimal, ", a, a);
	printf("%o em octal, %x em hexadecimal", a, a);
	return 0;
}
