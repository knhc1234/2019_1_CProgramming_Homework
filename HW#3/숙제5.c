#include <stdio.h>

int main(void) {

	int i;    	  
	int sum;     
	
	sum = 0;  
	
	for (i = 1; i <= 100; i++) {
		if(i % 2 == 0)
			sum = sum + i;
	}
	printf("\n%d\n", sum);
}
