#include <stdio.h>
#include <math.h>

struct point {
	float x,y;
};

struct point midpoint(struct point a, struct point b) {
	struct point mid;
	
	mid.x=(a.x+b.x)/2.0;
	mid.y=(a.y+b.y)/2.0;
	return mid;
}

int main(void) {
	
	struct point p,q,m;
	
	scanf("%f %f",&p.x,&p.y);
	scanf("%f %f",&q.x,&q.y);
	m = midpoint(p,q);
	
	printf("ÁßÁ¡ = (%f,%f)\n", m.x,m.y);
	return 0;
}

