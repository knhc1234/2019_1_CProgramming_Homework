#include <stdio.h>

int main(void) {
	
	char s[80],*p;
	int len=0;
	
	printf("문자열을 입력하시오: ");
	scanf("%s",s);
	
	p=s;
	while(*p) {   //NULL문자가 아닌 동안 반복
	p++;
	len++; 
	}
	printf("문자열:%s 문자열의 길이 %d",s ,len);		//s대신 p를 쓰면 문자열이 나오지 않음(저장된건 s고 p는 저장하는게 아님) 
	return 0;
}
