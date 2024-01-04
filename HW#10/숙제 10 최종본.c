#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4
#define MAXHIT 14
#define FILENAME "battleship_record.txt"
#define SEED 3		/* ��ǥ column 1ȸ ���� �� */

/********************************************************************
get_smart_coordinate() �Լ��� ���� ����Ʈ�� ��ǥ�� ���մϴ�.
1. ��ǥ�� �������� ���ϴ� ���� �ƴϰ� SEED(3) ��ŭ ���� ��ŵ�ϴ�.
   -> ��ǥ������ 20�� ���� �ȵ� ��� �������� ��ǥ�� �ٽ� ���մϴ�.
2. ��ǥ�� ���ߵǸ� �������� ������ �������� ���ؼ� �� ��������
   ��ǥ�� �Ѱ��� �������� �Լ��� ã���ϴ�.

���� �� ����Ʈ�ϰ� ��ǥ�� �Ѱ� ã���� ��� �������� ��θ� ��Ȯ�ϰ�
ã�Ƽ� �Լ� ��ü�� ��ħ�� �� �ְ� �� �� ������ ���� �ƽ����ϴ�.
********************************************************************/


/* �ڷᱸ�� �ʱ�ȭ */
void initial_ocean(char ocean[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			ocean[i][j] = '#';
		}
	}
}

/* ���� ocean ���� ��� */
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

/* �Է°� ���� üũ */
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

/* row�� column�� �ѹ��� */
void get_coordinate(const char coordinate[10], int* row, int* column)
{
	*row = coordinate[0] - 'A';
	*column = coordinate[1] - '1';
}

/* shipetype('C', 'B', 'F', 'S' �� �ϳ�)�� ���� �Լ� ������ �� retrun */
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

/* ocean�� shipetype('C', 'B', 'F', 'S' �� �ϳ�)�� �Լ��� row, column, direction�� ��ġ �������� üũ */
int check_availability(const char ocean[SIZE][SIZE], int row, int column, char direction, char shiptype)
{
	int i;
	int ship_size;
	int collisionFlag;

	ship_size = get_shipsize(shiptype);

	/* ���� ��ġ �Է½� */
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

	/* ���� ��ġ �Է½� */
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

	/* ���� ��ġ �Է½� */
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

	/* ���� ��ġ �Է½� */
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

/* ocean�� shipetype('C', 'B', 'F', 'S' �� �ϳ�)�� �Լ��� row, column, direction�� ��ġ */
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

/* ���� row, column, direction�� �ѹ��� */
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

/* ���� row, column�� �ѹ��� */
void get_random_row_col(int* row, int* column)
{
	*row = rand() % SIZE;
	*column = rand() % SIZE;
}

/* �� �ٴ��� ���� ���*/
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

/* �Լ��� ������ �Է°� ���� üũ */
int check_coordinate(const char coordinate[10]) {
	if (strlen(coordinate) != 2) {
		return 0;
	}
	if (!('A' <= coordinate[0] && coordinate[0] <= 'I' && '1' <= coordinate[1] && coordinate[1] <= '9')) {
		return 0;
	}

	return 1;
}

/* ������ǥ �ߺ� ���� üũ (Hades) */
int is_duplicate_hades(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == '#')
		return 0;
	else
		return 1;
}

/* ������ǥ �ߺ� ���� üũ (Poseidon) */
int is_duplicate_poseidon(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == 'X')
		return 1;
	else
		return 0;
}

/* ���� ��ǥ�� �ִ� �Դ� ���� Ȯ�� */
char check_attack_hit(const char ocean[SIZE][SIZE], int row, int column) {
	if (ocean[row][column] == 'C' || ocean[row][column] == 'B' || ocean[row][column] == 'F' || ocean[row][column] == 'S') {
		return ocean[row][column];
	}
	else
		return 'X';
}

/* ���� ��� ocean�� �ݿ� */
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
	printf("��ɰ��� ȯ���մϴ� !!\n");
	printf("==============================================\n");
	printf("������� ��ɰ����� �� �༺ �ϵ��� ���� ������\n");
	printf("%d�� %d�� �Դϴ�.\n\n", win, lose);
	printf("�̹� ���ﵵ �¸��� ��� �帳�ϴ�.\n");
	printf("Enter Ű�� �����ּ���... ");
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
	
	if (isHit) {	/* ���ߵǸ� ��ǥ�� �Ѱ��� ���� ��Ų�� */
		if (caseDirection == 9) {
			caseDirection = rand() % 4;		/* 4�� ������ �ϳ��� ���Ƿ� */
		}
		get_next_row_col(row, column, &caseDirection);
	}
	else {		/* ���ߵ��� ������ ���� + ���������� ��ǥ ���� */
		caseDirection = 9;
		missSum++;
		if (missSum % 20 == 0) { /* 20�� ���� ���н� �������� ��ǥ����*/
			get_random_row_col(row, column);
			printf("---Random---\n");
		}
		else { /* 20�� �̸� ���н� SEED ��ŭ ���������� ��ǥ ����*/
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
	char sName[nSTAGE][10] = { "�װ�����", "����", "������", "�����" };
	int	sIndex;
	int win = 0, lose = 0;

	/* �ϵ����� Smart ������ �ϱ� ���� ���� ���� */
	int rowHades = 0, columnHades = 0;
	int isHit = 0 ;			/* ������ �����ߴ��� */

	/* ��������� ���� ���ϱ� */
	read_record(&win, &lose);
	/* ��������� ���� ��� */
	system("cls");
	display_record(win, lose);
	getch();
	
	/* Poseidon �Լ� ��ġ */
	/* �ڷᱸ�� �ʱ�ȭ */
	initial_ocean(ocean_poseidon);

	/* STAGE Index �ʱ�ȭ */
	sIndex = 0;
	while (1) {
		system("cls");
		display_ocean(ocean_poseidon);

		/* STAGE�� ��� ����Ǿ����� üũ */
		if (sIndex >= nSTAGE) {
			printf("�����غ� �Ϸ�!! ��� �Լ��� ��ġ�� �������ϴ�. \n");
			getch();
			break;
		}

		/* STAGE�� ���� �Լ� ���� �Ҵ� */
		shiptype = stype[sIndex];

		/* �Լ��� ���� �Լ� ������ �Ҵ� */
		ship_size = get_shipsize(shiptype);

		/* ��ǥ �Է� ��û */
		printf("%s %dĭ ��ġ (��ǥ ����): ", sName[sIndex], ship_size);
		scanf("%s %c", coordinate, &direction);

		/* �Էµ� ��ǥ ���� üũ */
		if (!check_input(coordinate, direction)) {
			printf("�߸��� ��ǥ �Ǵ� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
			getch();
			continue;
		}

		/* ��ǥ�ؼ� */
		get_coordinate(coordinate, &row, &column) ;
	
		/* �Լ� ��ġ ���� ���� Ȯ�� */
		if (!check_availability(ocean_poseidon, row, column, direction, shiptype)) {
			printf("��ġ�� �Ұ��� �մϴ�. �ٽ� �Է��ϼ���.\n");
			getch();
			continue;
		}

		/* �Լ� ��ġ */
		deploy_ship(ocean_poseidon, row, column, direction, shiptype);

		/* ���� �Է� STAGE�� �̵� */
		sIndex++;
	}

	/* Hades �Լ� ��ġ */

	/* �ڷᱸ�� �ʱ�ȭ */
	initial_ocean(ocean_hades);

	/* rand() seed �ʱ�ȭ */
	srand(time(NULL));
	/* STAGE Index �ʱ�ȭ */
	sIndex = 0;
	while (1) {
		/* STAGE�� ��� ����Ǿ����� üũ */
		if (sIndex >= nSTAGE) {
			break;
		}

		/* STAGE�� ���� �Լ� ���� �Ҵ� */
		shiptype = stype[sIndex];

		/* ��ǥ �� ���� ���� �Է� */
		get_random_coordinate(&row, &column, &direction);

		/* �Լ� ��ġ ���� ���� Ȯ�� */
		if (!check_availability(ocean_hades, row, column, direction, shiptype)) {
			continue;
		}

		/* �Լ� ��ġ */
		deploy_ship(ocean_hades, row, column, direction, shiptype);

		/* ���� �Է� STAGE�� �̵� */
		sIndex++;
	}


	/* ���� ���̴� �ϵ��� ��ǥ �ʱ�ȭ */
	initial_ocean(ocean_hades_display);
	system("cls");
	display_two_oceans(ocean_poseidon, ocean_hades_display);

	/* �ϵ��� ���� ���� ��ǥ ���� �ʱ�ȭ*/
	get_random_row_col(&rowHades, &columnHades);

	while (1) {
		/* �����̵� -> �ϵ��� ���� */
		printf("[�����̵� ����] ��ǥ�� �Է��ϼ��� : ");
		scanf("%s", coordinate);
		
		/* �Էµ� ��ǥ ���� üũ */
		if (!check_coordinate(coordinate)) {
			printf("�߸��� ��ǥ�Դϴ�. �ٽ� �Է��ϼ���.\n");
			getch();
			continue;
		}

		/* �÷��̾��� ������ǥ �ؼ� */
		get_coordinate(coordinate, &row, &column);

		if (is_duplicate_hades(ocean_hades_display, row, column)) {
			printf("�̹� ������ ��ǥ�Դϴ�. �ٽ� �Է��ϼ���.\n");
			getch();
			continue;
		}
		
		/* ���� ������ ��� shiptype  �����ΰ�� 'X' ��ȯ�� */
		shiptype =  check_attack_hit(ocean_hades, row, column);
		if (shiptype != 'X') {  /* ���� ��ǥ�� �Դ밡 ���� �� */
			hitCountHades++;
		}

		/* �ϵ����� ���� ������ ��� shiptype�� �����ΰ�� 'X'�� ��� */
		deploy_attack(ocean_hades_display, row, column, shiptype);
		system("cls");
		display_two_oceans(ocean_poseidon, ocean_hades_display);
		
		if (hitCountHades == MAXHIT) {
			/* ��������� ���� �����ϱ� */
			win++;
			write_record(win, lose);

			printf("�ϵ��� �Լ� ��� ����! �����̵��� �¸��Դϴ�!\n");
			break;
		}

		/* �ϵ��� -> �����̵� ���� */
		while (1) {
			get_smart_coordinate(&rowHades, &columnHades, isHit);
			
			/* �ߺ��϶� */
			if (is_duplicate_poseidon(ocean_poseidon, rowHades, columnHades)) {
				continue;
			};

			/* ���� ������ ��� shiptype  �����ΰ�� 'X' ��ȯ�� */
			shiptype = check_attack_hit(ocean_poseidon, rowHades, columnHades);
			if (shiptype != 'X') {  /* ���� ��ǥ�� �Դ밡 ���� �� */
				hitCountPoseidon++;
				isHit = 1;	
			}
			else {
				isHit = 0;
			}

			/* �����̵��� ���� ���� ���� ���ο� ������� 'X'�� ��� */
			deploy_attack(ocean_poseidon, rowHades, columnHades, 'X');

			printf("[�ϵ��� ����] ��ǥ %c%d \n", rowHades + 'A', columnHades + 1);
			display_two_oceans(ocean_poseidon, ocean_hades_display);
			break;
		}

		if (hitCountPoseidon == MAXHIT) {
			/* ��������� ���� �����ϱ� */
			lose++;
			write_record(win, lose);
			printf("�����̵� �Լ� ��� ����! �ϵ����� �¸��Դϴ�!\n");
			break;
		}
	}
	
	/* ������ �Է� ��� */
	getch();

	return;
}
