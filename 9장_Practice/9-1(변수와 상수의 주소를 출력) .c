#include <stdio.h>

int p,q;
const int max = 100;

int main(void) {
	int a,b;
	
	printf("a客 b狼 林家: %p %p\n",&a,&b);    //a,b狼 林家 
	printf("p客 q狼 林家: %x %x\n",&p,&q);	//p,q狼 林家  
	printf("max 狼 林家: %x\n",&max);			//max狼 林家 
	printf("巩磊凯狼 林家: %p \n","univ");	//univ狼 林家 
	
	return 0;
}
