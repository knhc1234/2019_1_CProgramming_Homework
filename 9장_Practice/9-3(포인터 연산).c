#include <stdio.h>

int main(void) {
	
	long *p;
	char *q;
	double *r;
	
	p=(long*)100;		//long�����ͷ� �� ��ȯ 
	q=(char*)200;		//char�����ͷ� �� ��ȯ 
	r=(double*)300;		//double�����ͷ� �� ��ȯ 
	p++;				//p�� �ּҰ� 4���� 
	q--;				//q�� �ּҰ� 1���� 
	r= r+5;				//r�� �ּҰ� 40���� 
	
	printf("p=%d q=%d r=%d",p,q,r);		//��ȭ�� �ּ� ��� 
	
	return 0;
}
