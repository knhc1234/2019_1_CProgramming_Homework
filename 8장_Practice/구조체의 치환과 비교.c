#include <stdio.h>

struct point {
	float x;
	float y;
};

int main(void) {
	
	struct point p1 ={4.0, 10.0};
	struct point p2;
	
	p2 = p1;								//����ü ġȯ 
	
	printf("p2:x=%f, y=%f\n",p2.x,p2.y);
	
	if(p1.x==p2.x&&p1.y==p2.y)				//����ü ��:��� ���� 
	printf("���� p1�� p2�� ����.\n");
	
	return 0;
}
