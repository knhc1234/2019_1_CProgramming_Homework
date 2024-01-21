#include <stdio.h>

int main(void)
{
	float s[16];
	
	printf("배열 s의 값: %x\n",s);
	printf("s[0]의 주소값: %x\n",&s[0]);		//s와 &s[0]은 같다. 
	printf("배열 s+1의 값: %x\n",s+1);
	printf("s[1]의 주소값: %x\n",&s[1]);		//s+1과 &s[1]은 같다. 
	
	return 0;
}
