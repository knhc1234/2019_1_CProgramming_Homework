#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4

void main() {
	int i, j;

	char ocean[SIZE][SIZE];
	char ocean2[SIZE][SIZE];
	char input[10];
		
	int row = 0, col = 0;

	int sLimit[nSTAGE] = { 5,4,3,2 };
	char sIcon[nSTAGE] = { 'C', 'B', 'F', 'S' };
	char sName[nSTAGE][20] = { "�װ�����(C)", "����(B)", "������(F)", "�����(S)" };
	char sDirection[nSTAGE] = { 'N', 'E', 'W', 'S' };
	int	sIndex = 0;

	/* �ڷᱸ�� �ʱ�ȭ */
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean[i][j] = '#';
		}
	}
	
	while (1) {
		system("cls");

		/* ���� ocean ���� ��� */
		printf(" 123456789\n");
		for (i = 0; i < SIZE; i++) {
			printf("%c", 'A' + i);
			for (j = 0; j < SIZE; j++) {
				printf("%c", ocean[i][j]);
			}
			printf("\n");
		}

		/* STAGE�� ��� ����Ǿ����� üũ */
		if (sIndex >= nSTAGE) {
			printf("\n");
			break;
		}

		/* ��ǥ �Է� ��û */
		printf("%s�� ��ġ�Ͻÿ�(������ ����) : ", sName[sIndex]);
		gets(input);

		/* �Էµ� ��ǥ ���� üũ */
		/* �Էµ� ��ǥ 4�ڸ� ���� üũ*/
		if (strlen(input) != 4) {
			printf("����");
			getch();
			continue;
		}

		/* �Էµ� ��ǥ ���� üũ */
		if (!('A' <= input[0] && input[0] <= 'I' && '1' <= input[1] && input[1] <= '9')) {
			printf("����");
			getch();
			continue;
		}

		/* �Էµ� ��ǥ ���� üũ */
		if (input[2] != ' ') {
			printf("����");
			getch();
			continue;
		}

		/* �Էµ� ��ǥ ���� ���� üũ*/
		if (input[3] != 'N' && input[3] != 'E' && input[3] != 'W' && input[3] != 'S') {
			printf("����");
			getch();
			continue;
		}
		
		/* ��ǥ�ؼ� */
		row = input[0] - 'A';
		col = input[1] - '1';

		/* ��ġ���� Ȯ�� �� �Լ� ��ġ*/
		/* ���� ��ġ �Է½� */
		if(input[3] == 'N') {
			if (row - sLimit[sIndex] + 1 < 0 ) {
				printf("����");
				getch();
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++) 
				if (ocean[row - i][col] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean[row - i][col] = sIcon[sIndex];
			}
			else {
				printf("����");
				getch();
				continue;
			}

		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'E') {
			if (col + sLimit[sIndex] > SIZE ) {
				printf("����");
				getch();
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean[row][col+i] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean[row][col+i] = sIcon[sIndex];
			}
			else {
				printf("����");
				getch();
				continue;
			}
		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'W') {
			if (col - sLimit[sIndex] + 1 < 0) {
				printf("����");
				getch();
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean[row][col - i] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean[row][col - i] = sIcon[sIndex];
			}
			else {
				printf("����");
				getch();
				continue;
			}
		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'S') {
			if (row + sLimit[sIndex] > SIZE ) {
				printf("����");
				getch();
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean[row + i][col] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean[row + i][col] = sIcon[sIndex];
			}
			else {
				printf("����");
				getch();
				continue;
			}
		}

		/* ���� �Է� STAGE�� �̵� */
		sIndex++;
	}
	
	/* �ڷᱸ�� �ʱ�ȭ */
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean2[i][j] = '#';
		}
	}
	/* rand() �Լ��� �ٸ� seed�� �ֱ� ���ؼ� */
	srand(time(NULL));
	/* sIndex �ʱ�ȭ */ 
	sIndex = 0;

	while (1) {
		/* STAGE�� ��� ����Ǿ����� üũ */
		if (sIndex >= nSTAGE) {
			/* ���� ocean ���� ��� */
			printf(" 123456789\n");
			for (i = 0; i < SIZE; i++) {
				printf("%c", 'A' + i);
				for (j = 0; j < SIZE; j++) {
					printf("%c", ocean2[i][j]);
				}
				printf("\n");
			}
			break;
		}

		/* ��ǥ ���� �Է� */
		sprintf(input, "%c%c %c", 'A' + rand() % 9, '1' + rand() % 9, sDirection[rand() % 4]);
	
		/* �Էµ� ��ǥ ���� üũ */
		/* �Էµ� ��ǥ 4�ڸ� ���� üũ*/
		if (strlen(input) != 4) {
			continue;
		}

		/* �Էµ� ��ǥ ���� üũ */
		if (!('A' <= input[0] && input[0] <= 'I' && '1' <= input[1] && input[1] <= '9')) {
			continue;
		}

		/* �Էµ� ��ǥ ���� üũ */
		if (input[2] != ' ') {
			continue;
		}

		/* �Էµ� ��ǥ ���� ���� üũ*/
		if (input[3] != 'N' && input[3] != 'E' && input[3] != 'W' && input[3] != 'S') {
			continue;
		}
		
		/* ��ǥ�ؼ� */
		row = input[0] - 'A';
		col = input[1] - '1';

		/* ��ġ���� Ȯ�� �� �Լ� ��ġ*/
		/* ���� ��ġ �Է½� */
		if(input[3] == 'N') {
			if (row - sLimit[sIndex] + 1 < 0 ) {
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++) 
				if (ocean2[row - i][col] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean2[row - i][col] = sIcon[sIndex];
			}
			else {
				continue;
			}

		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'E') {
			if (col + sLimit[sIndex] > SIZE ) {
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean2[row][col+i] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean2[row][col+i] = sIcon[sIndex];
			}
			else {
				continue;
			}
		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'W') {
			if (col - sLimit[sIndex] + 1 < 0) {
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean2[row][col - i] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean2[row][col - i] = sIcon[sIndex];
			}
			else {
				continue;
			}
		}
		/* ���� ��ġ �Է½� */
		else if (input[3] == 'S') {
			if (row + sLimit[sIndex] > SIZE ) {
				continue;
			}
			for (i = 0; i < sLimit[sIndex]; i++)
				if (ocean2[row + i][col] != '#') break;
			if (i == sLimit[sIndex]) {
				for (i = 0; i < sLimit[sIndex]; i++)
					ocean2[row + i][col] = sIcon[sIndex];
			}
			else {
				continue;
			}
		}

		/* ���� �Է� STAGE�� �̵� */
		sIndex++;
	}

	/* ������ �Է� ��� */
	getch();

	return;
}



