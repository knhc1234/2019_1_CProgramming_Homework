#include <stdio.h>

int main(void) {
	int a,b;
	int *pa,*pb;
	
	pa=&a;
	pb=&b;
	
	scanf("%d %d",&a,&b);
	
	printf("��:%d ��:%d ��:%d ������:%d",*pa+*pb,*pa-*pb,*pa * *pb,*pa%*pb);
	return 0;
}
