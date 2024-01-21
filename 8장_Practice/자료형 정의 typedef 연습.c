#include <stdio.h>

typedef char BYTE;
typedef short WORD;
typedef long DWORD;
typedef double Vector[3]; //배열
typedef struct {double x,y;} Point;	//구조체

int main(void) {
	BYTE a = 10;
	WORD b = -1000;
	DWORD c = 100000;
	Vector v = {1.0,2.0,3.0};
	Point p = {-15.0,12.0};
	
	printf("a = %d, b = %d, c = %d\n",a,b,c);
	printf("v = (%g, %g, %g)\n",v[0],v[1],v[2]);
	printf("p = (%g, %g)\n", p.x, p.y);
	return 0;
} 

