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
	
	printf("ù ��° ���� x��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p1.x);
	printf("ù ��° ���� y��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p1.y);
	printf("ù ��° ���� z��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p1.z);
	
	printf("�� ��° ���� x��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p2.x);
	printf("�� ��° ���� y��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p2.y);
	printf("�� ��° ���� z��ǥ�� �Է��Ͻÿ�: ");
	scanf("%f", &p2.z);
		
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	dz = p1.z - p2.z;
	distance = sqrt(dx*dx + dy*dy + dz*dz);
	
	printf("�Ÿ��� %f�Դϴ�.\n", distance);
	
	return 0;
}
