#include <stdio.h>

int main(void)
{
	float s[16];
	
	printf("�迭 s�� ��: %x\n",s);
	printf("s[0]�� �ּҰ�: %x\n",&s[0]);		//s�� &s[0]�� ����. 
	printf("�迭 s+1�� ��: %x\n",s+1);
	printf("s[1]�� �ּҰ�: %x\n",&s[1]);		//s+1�� &s[1]�� ����. 
	
	return 0;
}
