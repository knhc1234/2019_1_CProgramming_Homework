#include <stdio.h>

int main (void) {
	int a[10];
	int b[10];
	int c[10];
	int i;
	int sum;
	sum=0;
	
	for(i=0;i<10;i++) 
	{ 	
		a[i]=2*i+2;
		printf ("a[%d]=%d\n",i,a[i]);}
	printf("-------------\n");
	for(i=0;i<10;i++)
	{	
		b[i]=2*i+1;
		printf ("b[%d]=%d\n",i,b[i]);}
	
	for(i=0;i<10;i++)
	{   
		c[i]=a[i]*b[i];
		printf ("c[%d]=%d\n",i,c[i]);
	}
	printf("-------------\n");
	i=0;
	while(i<10){
		sum=sum+c[i];
		i++;
	}
	printf("SUM=%d\n",sum);
}
