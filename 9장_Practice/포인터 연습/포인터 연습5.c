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

	printf("���ڿ�a�� �Է��Ͻÿ�: ");
	scanf("%s",a);

	printf("���ڿ�b�� �Է��Ͻÿ�: ");
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
