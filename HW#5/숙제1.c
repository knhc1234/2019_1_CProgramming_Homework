#include <stdio.h>
#pragma warning(disable: 4996)
#include<string.h>

int main(void) {

	int i, j;
	char name[5][80];
	char quit[10]={"quit"};
	char search[80];
	
	for (i = 0; i < 5; i++) {
		scanf("%s", name[i]);
		}
		
	while(strcmp(quit,search)!=0) //���ο� search���� ������ quit�� �̿��Ͽ� ������ ��� ���� ������ EnterŰ�� �����ּ���
	{	
		scanf("%s", search);

	for (j = 0; j < 5; j++) {
		if (strcmp(name[j], search)==0)
			printf("%d��° �̸��Դϴ�", j + 1); 
		}
		if (strcmp(name[0],search)&&strcmp(name[1],search)&&strcmp(name[2],search)&&strcmp(name[3],search)&&strcmp(name[4],search))
			printf("�����ϴ�.");
	getch();
}
}
