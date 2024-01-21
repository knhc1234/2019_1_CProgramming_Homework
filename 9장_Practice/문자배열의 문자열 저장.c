#include <stdio.h>

int main(void) {
	char s[20];
	char t[]="university";
	
	//s="computer";  배열은 치환 불가
	strcpy(s,"computer");		//문자열을 s로 복사 
	strcpy(s,t); 				//배열 t에 저장된 문자열을 s로 복사 
	
	printf("%s",s);
}
