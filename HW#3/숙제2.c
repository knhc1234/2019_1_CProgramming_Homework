#include <stdio.h>

int main(void) {

	int a;
	int b;
	
	int winA = 0;
	int winB = 0;
	
	while(winA < 3 && winB < 3){
		printf("�Է��Ͻÿ�(����=1, ����=2, ��=3) : ");
		scanf("%d", &a); 
	
		b = rand() % 3 + 1;
	
		switch(a){
		
		case 1: 
			switch(b) {
				case 1: printf("���º��Դϴ�"); 
						break;
				case 2: printf("��ǻ�Ͱ� �¸��߽��ϴ�");
						winB++;
						break;
				case 3: printf("����� �¸��߽��ϴ�"); 
						winA++;
						break; 
			}
			break;
		case 2: 
			switch(b) {
				case 1: printf("����� �¸��߽��ϴ�"); 
						winA++;
						break;
				case 2: printf("���º��Դϴ�"); 
						break;
				case 3: printf("��ǻ�Ͱ� �¸��߽��ϴ�");
						winB++;
						break; 
			}
			break;
		case 3: 
			switch(b) {
				case 1: printf("��ǻ�Ͱ� �¸��߽��ϴ�"); 
						winB++;
						break;
				case 2: printf("����� �¸��߽��ϴ�"); 
						winA++;
						break;
				case 3: printf("���º��Դϴ�"); 
						break; 
			}
			break;
		default:
			printf("�Է��� �߸��Ǿ����ϴ�\n");
		}
		
		printf("���= %d  ��ǻ��= %d \n", a, b); 
		printf("[����] ���:%d��   ��ǻ��:%d��\n ", winA, winB);
		printf("-----------------------------------\n");	
	}
}
