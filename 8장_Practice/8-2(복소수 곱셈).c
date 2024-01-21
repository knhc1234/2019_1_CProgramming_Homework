#include <stdio.h>

struct complex {
	double real;
	double imag;
};

int main(void) {
	struct complex x = {1.0 , 2.0};
	struct complex y = {2.0 , -3.0};
	struct complex m;
	
	m.real=x.real*y.real - x.imag*y.imag;
	m.imag=x.real*y.imag + x.imag*y.real;
	
	printf("º¹¼Ò¼ö °ö¼À °á°ú = %f + %f i\n",m.real,m.imag);
	return 0;
}
