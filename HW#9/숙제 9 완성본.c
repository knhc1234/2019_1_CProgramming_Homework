#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4
#define MAXHIT 14

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

/* �Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)�� return */
int get_row(const char coordinate[10])
{
	return coordinate[0] - 'A';
}

/* �Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)�� return*/
int get_column(const char coordinate[10])
{
	return coordinate[1] - '1';
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

/* ��ǥ���� row ��ǥ��(0���� 8������ ��)�� �����ϰ� �����ؼ� return */
int get_random_row(void)
{
	return rand() % SIZE;
}

/* ��ǥ���� column ��ǥ��(0���� 8������ ��)�� �����ϰ� �����ؼ� return */
int get_random_column(void)
{
	return rand() % SIZE;
}

/* ����('N', 'S', 'E', 'W' �� �ϳ�)�� �����ϰ� �����ؼ� return */
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
	char sName[nSTAGE][10] = { "�װ�����", "����", "������", "�����" };
	int	sIndex;

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
		row = get_row(coordinate);
		column = get_column(coordinate);

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
		row = get_random_row();
		column = get_random_column();
		direction = get_random_direction();

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
		row = get_row(coordinate);
		column = get_column(coordinate);

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
			printf("�ϵ��� �Լ� ��� ����! �����̵��� �¸��Դϴ�!\n");
			break;
		}

		/* �ϵ��� -> �����̵� ���� */
		while (1) {
			row = get_random_row();
			column = get_random_column();

			/* �ߺ��϶� */
			if (is_duplicate_poseidon(ocean_poseidon, row, column)) {
				continue;
			};

			/* ���� ������ ��� shiptype  �����ΰ�� 'X' ��ȯ�� */
			shiptype = check_attack_hit(ocean_poseidon, row, column);
			if (shiptype != 'X') {  /* ���� ��ǥ�� �Դ밡 ���� �� */
				hitCountPoseidon++;
			}

			/* �����̵��� ���� ���� ���� ���ο� ������� 'X'�� ��� */
			deploy_attack(ocean_poseidon, row, column, 'X');

			printf("[�ϵ��� ����] ��ǥ %c%d \n", row + 'A', column + 1);
			display_two_oceans(ocean_poseidon, ocean_hades_display);
			break;
		}

		if (hitCountPoseidon == MAXHIT) {
			printf("�����̵� �Լ� ��� ����! �ϵ����� �¸��Դϴ�!\n");
			break;
		}
	}
	
	/* ������ �Է� ��� */
	getch();

	return;
}
