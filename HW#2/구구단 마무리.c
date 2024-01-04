#include <stdio.h>

int main(void) {

	int a;
	int b;

	a = 2;

	while (a <= 9) {
		b = 1;
		while (b <= 9) {
			printf("%d * %d = %d \n", a, b, a*b);
			b++;
		}
		printf("-----------\n");
		a++;
	}
}



