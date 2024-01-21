#include <stdio.h>
#include <math.h>

struct point{
	float x;
	float y;
};

int main(void) {
	struct point a,b;
	float dx,dy,distance;
	
	a.x=10.0; a.y=5.0;
	scanf("%f %f",&b.x,&b.y);
	
	dx = a.x-b.x;
	dy = a.y-b.y;
	distance=sqrt(dx*dx+dy*dy);
	printf("distance = %f",distance);
	
	return 0;
}
