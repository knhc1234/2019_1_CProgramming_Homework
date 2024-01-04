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
	char sName[nSTAGE][20] = { "항공모함(C)", "전함(B)", "구축함(F)", "잠수함(S)" };
	char sDirection[nSTAGE] = { 'N', 'E', 'W', 'S' };
	int	sIndex = 0;

	/* 자료구조 초기화 */
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean[i][j] = '#';
		}
	}
	
	while (1) {
		system("cls");

		/* 현재 ocean 상태 출력 */
		printf(" 123456789\n");
		for (i = 0; i < SIZE; i++) {
			printf("%c", 'A' + i);
			for (j = 0; j < SIZE; j++) {
				printf("%c", ocean[i][j]);
			}
			printf("\n");
		}

		/* STAGE가 모두 수행되었는지 체크 */
		if (sIndex >= nSTAGE) {
			printf("\n");
			break;
		}

		/* 좌표 입력 요청 */
		printf("%s를 배치하시오(시작점 방향) : ", sName[sIndex]);
		gets(input);

		/* 입력된 좌표 오류 체크 */
		/* 입력된 좌표 4자리 여부 체크*/
		if (strlen(input) != 4) {
			printf("오류");
			getch();
			continue;
		}

		/* 입력된 좌표 범위 체크 */
		if (!('A' <= input[0] && input[0] <= 'I' && '1' <= input[1] && input[1] <= '9')) {
			printf("오류");
			getch();
			continue;
		}

		/* 입력된 자표 형식 체크 */
		if (input[2] != ' ') {
			printf("오류");
			getch();
			continue;
		}

		/* 입력된 좌표 방향 형식 체크*/
		if (input[3] != 'N' && input[3] != 'E' && input[3] != 'W' && input[3] != 'S') {
			printf("오류");
			getch();
			continue;
		}
		
		/* 좌표해석 */
		row = input[0] - 'A';
		col = input[1] - '1';

		/* 배치공간 확인 및 함선 배치*/
		/* 북쪽 배치 입력시 */
		if(input[3] == 'N') {
			if (row - sLimit[sIndex] + 1 < 0 ) {
				printf("오류");
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
				printf("오류");
				getch();
				continue;
			}

		}
		/* 동쪽 배치 입력시 */
		else if (input[3] == 'E') {
			if (col + sLimit[sIndex] > SIZE ) {
				printf("오류");
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
				printf("오류");
				getch();
				continue;
			}
		}
		/* 서쪽 배치 입력시 */
		else if (input[3] == 'W') {
			if (col - sLimit[sIndex] + 1 < 0) {
				printf("오류");
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
				printf("오류");
				getch();
				continue;
			}
		}
		/* 남쪽 배치 입력시 */
		else if (input[3] == 'S') {
			if (row + sLimit[sIndex] > SIZE ) {
				printf("오류");
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
				printf("오류");
				getch();
				continue;
			}
		}

		/* 다음 입력 STAGE로 이동 */
		sIndex++;
	}
	
	/* 자료구조 초기화 */
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean2[i][j] = '#';
		}
	}
	/* rand() 함수에 다른 seed를 넣기 위해서 */
	srand(time(NULL));
	/* sIndex 초기화 */ 
	sIndex = 0;

	while (1) {
		/* STAGE가 모두 수행되었는지 체크 */
		if (sIndex >= nSTAGE) {
			/* 최종 ocean 상태 출력 */
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

		/* 좌표 랜덤 입력 */
		sprintf(input, "%c%c %c", 'A' + rand() % 9, '1' + rand() % 9, sDirection[rand() % 4]);
	
		/* 입력된 좌표 오류 체크 */
		/* 입력된 좌표 4자리 여부 체크*/
		if (strlen(input) != 4) {
			continue;
		}

		/* 입력된 좌표 범위 체크 */
		if (!('A' <= input[0] && input[0] <= 'I' && '1' <= input[1] && input[1] <= '9')) {
			continue;
		}

		/* 입력된 자표 형식 체크 */
		if (input[2] != ' ') {
			continue;
		}

		/* 입력된 좌표 방향 형식 체크*/
		if (input[3] != 'N' && input[3] != 'E' && input[3] != 'W' && input[3] != 'S') {
			continue;
		}
		
		/* 좌표해석 */
		row = input[0] - 'A';
		col = input[1] - '1';

		/* 배치공간 확인 및 함선 배치*/
		/* 북쪽 배치 입력시 */
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
		/* 동쪽 배치 입력시 */
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
		/* 서쪽 배치 입력시 */
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
		/* 남쪽 배치 입력시 */
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

		/* 다음 입력 STAGE로 이동 */
		sIndex++;
	}

	/* 종료전 입력 대기 */
	getch();

	return;
}



