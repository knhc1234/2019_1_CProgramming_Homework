#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4
#define MAXHIT 14
#define FILENAME "battleship_record.txt"
#define SEED 3		/* 좌표 column 1회 증가 값 */

/********************************************************************
get_smart_coordinate() 함수를 통해 스마트한 좌표를 구합니다.
1. 좌표는 랜덤으로 구하는 것이 아니고 SEED(3) 만큼 증가 시킵니다.
   -> 좌표적중이 20번 연속 안될 경우 랜덤으로 좌표를 다시 구합니다.
2. 좌표가 적중되면 동서남북 방향을 램덤으로 구해서 그 방향으로
   좌표를 한개씩 증가시켜 함선을 찾습니다.

조금 더 스마트하게 좌표를 한개 찾았을 경우 동서남북 모두를 정확하게
찾아서 함선 전체를 격침할 수 있게 할 수 없었던 점이 아쉽습니다.
********************************************************************/


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

/* row와 column을 한번에 */
void get_coordinate(const char coordinate[10], int* row, int* column)
{
	*row = coordinate[0] - 'A';
	*column = coordinate[1] - '1';
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

/* 랜덤 row, column, direction을 한번에 */
void get_random_coordinate(int* row, int* column, char* direction)
{
	int directionCode;

	*row = rand() % SIZE;
	*column = rand() % SIZE;

	directionCode = rand() % 4;
	switch (directionCode) {
		case 0:
			*direction = 'N';
			break;
		case 1:
			*direction = 'S';
			break;
		case 2:
			*direction = 'W';
			break;
		default:
			*direction = 'E';
			break;
	}
}

/* 랜덤 row, column을 한번에 */
void get_random_row_col(int* row, int* column)
{
	*row = rand() % SIZE;
	*column = rand() % SIZE;
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

void read_record(int* win, int* lose)
{
	FILE* fp;
	
	fp = fopen(FILENAME, "r");
	if (fp) {
		fscanf(fp, "%d %d", win, lose);
		fclose(fp);
	}
}

void write_record(int win, int lose)
{
	FILE* fp;
	fp = fopen(FILENAME, "w");

	if (fp) {
		fprintf(fp, "%d %d", win, lose);
		fclose(fp);
	}
}

void display_record(int win, int lose)
{
	printf("==============================================\n");
	printf("사령관님 환영합니다 !!\n");
	printf("==============================================\n");
	printf("현재까지 사령관님의 대 행성 하데스 전쟁 전적은\n");
	printf("%d승 %d패 입니다.\n\n", win, lose);
	printf("이번 전쟁도 승리를 기원 드립니다.\n");
	printf("Enter 키를 눌러주세요... ");
}

void get_next_row_col(int* row, int* column, int* caseDirection)
{
	switch(*caseDirection)
	{
		case 0:	
			*row = *row + 1;
			break;
		case 1:	
			*row = *row - 1;
			break;
		case 2:	
			*column = *column + 1;
			break;
		case 3:	
			*column = *column - 1;
			break;
		default:	
			*column = *column + SEED;
			if (*column > SIZE - 1) {
				*column = *column % SIZE ;
				*row = *row + 1;
				if (*row > SIZE - 1) {
					*row = *row % SIZE;
				}
			}
			break;
	}

	if (*column > SIZE - 1 || *column < 0 || *row > SIZE - 1 || *row < 0) {
		*caseDirection = 9;
		get_random_row_col(row, column);
	}
}

void get_smart_coordinate(int* row, int* column, int isHit)
{
	static int caseDirection;
	static int missSum = 0;
	
	if (isHit) {	/* 적중되면 좌표를 한개씩 증가 시킨다 */
		if (caseDirection == 9) {
			caseDirection = rand() % 4;		/* 4개 방향중 하나를 임의로 */
		}
		get_next_row_col(row, column, &caseDirection);
	}
	else {		/* 적중되지 않으면 랜덤 + 순차적으로 좌표 생성 */
		caseDirection = 9;
		missSum++;
		if (missSum % 20 == 0) { /* 20번 연속 실패시 랜덤으로 좌표생성*/
			get_random_row_col(row, column);
			printf("---Random---\n");
		}
		else { /* 20번 미만 실패시 SEED 만큼 순차적으로 좌표 생성*/
			get_next_row_col(row, column, &caseDirection);
		}
	}
}

void main() 
{
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
	int win = 0, lose = 0;

	/* 하데스가 Smart 공격을 하기 위한 상태 변수 */
	int rowHades = 0, columnHades = 0;
	int isHit = 0 ;			/* 공격이 적중했는지 */

	/* 현재까지의 전적 구하기 */
	read_record(&win, &lose);
	/* 현재까지의 전적 출력 */
	system("cls");
	display_record(win, lose);
	getch();
	
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
		get_coordinate(coordinate, &row, &column) ;
	
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
		get_random_coordinate(&row, &column, &direction);

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

	/* 하데스 최초 공격 좌표 랜덤 초기화*/
	get_random_row_col(&rowHades, &columnHades);

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
		get_coordinate(coordinate, &row, &column);

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
			/* 현재까지의 전적 저장하기 */
			win++;
			write_record(win, lose);

			printf("하데스 함선 모두 격파! 포세이돈의 승리입니다!\n");
			break;
		}

		/* 하데스 -> 포세이돈 공격 */
		while (1) {
			get_smart_coordinate(&rowHades, &columnHades, isHit);
			
			/* 중복일때 */
			if (is_duplicate_poseidon(ocean_poseidon, rowHades, columnHades)) {
				continue;
			};

			/* 공격 성공인 경우 shiptype  실패인경우 'X' 반환됨 */
			shiptype = check_attack_hit(ocean_poseidon, rowHades, columnHades);
			if (shiptype != 'X') {  /* 공격 좌표에 함대가 있을 때 */
				hitCountPoseidon++;
				isHit = 1;	
			}
			else {
				isHit = 0;
			}

			/* 포세이돈은 공격 성공 실패 여부와 관계없이 'X'만 출력 */
			deploy_attack(ocean_poseidon, rowHades, columnHades, 'X');

			printf("[하데스 공격] 좌표 %c%d \n", rowHades + 'A', columnHades + 1);
			display_two_oceans(ocean_poseidon, ocean_hades_display);
			break;
		}

		if (hitCountPoseidon == MAXHIT) {
			/* 현재까지의 전적 저장하기 */
			lose++;
			write_record(win, lose);
			printf("포세이돈 함선 모두 격파! 하데스의 승리입니다!\n");
			break;
		}
	}
	
	/* 종료전 입력 대기 */
	getch();

	return;
}
