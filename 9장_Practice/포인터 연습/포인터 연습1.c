#include <stdio.h>

int main(void) {
	int a,b;
	int *pa,*pb;
	
	pa=&a;
	pb=&b;
	
	scanf("%d %d",&a,&b);
	
	printf("합:%d 차:%d 곱:%d 나머지:%d",*pa+*pb,*pa-*pb,*pa * *pb,*pa%*pb);
	return 0;
}
