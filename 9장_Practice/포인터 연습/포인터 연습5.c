#include <stdio.h>

void main (void) {
	
	char a[100];
	char b[100];
	char c[200];
	char *strptr1;
	char *strptr2;
	
	int i;
	strptr1=a;
	strptr2=c;

	printf("문자열a를 입력하시오: ");
	scanf("%s",a);

	printf("문자열b를 입력하시오: ");
	scanf("%s",b);

	while(*strptr1) {
		*strptr2=*strptr1;
		strptr1++;
		strptr2++;
	}	
	
	strptr1=b;
	
	while(*strptr1) {
	*strptr2=*strptr1;
	strptr1++;
	strptr2++;
	}	
	
	*strptr2='\0';
	
	printf("a: %s",a);
	printf("b: %s",b);
	printf("c: %s",c);
	
	
}
