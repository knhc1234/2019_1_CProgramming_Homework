#include <stdio.h>

int main(void) {
	
	char *p;
	char t[]= "university";
	
	p="computer";				//문자열 상수의 시작주소 저장 
	p=t;						//문자 배열의 시작주소 저장 
	
	printf("p=%s, t=%s",p,t);
	return 0;
}
