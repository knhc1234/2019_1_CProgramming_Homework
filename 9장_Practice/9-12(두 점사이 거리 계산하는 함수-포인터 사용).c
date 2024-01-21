#include <stdio.h>
#include <math.h>

struct point{
	float x;
	float y;
};

//�� �� ������ �Ÿ� ���: �� ���� ���� �����͸� �μ��� ���� 
float distance(struct point *p, struct point *q) {
	
	float dx, dy, distance;
	
	dx=p->x - q->x;
	dy=p->y - q->y;
	distance = sqrt(dx*dx + dy*dy);
	return distance;
}

//���� ��ǥ ���: ���� ���� �����͸� �μ��� ����
void print_point(struct point *p) {
	printf("(%g,%g)",p->x,p->y);
} 

int main(void) {
	struct point a = {1.0,4.0};
	struct point b = {5.0,1.0};
	
	printf("�� a�� ��ǥ: ");
	print_point(&a);
	printf("�� b�� ��ǥ: ");
	print_point(&b);
	printf("\n�� �� ������ �Ÿ�: %f\n", distance(&a,&b));
	
	return 0;
}
