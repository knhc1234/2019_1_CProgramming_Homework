#include <stdio.h>

enum itemcode {Keyboard=100, Mouse, Scanner, Laser=200, Inkjet, Plotter};

int main(void) {
	enum itemcode item;
	
	printf("ǰ�� �ڵ带 �Է��ϼ���. ");
	scanf("%d",&item); //�ڵ� �Է� 
	printf("ǰ�� �ڵ� %d�� ",item);

	switch (item) {
		case Keyboard: printf("Keyboard�Դϴ�.\n"); break;
		case Mouse: printf("Mouse�Դϴ�.\n"); break;
		case Scanner: printf("Scanner�Դϴ�.\n"); break;
		case Laser: printf("Laser�Դϴ�.\n"); break;
		case Inkjet: printf("Inkjet�Դϴ�.\n"); break;
		case Plotter: printf("Plotter�Դϴ�.\n"); break;
		default: printf("�����ϴ�.\n");
	}
	return 0;
}
