#include <stdio.h>

int main(void) {
	
	char s[80],*p;
	int len=0;
	
	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s",s);
	
	p=s;
	while(*p) {   //NULL���ڰ� �ƴ� ���� �ݺ�
	p++;
	len++; 
	}
	printf("���ڿ�:%s ���ڿ��� ���� %d",s ,len);		//s��� p�� ���� ���ڿ��� ������ ����(����Ȱ� s�� p�� �����ϴ°� �ƴ�) 
	return 0;
}
