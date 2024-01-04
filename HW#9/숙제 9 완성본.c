#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4
#define MAXHIT 14

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
void display_ocean(const char ocean[SIZE][SIZE])
{
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

/* 입력값 오류 체크 */
int check_input(const char coordinate[10], char direction)
{
	if (strlen(coordinate) != 2) {
		return 0;
	}
	if (!('A' <= coordinate[0] && coordinate[0] <= 'I' && '1' <= coordinate[1] && coordinate[1] <= '9')) {
		return 0;
	}
	if (!(direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W')) {
		return 0;
	}

	return 1;
}

/* 입력받은 좌표값(coordinate)에서 행 값(0부터 8사이의 값)을 return */
int get_row(const char coordinate[10])
{
	return coordinate[0] - 'A';
}

/* 입력받은 좌표값(coordinate)에서 열 값(0부터 8사이의 값)을 return*/
int get_column(const char coordinate[10])
{
	return coordinate[1] - '1';
}

/* shipetype('C', 'B', 'F', 'S' 중 하나)에 따른 함선 사이즈 값 retrun */
int get_shipsize(const char shiptype)
{
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
	default:
		return 0;
		break;
	}

	return ship_size;
}

/* ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치 가능한지 체크 */
int check_availability(const char ocean[SIZE][SIZE], int row, int column, char direction, char shiptype)
{
	int i;
	int ship_size;
	int collisionFlag;

	ship_size = get_shipsize(shiptype);

	/* 북쪽 배치 입력시 */
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

	/* 남쪽 배치 입력시 */
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

	/* 동쪽 배치 입력시 */
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

	/* 서쪽 배치 입력시 */
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

/* ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치 */
void deploy_ship(char ocean[SIZE][SIZE], int row, int column, char direction, char shiptype)
{
	int i;
	int ship_size;

	ship_size = get_shipsize(shiptype);

	if (direction == 'N') {
		for (i = 0; i < ship_size; i++) {
			ocean[row - i][column] = shiptype;
		}
	}
	else if (direction == 'S') {
		for (i = 0; i < ship_size; i++) {
			ocean[row + i][column] = shiptype;
		}
	}
	else if (direction == 'E') {
		for (i = 0; i < ship_size; i++) {
			ocean[row][column + i] = shiptype;
		}
	}
	else if (direction == 'W') {
		for (i = 0; i < ship_size; i++) {
			ocean[row][column - i] = shiptype;
		}
	}
}

/* 좌표값중 row 좌표값(0부터 8사이의 값)을 랜덤하게 생성해서 return */
int get_random_row(void)
{
	return rand() % SIZE;
}

/* 좌표값중 column 좌표값(0부터 8사이의 값)을 랜덤하게 생성해서 return */
int get_random_column(void)
{
	return rand() % SIZE;
}

/* 방향('N', 'S', 'E', 'W' 중 하나)을 랜덤하게 생성해서 return */
char get_random_direction(void)
{
	int directionCode;
	char direction;

	directionCode = rand() % 4;
	switch (directionCode) {
	case 0:
		direction = 'N';
		break;
	case 1:
		direction = 'S';
		break;
	case 2:
		direction = 'W';
		break;
	default:
		direction = 'E';
		break;
	}
	return direction;
}

/* 두 바다의 상태 출력*/
void display_two_oceans(const char ocean1[SIZE][SIZE], const char ocean2[SIZE][SIZE]) 
{
	int i, j;

	printf(" 123456789  123456789\n");

	for (i = 0; i < SIZE; i++) {
		printf("%c", 'A' + i);
		for (j = 0; j < SIZE; j++) {
			printf("%c", ocean1[i][j]);
		}
		
		printf(" %c", 'A' + i);
		for (j = 0; j < SIZE; j++) {
			printf("%c", ocean2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

/* 함선간 전투시 입력값 오류 체크 */
int check_coordinate(const char coordinate[10]) {
	if (strlen(coordinate) != 2) {
		return 0;
	}
	if (!('A' <= coordinate[0] && coordinate[0] <= 'I' && '1' <= coordinate[1] && coordinate[1] <= '9')) {
		return 0;
	}

	return 1;
}

/* 공격좌표 중복 여부 체크 (Hades) */
int is_duplicate_hades(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == '#')
		return 0;
	else
		return 1;
}

/* 공격좌표 중복 여부 체크 (Poseidon) */
int is_duplicate_poseidon(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == 'X')
		return 1;
	else
		return 0;
}

/* 공격 좌표에 있는 함대 종류 확인 */
char check_attack_hit(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == 'C' || ocean[row][column] == 'B' || ocean[row][column] == 'F' || ocean[row][column] == 'S') {
		return ocean[row][column];
	}
	else
		return 'X';
}

/* 공격 결과 ocean에 반영 */
void deploy_attack(char ocean[SIZE][SIZE], int row, int column, char shiptype) {
	ocean[row][column] = shiptype;
}

void main() {
	char ocean_poseidon[SIZE][SIZE];
	char ocean_hades[SIZE][SIZE];
	char ocean_hades_display[SIZE][SIZE];
	char coordinate[10];
	char direction;
	char shiptype;
	int  ship_size;

	int hitCountPoseidon=0, hitCountHades = 0;
	int row = 0, column = 0;

	char stype[nSTAGE] = { 'C', 'B', 'F', 'S' };
	char sName[nSTAGE][10] = { "항공모함", "전함", "구축함", "잠수함" };
	int	sIndex;

	/* Poseidon 함선 배치 */
	/* 자료구조 초기화 */
	initial_ocean(ocean_poseidon);

	/* STAGE Index 초기화 */
	sIndex = 0;
	while (1) {
		system("cls");
		display_ocean(ocean_poseidon);

		/* STAGE가 모두 수행되었는지 체크 */
		if (sIndex >= nSTAGE) {
			printf("전투준비 완료!! 모든 함선의 배치가 끝났습니다. \n");
			getch();
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


	/* 눈에 보이는 하데스 좌표 초기화 */
	initial_ocean(ocean_hades_display);
	system("cls");
	display_two_oceans(ocean_poseidon, ocean_hades_display);

	while (1) {
		/* 포세이돈 -> 하데스 공격 */
		printf("[포세이돈 공격] 좌표를 입력하세요 : ");
		scanf("%s", coordinate);
		
		/* 입력된 좌표 오류 체크 */
		if (!check_coordinate(coordinate)) {
			printf("잘못된 좌표입니다. 다시 입력하세요.\n");
			getch();
			continue;
		}

		/* 플레이어의 공격좌표 해석 */
		row = get_row(coordinate);
		column = get_column(coordinate);

		if (is_duplicate_hades(ocean_hades_display, row, column)) {
			printf("이미 공격한 좌표입니다. 다시 입력하세요.\n");
			getch();
			continue;
		}
		
		/* 공격 성공인 경우 shiptype  실패인경우 'X' 반환됨 */
		shiptype =  check_attack_hit(ocean_hades, row, column);
		if (shiptype != 'X') {  /* 공격 좌표에 함대가 있을 때 */
			hitCountHades++;
		}

		/* 하데스는 공격 성공인 경우 shiptype을 실패인경우 'X'를 출력 */
		deploy_attack(ocean_hades_display, row, column, shiptype);
		system("cls");
		display_two_oceans(ocean_poseidon, ocean_hades_display);
		
		if (hitCountHades == MAXHIT) {
			printf("하데스 함선 모두 격파! 포세이돈의 승리입니다!\n");
			break;
		}

		/* 하데스 -> 포세이돈 공격 */
		while (1) {
			row = get_random_row();
			column = get_random_column();

			/* 중복일때 */
			if (is_duplicate_poseidon(ocean_poseidon, row, column)) {
				continue;
			};

			/* 공격 성공인 경우 shiptype  실패인경우 'X' 반환됨 */
			shiptype = check_attack_hit(ocean_poseidon, row, column);
			if (shiptype != 'X') {  /* 공격 좌표에 함대가 있을 때 */
				hitCountPoseidon++;
			}

			/* 포세이돈은 공격 성공 실패 여부와 관계없이 'X'만 출력 */
			deploy_attack(ocean_poseidon, row, column, 'X');

			printf("[하데스 공격] 좌표 %c%d \n", row + 'A', column + 1);
			display_two_oceans(ocean_poseidon, ocean_hades_display);
			break;
		}

		if (hitCountPoseidon == MAXHIT) {
			printf("포세이돈 함선 모두 격파! 하데스의 승리입니다!\n");
			break;
		}
	}
	
	/* 종료전 입력 대기 */
	getch();

	return;
}
