#include <stdio.h>

int main(void) {
	char s[20];
	char t[]="university";
	
	//s="computer";  �迭�� ġȯ �Ұ�
	strcpy(s,"computer");		//���ڿ��� s�� ���� 
	strcpy(s,t); 				//�迭 t�� ����� ���ڿ��� s�� ���� 
	
	printf("%s",s);
}
