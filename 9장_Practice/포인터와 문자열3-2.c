#include <stdio.h>

int main(void) {
	
	char *p;
	p = malloc(20);				//p�� ���� �Ҵ� ���� 20B �޸� �ּ� ���� 
	strcpy(p,"computer");
	
	printf("p=%s",p); 
}
