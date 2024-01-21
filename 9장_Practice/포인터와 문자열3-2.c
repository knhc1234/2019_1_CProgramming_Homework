#include <stdio.h>

int main(void) {
	
	char *p;
	p = malloc(20);				//p는 새로 할당 받은 20B 메모리 주소 저장 
	strcpy(p,"computer");
	
	printf("p=%s",p); 
}
