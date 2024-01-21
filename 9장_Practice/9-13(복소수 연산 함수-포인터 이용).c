#include <stdio.h>

struct complex{
	double re;
	double im;
};

//p가 가리키는 복소수 값 지정
void assign(struct complex *p, double real, double imag) {
	
	p->re=real;
	p->im=imag;
} 

//p, q가 가리키는 복소수를 더하여 result가 가리키는 복소수에 저장
void add(struct complex *result,struct complex *p,struct complex *q) {
	result->re = p->re + q->re;
	result->im = p->im + q->im;
}

//p가 가리키는 복소수를 출력
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
