#include <stdio.h>

void cal(int a, int b, int *sum, int *diff) {
	
	*sum=a+b;
	*diff=a-b;
	
	if(*diff<0)
	*diff=-*diff;
	
	return;
};

int main(void) {
	int a,b;
	scanf("%d %d",&a,&b);
	
	cal(a,b,&a,&b);
	
	printf("Че:%d Тї:%d",a,b);
	
	return 0;
}
