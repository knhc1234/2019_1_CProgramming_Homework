#include <stdio.h>

void add(int a, int b, int *p);

int main(void) {
	
	int sum;			//결과를 받을 변수 
	
	add(10,20,&sum);	//sum의 주소를 인수 전달 
	printf("sum=%d\n",sum);
	return 0;
	
}

void add(int a, int b, int *p) {
	*p = a+b; //포인터 p가 가리키는 곳에 a,b의 합을 저장 
}
