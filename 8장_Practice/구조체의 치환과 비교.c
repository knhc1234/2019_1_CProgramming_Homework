#include <stdio.h>

struct point {
	float x;
	float y;
};

int main(void) {
	
	struct point p1 ={4.0, 10.0};
	struct point p2;
	
	p2 = p1;								//구조체 치환 
	
	printf("p2:x=%f, y=%f\n",p2.x,p2.y);
	
	if(p1.x==p2.x&&p1.y==p2.y)				//구조체 비교:멤버 별로 
	printf("두점 p1과 p2는 같다.\n");
	
	return 0;
}
