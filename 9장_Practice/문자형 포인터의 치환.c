#include <stdio.h>

int main(void) {
	
	char *p;
	char t[]= "university";
	
	p="computer";				//���ڿ� ����� �����ּ� ���� 
	p=t;						//���� �迭�� �����ּ� ���� 
	
	printf("p=%s, t=%s",p,t);
	return 0;
}
