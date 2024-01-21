#include <stdio.h>

struct complex{
	double re;
	double im;
};

//p�� ����Ű�� ���Ҽ� �� ����
void assign(struct complex *p, double real, double imag) {
	
	p->re=real;
	p->im=imag;
} 

//p, q�� ����Ű�� ���Ҽ��� ���Ͽ� result�� ����Ű�� ���Ҽ��� ����
void add(struct complex *result,struct complex *p,struct complex *q) {
	result->re = p->re + q->re;
	result->im = p->im + q->im;
}

//p�� ����Ű�� ���Ҽ��� ���
void prt(struct complex *p) {
	printf("%g + %g i\n", p->re, p->im);
} 

int main(void) {
	struct complex c1, c2, c3;
	
	assign(&c1, 1.0, 2.0);		//c1: 1 + 2i
	assign(&c2, 3.0, 4.0);		//c2: 3 + 4i
	add(&c3,&c1,&c2);			//c3 = c1 + c2
	prt(&c3);
	
	return 0;
} 
