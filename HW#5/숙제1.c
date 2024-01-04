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
		
	while(strcmp(quit,search)!=0) //새로운 search값을 쓸때와 quit을 이용하여 나갈시 결과 값이 나온후 Enter키를 눌러주세요
	{	
		scanf("%s", search);

	for (j = 0; j < 5; j++) {
		if (strcmp(name[j], search)==0)
			printf("%d번째 이름입니다", j + 1); 
		}
		if (strcmp(name[0],search)&&strcmp(name[1],search)&&strcmp(name[2],search)&&strcmp(name[3],search)&&strcmp(name[4],search))
			printf("없습니다.");
	getch();
}
}
