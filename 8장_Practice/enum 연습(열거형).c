#include <stdio.h>

enum itemcode {Keyboard=100, Mouse, Scanner, Laser=200, Inkjet, Plotter};

int main(void) {
	enum itemcode item;
	
	printf("품목 코드를 입력하세요. ");
	scanf("%d",&item); //코드 입력 
	printf("품목 코드 %d는 ",item);

	switch (item) {
		case Keyboard: printf("Keyboard입니다.\n"); break;
		case Mouse: printf("Mouse입니다.\n"); break;
		case Scanner: printf("Scanner입니다.\n"); break;
		case Laser: printf("Laser입니다.\n"); break;
		case Inkjet: printf("Inkjet입니다.\n"); break;
		case Plotter: printf("Plotter입니다.\n"); break;
		default: printf("없습니다.\n");
	}
	return 0;
}
