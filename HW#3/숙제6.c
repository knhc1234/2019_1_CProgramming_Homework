#include <stdio.h>

int main(void) {
	int i;
	int total; 
	
	total = 0;
	
	for (i =1; i <= 100; i++) 
		total = total + isprime(i);
	
	printf("%d", total);
}


isprime(int n){
	int i;
		
	for (i = 2; i < n; i++) 
		if ((n % i) == 0) 
			return 0;
	
	if(n <= 1)	
		return 0;
	else		
		return n;
}
	

	
