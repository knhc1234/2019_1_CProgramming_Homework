#include <stdio.h>

int main(void) {
	int i;
	int j;
	
	for(i = 1; i <= 10; i++)
	{
		for(j = 1; j <= 10-i; j++)
			printf(" ");
		for(j = 1; j < 2*i; j++)
			printf("*");
		printf("\n");
	}
}
 
