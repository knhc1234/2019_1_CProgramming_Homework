#include <stdio.h>
#include <string.h>

struct student{
	int id;
	char name[12];
	int score;
};

int main (void) {
	struct student s, *p;
	p=&s;
	(*p).id=20060081;
	//p->name="ȫ�浿";		�迭�� �Ұ��� 
	p->score=88;
	
	strcpy(p->name,"ȫ�浿");
	
	printf("id=%d, name=%s, score=%d\n",p->id,p->name,p->score);	
	printf("id=%d, name=%s, score=%d\n",s.id,s.name,s.score);
	printf("id=%d, name=%s, score=%d\n",(*p).id,(*p).name,(*p).score);			//����� ���� 
	
	return 0;
}
