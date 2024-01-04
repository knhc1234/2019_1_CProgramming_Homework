#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 9
#define nSTAGE 4

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

/* �Է¹��� ��ǥ���� ������ �ùٸ� ������ üũ */
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

/* �Է¹��� ��ǥ������ �� ���� return */
int get_row(const char coordinate[10]) {
	int row;

	row = coordinate[0] - 'A';
	return row;
}

/* �Է¹��� ��ǥ������ �� ���� return */
int get_column(const char coordinate[10]) {
	int column;

	column = coordinate[1] - '1';
	return column;
}

/* shiptype('C','B','F','S')�� ���� ship_size�� return */
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

/* ocean�� shiptype�Լ��� ��ġ �������� üũ */
int check_availability(const char ocean[9][9], int row, int column, char direction, char shiptype) {
	int i;
	int ship_size;
	int collisionFlag;

	ship_size = get_shipsize(shiptype);

	/* ���� ��ġ */
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

	/* ���� ��ġ */
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

	/* ���� ��ġ */
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
	
	/* ���� ��ġ */
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

/* �Լ� ��ġ */
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

/* ��ǥ���� row ���� ���� */
int get_random_row(void) {
	return rand() % SIZE;
}

/* ��ǥ���� column ���� ���� */
int get_random_column(void) {
	return rand() % SIZE;
}

/* ���� ���� ���� */
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
	char sName[nSTAGE][10] = { "�װ�����","����","������","�����" };
	int sIndex; /* STAGE Index */
	
	/* Poseidon �Լ� ��ġ */
	/* �ڷᱸ�� �ʱ�ȭ */
	initial_ocean(ocean_poseidon);

	sIndex = 0;
	while (1) {
		system("cls");
		display_ocean(ocean_poseidon);

		/* STAGE�� ��� ����Ǿ����� üũ */
		if (sIndex >= nSTAGE) {
			printf("�����غ� �Ϸ�!! ��� �Լ��� ��ġ�� �������ϴ�. \n");
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

	printf("\n\n");
	display_ocean(ocean_hades);
	printf("�ϵ��� �Լ� ��ġ �ľ� �Ϸ�!! \n");

	/* ������ �Է� ��� */
	getch();

	return;
}