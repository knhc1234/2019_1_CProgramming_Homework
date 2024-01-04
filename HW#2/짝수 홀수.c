#include <stdio.h>

int main(void)
{
	int a;
	
	printf("정수를 입력하시오 : ");
	scanf("%d", &a);
	
	if(a%2 == 0)
		printf("짝수입니다\n");
	else
		printf("홀수입니다\n");
	return 0;
}

