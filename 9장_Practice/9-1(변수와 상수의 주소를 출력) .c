#include <stdio.h>

int p,q;
const int max = 100;

int main(void) {
	int a,b;
	
	printf("a�� b�� �ּ�: %p %p\n",&a,&b);    //a,b�� �ּ� 
	printf("p�� q�� �ּ�: %x %x\n",&p,&q);	//p,q�� �ּ�  
	printf("max �� �ּ�: %x\n",&max);			//max�� �ּ� 
	printf("���ڿ��� �ּ�: %p \n","univ");	//univ�� �ּ� 
	
	return 0;
}
