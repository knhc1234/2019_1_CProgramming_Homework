#include <stdio.h>

int main (void) {
	
	int a , b, *p;
	
	a=10;
	p=&a;		//�ʱ�ȭ 
	
	b=*p;		//b=a		
	*p=20;		//a=20
	
	printf("a=%d, b=%d",a,b);
	
	return 0;
}
