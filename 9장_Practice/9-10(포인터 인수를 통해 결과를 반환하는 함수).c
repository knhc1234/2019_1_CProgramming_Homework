#include <stdio.h>

void add(int a, int b, int *p);

int main(void) {
	
	int sum;			//����� ���� ���� 
	
	add(10,20,&sum);	//sum�� �ּҸ� �μ� ���� 
	printf("sum=%d\n",sum);
	return 0;
	
}

void add(int a, int b, int *p) {
	*p = a+b; //������ p�� ����Ű�� ���� a,b�� ���� ���� 
}
