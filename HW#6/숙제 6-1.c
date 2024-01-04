#include <stdio.h>

int main(void) {
	char ocean[9][9];
	int  i, j;
	char x1 = 0x00 , y1 = 0x00;										// x1, y1은 입력받은 값 (좌표 값) 
	int  x2, y2;													// x2, y2는 입력받은 값을 int로 변환한 값 
	int  sum=0;														// sum은 입력된 좌표의 개수 

	for(i=0;i<9;i++) {												// ocean에 '#'대입 
		for(j=0;j<9;j++){
			ocean[i][j]='#';
		}	
	}
	
	printf("  123456789\n");										// 좌표를 표현하기 위해 x축 표시
	for(i=0;i<9;i++) {
		printf("%c ", 'A'+i);										// 좌표를 표현하기 위해 y축 표시 
		for(j=0;j<9;j++) {
			printf("%c",ocean[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	while(y1!='G' || x1!='G') {										// GG를 치면 종료 (그전까지 계속 반복) 
		printf("좌표를 입력하시오: ");  							// 좌표 입력 
		scanf("%c%c",&y1,&x1);
		
		while(getchar()!='\n');										// skip '\n'

		if(y1 >= 'A'&& y1 <= 'I' && x1 >= '1' && x1 <= '9') {		// x좌표 1~9, y좌표 A~I까지 입력되었을 때 
			y2 = y1 - 'A';
			x2 = x1 - '1';
			
			if(ocean[y2][x2]=='X') {								// 입력된 좌표 중복 확인
				printf("이미 입력한 좌표입니다.\n");
			}
			else {													// 중복이 아닐시 해당 좌표를 X로 표시 
				ocean[y2][x2] = 'X';
				
				printf("  123456789\n");
				for(i=0;i<9;i++) {
					printf("%c ", 'A'+i);
					for(j=0;j<9;j++) {
						printf("%c",ocean[i][j]);
					}
					printf("\n");
				}	
				printf("\n");
			}
		}		
		
		else {														// 잘못된 좌표 입력 표시 
			printf("잘못된 좌표입니다.\n");
		}
	
	}
	
	for(i=0;i<9;i++) {												// 몇개의 좌표가 입력되었는지 계산 
		for(j=0;j<9;j++) {
			if(ocean[i][j]=='X') {
				sum = sum + 1;
			}
		}
	}
	
	printf("지금까지 %d개의 좌표가 입력되었습니다.", sum);
	
	return 0;
} 


