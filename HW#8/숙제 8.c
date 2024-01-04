#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4

/* 자료구조 초기화 */
void initial_ocean(char ocean[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean[i][j] = '#';
		}
	}
}

/* 현재 ocean 상태 출력 */
void display_ocean(const char ocean[9][9]) {
	int i, j;
	
	printf(" 123456789\n");
	for (i = 0; i < SIZE; i++) {
		printf("%c", 'A' + i);
		for (j = 0; j < SIZE; j++) {
			printf("%c", ocean[i][j]);
		}
		printf("\n");
	}
}

/* 입력받은 좌표값과 방향이 올바른 값인지 체크 */
int check_input(const char coordinate[10], char direction) {
	if (strlen(coordinate) != 2) {
		return 0;
	}
	if (coordinate[0]<'A' || coordinate[0]>'I' || coordinate[1]<'1' || coordinate[1]>'9') {
		return 0;
	}
	if (!(direction == 'N' || direction == 'E' || direction == 'S' || direction == 'W')) {
		return 0;
	}
	return 1;
}

/* 입력받은 좌표값에서 행 값을 return */
int get_row(const char coordinate[10]) {
	int row;

	row = coordinate[0] - 'A';
	return row;
}

/* 입력받은 좌표값에서 열 값을 return */
int get_column(const char coordinate[10]) {
	int column;

	column = coordinate[1] - '1';
	return column;
}

/* shiptype('C','B','F','S')에 따른 ship_size값 return */
int get_shipsize(const char shiptype) {
	int ship_size;

	switch (shiptype) {
	case 'C':
		ship_size = 5;
		break;
	case 'B':
		ship_size = 4;
		break;
	case 'F':
		ship_size = 3;
		break;
	case 'S':
		ship_size = 2;
		break;
	}

	return ship_size;
		
}

/* ocean에 shiptype함선을 배치 가능한지 체크 */
int check_availability(const char ocean[9][9], int row, int column, char direction, char shiptype) {
	int i;
	int ship_size;
	int collisionFlag;

	ship_size = get_shipsize(shiptype);

	/* 북쪽 배치 */
	if (direction == 'N') {
		if (row < ship_size - 1)
			return 0;

		collisionFlag = 0;
		for (i = 0; i < ship_size; i++) {
			if (ocean[row - i][column] != '#') {
				collisionFlag = 1;
				break;
			}
		}
		if (collisionFlag == 1)
			return 0;
	}

	/* 남쪽 배치 */
	else if (direction == 'S') {
		if (row > SIZE - ship_size)
			return 0;

		collisionFlag = 0;
		for (i = 0; i < ship_size; i++) {
			if (ocean[row + i][column] != '#') {
				collisionFlag = 1;
				break;
			}
		}
		if (collisionFlag == 1)
			return 0;
	}

	/* 동쪽 배치 */
	else if (direction == 'E') {
		if (column > SIZE - ship_size)
			return 0;

		collisionFlag = 0;
		for (i = 0; i < ship_size; i++) {
			if (ocean[row][column + i] != '#') {
				collisionFlag = 1;
				break;
			}
		}
		if (collisionFlag == 1)
			return 0;
	}
	
	/* 서쪽 배치 */
	else if (direction == 'W') {
		if (column < ship_size - 1)
			return 0;

		collisionFlag = 0;
		for (i = 0; i < ship_size; i++) {
			if (ocean[row][column - i] != '#') {
				collisionFlag = 1;
				break;
			}
		}
		if (collisionFlag == 1)
			return 0;
	}

	return 1;
}

/* 함선 배치 */
void deploy_ship(char ocean[9][9], int row, int column, char direction, char shiptype) {
	int i;
	int ship_size;

	ship_size = get_shipsize(shiptype);

	if (direction == 'N') {
		for (i = 0; i < ship_size; i++)
			ocean[row - i][column] = shiptype;
	}
	else if (direction == 'S') {
		for (i = 0; i < ship_size; i++)
			ocean[row + i][column] = shiptype;
	}
	else if (direction == 'E') {
		for (i = 0; i < ship_size; i++)
			ocean[row][column + i] = shiptype;
	}
	else if (direction == 'W') {
		for (i = 0; i < ship_size; i++)
			ocean[row][column - i] = shiptype;
	}
}

/* 좌표값중 row 랜덤 생성 */
int get_random_row(void) {
	return rand() % SIZE;
}

/* 좌표값중 column 랜덤 생성 */
int get_random_column(void) {
	return rand() % SIZE;
}

/* 방향 랜덤 생성 */
char get_random_direction(void) {
	int directioncode;
	char direction;

	directioncode = rand() % 4;
	switch (directioncode) {
	case 0:
		direction = 'N';
			break;
	case 1:
		direction = 'E';
			break;
	case 2:
		direction = 'W';
			break;
	case 3:
		direction = 'S';
			break;
	}

	return direction;
}

int main(void) {
	char ocean_poseidon[SIZE][SIZE];
	char ocean_hades[SIZE][SIZE];
	char coordinate[10];
	char direction;
	char shiptype;
	int  ship_size;

	int row = 0, column = 0;

	char stype[nSTAGE] = { 'C','B','F','S' };
	char sName[nSTAGE][10] = { "항공모함","전함","구축함","잠수함" };
	int sIndex; /* STAGE Index */
	
	/* Poseidon 함선 배치 */
	/* 자료구조 초기화 */
	initial_ocean(ocean_poseidon);

	sIndex = 0;
	while (1) {
		system("cls");
		display_ocean(ocean_poseidon);

		/* STAGE가 모두 수행되었는지 체크 */
		if (sIndex >= nSTAGE) {
			printf("전투준비 완료!! 모든 함선의 배치가 끝났습니다. \n");
			break;
		}

		/* STAGE에 따라 함선 종류 할당 */
		shiptype = stype[sIndex];

		/* 함선에 따른 함선 사이즈 할당 */
		ship_size = get_shipsize(shiptype);

		/* 좌표 입력 요청 */
		printf("%s %d칸 배치 (좌표 방향): ", sName[sIndex], ship_size);
		scanf("%s %c", coordinate, &direction);

		/* 입력된 좌표 오류 체크 */
		if (!check_input(coordinate, direction)) {
			printf("잘못된 좌표 또는 방향입니다. 다시 입력하세요.\n");
			getch();
			continue;
		}

		/* 좌표해석 */
		row = get_row(coordinate);
		column = get_column(coordinate);

		/* 함선 배치 가능 여부 확인 */
		if (!check_availability(ocean_poseidon, row, column, direction, shiptype)) {
			printf("배치가 불가능 합니다. 다시 입력하세요.\n");
			getch();
			continue;
		}

		/* 함선 배치 */
		deploy_ship(ocean_poseidon, row, column, direction, shiptype);

		/* 다음 입력 STAGE로 이동 */
		sIndex++;
	}

	/* Hades 함선 배치 */
	/* 자료구조 초기화 */
	initial_ocean(ocean_hades);

	/* rand() seed 초기화 */
	srand(time(NULL));
	/* STAGE Index 초기화 */
	sIndex = 0;
	while (1) {
		/* STAGE가 모두 수행되었는지 체크 */
		if (sIndex >= nSTAGE) {
			break;
		}

		/* STAGE에 따라 함선 종류 할당 */
		shiptype = stype[sIndex];

		/* 좌표 및 방향 랜덤 입력 */
		row = get_random_row();
		column = get_random_column();
		direction = get_random_direction();

		/* 함선 배치 가능 여부 확인 */
		if (!check_availability(ocean_hades, row, column, direction, shiptype)) {
			continue;
		}

		/* 함선 배치 */
		deploy_ship(ocean_hades, row, column, direction, shiptype);

		/* 다음 입력 STAGE로 이동 */
		sIndex++;
	}

	printf("\n\n");
	display_ocean(ocean_hades);
	printf("하데스 함선 배치 파악 완료!! \n");

	/* 종료전 입력 대기 */
	getch();

	return;
}