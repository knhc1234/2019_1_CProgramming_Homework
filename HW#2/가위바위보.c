#include <stdio.h>

int main(void) {

	int a;
	int b;
	
	int winA = 0;
	int winB = 0;
	
	while(winA < 3 && winB < 3){
		printf("입력하시오(가위=1, 바위=2, 보=3) : ");
		scanf("%d", &a); 
	
		b = rand() % 3 + 1;
	
		if( a== 1 ){
			if(b== 1 )
				printf("무승부입니다\n");
			if(b== 2 ){
				printf("컴퓨터가 승리했습니다\n");
				winB++; 
			}
			if(b== 3 ){
				printf("사람이 승리했습니다\n");
				winA++;
			}	
		}
		else if( a== 2){
			if(b== 1 ){
				printf("사람이 승리했습니다\n");
				winA++;
			}	
			if(b== 2 )
				printf("무승부입니다\n");
			if(b== 3 ){
				printf("컴퓨터가 승리했습니다\n");
				winB++;
			}	
		}
		else if( a== 3){
			if(b== 1){
				printf("컴퓨터가 승리했습니다\n");
				winB++;
			}
			if(b== 2){
				printf("사람이 승리했습니다\n");
				winA++;
			}
			if(b== 3)
				printf("무승부입니다\n");
		}
		else
			printf("입력이 잘못되었습니다\n"); 
			
		printf("사람= %d  컴퓨터= %d \n", a, b); 
		printf("[누적] 사람:%d승   컴퓨터:%d승\n ", winA, winB);
		printf("-----------------------------------\n");
	}	
}


