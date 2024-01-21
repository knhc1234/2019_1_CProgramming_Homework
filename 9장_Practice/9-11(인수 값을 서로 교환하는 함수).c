#include <stdio.h>
void swap(int *x,int *y);

int main(void)

{
	int a,b;
	a=10; b=20;
	
	printf("before: a=%d, b=%d\n",a,b);
	swap(&a,&b);
	printf("after: a=%d, b=%d\n",a,b);
	
	return 0;
}

void swap(int *x, int *y) {
	int tmp;
	
	tmp = *x;
	*x = *y;
	*y= tmp;
}
