#include <stdio.h>

int main(void) {
	
	long *p;
	char *q;
	double *r;
	
	p=(long*)100;		//long포인터로 형 변환 
	q=(char*)200;		//char포인터로 형 변환 
	r=(double*)300;		//double포인터로 형 변환 
	p++;				//p는 주소가 4증가 
	q--;				//q는 주소가 1증가 
	r= r+5;				//r은 주소가 40증가 
	
	printf("p=%d q=%d r=%d",p,q,r);		//변화된 주소 출력 
	
	return 0;
}
