#include <stdio.h>

struct student{
	int id;
	char name[10];
	int dept;
};

int main(void) {
	int i;
	struct student s[10];		//s�� ����ü�� �迭
	
	for(i=0;i<10;i++)
	scanf("%d %s %d",&s[i].id,s[i].name,&s[i].dept);
	for(i=9;i>=0;i--)
	printf("%d %s %d\n",s[i].id,s[i].name,s[i].dept);
	
	return 0;
}
