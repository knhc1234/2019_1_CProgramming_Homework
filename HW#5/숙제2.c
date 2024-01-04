#include <stdio.h>
#pragma warning(disable: 4996)
#include<string.h>
#include<stdlib.h>

int main(void) {
	
	char name[80];
	int age;
	float height;
	char result[200];
	char is[]="is";
	char sentence[]="years old and his/her height is";
	char a[5];
	char *pbuffer;
	int dec, sign;
	char buffer[100];
	
	printf("이름은: \n");
	scanf("%s",name);
	printf("나이는: \n");
	scanf("%d",&age);
	printf("키는: \n");
	scanf("%f",&height);
	
	strcpy(result, name);
	strcat(result, is);
	itoa(age, a, 10);
	strcat(result, a);
	strcat(result, sentence);
	pbuffer = gcvt( height, 6, buffer );
	strcat(result, pbuffer);
	
	printf("Result: %s\n",result);
	getch();
}


