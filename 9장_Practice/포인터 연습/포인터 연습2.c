#include <stdio.h>
	
int main(void) {
	
	int a[10];
	int *pa;
	int i,sum=0;
	
	for(i=0;i<10;i++)
	a[i]=i+1;
	
	pa=a;
	
	for(i=0;i<10;i++)
	sum = sum + *(pa+i);
	
	printf("%d",sum);
	
	return 0;
} 
