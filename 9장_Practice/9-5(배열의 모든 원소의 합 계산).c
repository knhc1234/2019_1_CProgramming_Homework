#include <stdio.h>

int main(void) {
	int a[20],*p,sum;
	int i; 
	
	for(i=0;i<20;i++)
	a[i]=i;
	
	sum = 0;
	
	for(p=a;p<&a[20];p++)
	sum = sum + *p;
	
	printf("sum=%d",sum);
}
