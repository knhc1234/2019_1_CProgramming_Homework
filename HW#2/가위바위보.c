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
	
		if( a== 1 ){
			if(b== 1 )
				printf("���º��Դϴ�\n");
			if(b== 2 ){
				printf("��ǻ�Ͱ� �¸��߽��ϴ�\n");
				winB++; 
			}
			if(b== 3 ){
				printf("����� �¸��߽��ϴ�\n");
				winA++;
			}	
		}
		else if( a== 2){
			if(b== 1 ){
				printf("����� �¸��߽��ϴ�\n");
				winA++;
			}	
			if(b== 2 )
				printf("���º��Դϴ�\n");
			if(b== 3 ){
				printf("��ǻ�Ͱ� �¸��߽��ϴ�\n");
				winB++;
			}	
		}
		else if( a== 3){
			if(b== 1){
				printf("��ǻ�Ͱ� �¸��߽��ϴ�\n");
				winB++;
			}
			if(b== 2){
				printf("����� �¸��߽��ϴ�\n");
				winA++;
			}
			if(b== 3)
				printf("���º��Դϴ�\n");
		}
		else
			printf("�Է��� �߸��Ǿ����ϴ�\n"); 
			
		printf("���= %d  ��ǻ��= %d \n", a, b); 
		printf("[����] ���:%d��   ��ǻ��:%d��\n ", winA, winB);
		printf("-----------------------------------\n");
	}	
}


