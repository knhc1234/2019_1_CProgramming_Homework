#include <stdio.h>
#pragma warning(disable: 4996)
#include<string.h>

int main(void) {
	
	char name[80];
	int age;
	float height;
	char result[200];
	char is[]="is";
	char sentence[]="years old and his/her height is";
	char a[5];
	char h[100];
	
	printf("�̸���: \n");
	scanf("%s",name);
	printf("���̴�: \n");
	scanf("%d",&age);
	printf("Ű��: \n");
	scanf("%f",&height);
	
	
	 
	strcpy(result, name);
	strcat(result, is);
	sprintf(a, "%d", age);
	strcat(result, a);
	strcat(result, sentence);
	sprintf(h, "%f", height);
	strcat(result, h);
	
	printf("Result: %s\n",result);
	getch();
}
