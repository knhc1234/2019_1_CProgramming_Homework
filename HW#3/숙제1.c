#include <stdio.h>

int main(void) {

	int a;
	int b;

	for(a = 2; a <= 9; a++) {
		for(b = 1; b <= 9 ; b++) {
			printf("%d * %d = %d \n", a, b, a*b);
		}
		printf("-----------\n");
	}
}
