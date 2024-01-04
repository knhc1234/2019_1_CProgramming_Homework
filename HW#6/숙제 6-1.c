#include <stdio.h>

int main(void) {
	char ocean[9][9];
	int  i, j;
	char x1 = 0x00 , y1 = 0x00;										// x1, y1�� �Է¹��� �� (��ǥ ��) 
	int  x2, y2;													// x2, y2�� �Է¹��� ���� int�� ��ȯ�� �� 
	int  sum=0;														// sum�� �Էµ� ��ǥ�� ���� 

	for(i=0;i<9;i++) {												// ocean�� '#'���� 
		for(j=0;j<9;j++){
			ocean[i][j]='#';
		}	
	}
	
	printf("  123456789\n");										// ��ǥ�� ǥ���ϱ� ���� x�� ǥ��
	for(i=0;i<9;i++) {
		printf("%c ", 'A'+i);										// ��ǥ�� ǥ���ϱ� ���� y�� ǥ�� 
		for(j=0;j<9;j++) {
			printf("%c",ocean[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	while(y1!='G' || x1!='G') {										// GG�� ġ�� ���� (�������� ��� �ݺ�) 
		printf("��ǥ�� �Է��Ͻÿ�: ");  							// ��ǥ �Է� 
		scanf("%c%c",&y1,&x1);
		
		while(getchar()!='\n');										// skip '\n'

		if(y1 >= 'A'&& y1 <= 'I' && x1 >= '1' && x1 <= '9') {		// x��ǥ 1~9, y��ǥ A~I���� �ԷµǾ��� �� 
			y2 = y1 - 'A';
			x2 = x1 - '1';
			
			if(ocean[y2][x2]=='X') {								// �Էµ� ��ǥ �ߺ� Ȯ��
				printf("�̹� �Է��� ��ǥ�Դϴ�.\n");
			}
			else {													// �ߺ��� �ƴҽ� �ش� ��ǥ�� X�� ǥ�� 
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
		
		else {														// �߸��� ��ǥ �Է� ǥ�� 
			printf("�߸��� ��ǥ�Դϴ�.\n");
		}
	
	}
	
	for(i=0;i<9;i++) {												// ��� ��ǥ�� �ԷµǾ����� ��� 
		for(j=0;j<9;j++) {
			if(ocean[i][j]=='X') {
				sum = sum + 1;
			}
		}
	}
	
	printf("���ݱ��� %d���� ��ǥ�� �ԷµǾ����ϴ�.", sum);
	
	return 0;
} 


