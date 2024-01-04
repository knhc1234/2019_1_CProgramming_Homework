#include <stdio.h>
#include <math.h>

struct point {
	float x;
	float y;
	float z;
};

int main(void) {
	struct point p1, p2;
	float dx, dy, dz, distance;
	
	printf("첫 번째 점의 x좌표를 입력하시오: ");
	scanf("%f", &p1.x);
	printf("첫 번째 점의 y좌표를 입력하시오: ");
	scanf("%f", &p1.y);
	printf("첫 번째 점의 z좌표를 입력하시오: ");
	scanf("%f", &p1.z);
	
	printf("두 번째 점의 x좌표를 입력하시오: ");
	scanf("%f", &p2.x);
	printf("두 번째 점의 y좌표를 입력하시오: ");
	scanf("%f", &p2.y);
	printf("두 번째 점의 z좌표를 입력하시오: ");
	scanf("%f", &p2.z);
		
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	dz = p1.z - p2.z;
	distance = sqrt(dx*dx + dy*dy + dz*dz);
	
	printf("거리는 %f입니다.\n", distance);
	
	return 0;
}
