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
	//p->name="홍길동";		배열은 불가능 
	p->score=88;
	
	strcpy(p->name,"홍길동");
	
	printf("id=%d, name=%s, score=%d\n",p->id,p->name,p->score);	
	printf("id=%d, name=%s, score=%d\n",s.id,s.name,s.score);
	printf("id=%d, name=%s, score=%d\n",(*p).id,(*p).name,(*p).score);			//출력이 같다 
	
	return 0;
}
