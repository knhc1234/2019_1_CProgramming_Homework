#include <stdio.h>
#include <math.h>

struct point{
	float x;
	float y;
};

//두 점 사이의 거리 계산: 두 점에 대한 포인터를 인수로 받음 
float distance(struct point *p, struct point *q) {
	
	float dx, dy, distance;
	
	dx=p->x - q->x;
	dy=p->y - q->y;
	distance = sqrt(dx*dx + dy*dy);
	return distance;
}

//점의 좌표 출력: 점에 대한 포인터를 인수로 받음
void print_point(struct point *p) {
	printf("(%g,%g)",p->x,p->y);
} 

int main(void) {
	struct point a = {1.0,4.0};
	struct point b = {5.0,1.0};
	
	printf("점 a의 좌표: ");
	print_point(&a);
	printf("점 b의 좌표: ");
	print_point(&b);
	printf("\n두 점 사이의 거리: %f\n", distance(&a,&b));
	
	return 0;
}
