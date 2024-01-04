# 2019_1_CProgramming_Homework
2019_1학기 컴퓨터프로그래밍 과제

HW#2
1) 정수를 입력받아 홀수, 짝수 출력
2) 구구단을 2단부터 9단까지 출력(while문)
3) 1:가위 2:바위 3:보로 취급하여 컴퓨터가 랜덤하게 선택한 가위바위보와 대결하는 프로그램(3승 할 때까지 반복하여 수행)

HW#3
1) HW#2의 2번을 for문으로 작성
2) HW#2의 3번을 switch문을 사용하여 작성
3) 별찍기 1
4) 별찍기 2
5) 1부터 100까지 짝수의 합을 구하는 프로그램 작성
6) 1부터 100까지 소수의 합을 구하는 프로그램 작성(소수 판별하는 함수를 필수적으로 만들어서 사용)

HW#4
1) a: 2부터 10개의 짝수 저장, b: 1부터 10개의 홀수 저장, c: a[i] * b[i] 저장, sum: c값들의 합을 저장
2) 구구단 문제
3) 성적처리 문제(평균, 최소점수, 최대점수)
4) 랜덤 번호 생성(0~10사이, 중복 X)

HW#5
1) 이름(문자열) 5개를 입력받아 names에 저장 후 내용 차례대로 출력. 이름(문자열) 1개를 입력 받아 search에 저장. names에 search와 같은 이름이 있으면 몇번째 이름인지 출력, 없으면 "없습니다" 출력. 이러한 검색을 "quit"이 입력될 때까지 반복.
2) 이름(문자열), 나이(정수), 키(실수)를 입력받아서 name, age, height에 저장. strcpy()와 strcat()을 사용하여 result에 다음 문자열을 저장 "[name] is [age] years old and his/her height is [height]" ([]는 각 변수에 저장된 값을 의미) 최종적으로 result의 문자열 내용 출력
3) 2번과 동일한 기능을 수행하는 프로그램을 sprintf()를 사용하여 작성

HW#6

6-1. 당신은 바다로 이루어진 행성 "포세이돈"의 방위 사령관으로 임명되었다.
1) 행성 방위를 위해서, 먼저 구역 정보시스템을 시스템을 갖춰라. ocean[9][9] 에 각 구역의 정보를 저장하라. 초기에 모든 구역 정보에는 '#'이 저장되어 있다.
2) 구역 지정 기능을 갖춰라. 사령관이 좌표를 입력하면, 그 좌표에 해당하는 구역의 정보를 'X'로 마크하고 ocean의 내용을 출력하라.
3) 오류 방지 기능을 갖춰라. 사령관이 실수로 잘못된 좌표를 입력하면 (예: 5C, K6, , D+ 등), "잘못된 좌표입니다." 라고 출력하고 다시 좌표를 입력받으라. 만약 사령관이 이전에 입력했던 좌표(즉, 이미 'X'로 표시된 좌표)를 입력하면, "이미 입력한 좌표입니다." 라고 출력하고 다시 좌표를 입력받으라.
4) 사령관이 "GG"를 입력할 때 까지 2)와 3)을 반복하라."GG"가 입력되면, "지금까지 ...개의 좌표가 입력되었습니다."를 출력하고, 구역 정보시스템을 종료하라.
   
6-2. 3차원 좌표 (x, y, z)를 저장하는 구조체(3개의 실수값으로 구성)를 만들고, 두 점의 좌표를 저장할 p1, p2 구조체에 값을 입력받아서 두 점사이의 거리를 구해서 출력하라. 

HW#7
1) 전투준비!!
   
   행성 방위 사령관인 당신에게 4척의 함선이 주어졌다.
- 항공모함: 5칸 (C)
- 전함: 4칸 (B)
- 구축함: 3칸 (F)
- 잠수함: 2칸 (S)

행성 포세이돈을 지키기엔 턱없이 부족한 병력이지만, 한 번 열심히 해보자.

우선, 각 함선을 ocean에 배치하는 것으로 시작하자.
함선을 배치하기 위해서, 함선의 1) 시작점 좌표와 2) 배치 방향을 입력해야 한다.
(배치 방향은 N, E, W, S 중 하나를 선택해서, 북쪽, 동쪽, 서쪽, 남쪽을 표시한다.
북쪽은 위쪽방향, 동쪽은 오른쪽방향, 서쪽은 왼쪽방향, 남쪽은 아래쪽방향을 의미한다.)

항공모함부터 시작해서 잠수함까지 총 4종류의 함선에 대해서
차례로 이 두값을 입력받아 함선을 배치하자.

주의1: 9x9 크기인 ocean안에만 함선을 배치할 수 있다.
(즉 항공모함을 C4 N로 배치하려고 하면,
"오류"를 출력하고 다시 항공모함 정보를 입력받아야 한다.)

주의2: 함선끼리는 겹칠 수 없다.
(즉, 항공모함을 A3 S로 배치하고 나서, 전함을 C1 E로 배치하려고 하면,
"오류"를 출력하고 다시 전함 정보를 입력받아야 한다.)

각 함선의 배치가 끝날 때 마다, 현재 배치 상황을 출력해야 한다.

2) 비상! 비상!
   
행성 하데스에서 공격을 준비하고 있다는 첩보가 입수되었다.

우연히도 행성 하데스도 우리와 똑같이 항공모함 1척, 전함 1척, 구축함 1척, 잠수함 1척을 바다에 배치했다고 한다.


다행히도 우리의 우수한 첩보원 발키리에 의해서 행성 하데스의 함선배치 상황이 입수되었다.
행성 하데스의 함선배치 상황을 출력하라.


(rand()함수를 사용하여, 행성 하데스에 함선을 랜덤하게 배치하고 그 결과를 출력하면 됨.
단, 함선을 배치할때 행성 포세이돈의 규칙을 똑같이 따라야 함.)

HW#8
1) 다음의 함수(function)을 작성하고, 이를 사용하여 숙제 7에서 했던 코드를 다시 작성하라.


void display_ocean(const char ocean[9][9])
ocean의 내용을 화면에 출력


int check_input(const char coordinate[10], char direction)
입력받은 좌표값(coordinate)과 방향(direction)이 올바른 값인지 체크
만약 올바른 값이면 1 (true)를 return하고, 올바르지 않은 값이면 0 (false)를 return


int get_row(const char coordinate[10])
입력받은 좌표값(coordinate)에서 행 값(0부터 8사이의 값)을 return


int get_column(const char coordinate[10])
입력받은 좌표값(coordinate)에서 열 값(0부터 8사이의 값)을 return


int check_availability(const char ocean[9][9], int row, int column, char direction, char shiptype)
ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치 가능한지 체크
만약 배치 가능하면 1 (true)를 return하고, 배치 가능하지 않으면 0 (false)를 return


void deploy_ship(char ocean[9][9], int row, int column, char direction, char shiptype)
ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치
return값은 따로 없지만, ocean이 배열이기 때문에 함수 안에서 수정하면 그 결과가 반영됨


2) 다행히 Hades도 똑같은 문제 때문에 사령부가 혼란에 빠졌다.
이왕 일을 하는김에 Hades도 도와주자.

Hades를 위해서는 다음의 함수를 추가로 작성해서 코드에서 활용하라.


int get_random_row(void)
좌표값중 row 좌표값(0부터 8사이의 값)을 랜덤하게 생성해서 return


int get_random_column(void)
좌표값중 column 좌표값(0부터 8사이의 값)을 랜덤하게 생성해서 return


char get_random_direction(void)
방향('N', 'S', 'E', 'W' 중 하나)을 랜덤하게 생성해서 return


3) 숙제 7의 solution은 설명의 편의를 위해서 Poseidon과 Hades 각각에 대해서 독립적인 코드로 ocean을 생성하도록 되어 있다.

그러나, 최종적으로는 Poseidon과 Hades가 하나의 소스코드로 합쳐져야 한다. 

만약 자신의 코드가 Poseidon과 Hades 각각에 대해서 별도의 c 파일로 만들어져 있다면,

하나의 c 파일로 코드로 합치고, 프로그램의 최종결과로 Poseidon과 Hades의 함선 배치를 차례로 출력하도록 하라.

HW#9

당신은 그 동안의 공적을 인정받아 총사령관으로 임명되었다.
총사령관으로서 행성 하데스와의 전쟁을 승리로 이끌어라.

우리 행성인 포세이돈에 대해서는 함선배치를 알 수 있으나,
적 행성인 하데스에 대해서는 어디에 함선이 있는지 알 수 없다.(왼쪽에 행성 포세이돈을 오른쪽에 행성 하데스를 출력한다)


공격은 우리부터!
좌표를 입력하여 행성 하데스의 해당 위치에 미사일을 날리자.
만약 해당 위치에 함선이 없었다면 X가 표시되고,
함선이 있었다면 함선의 기호(즉, 'C' 'B' 'F' 'S' 중 하나)가 드러나면서 그 부분은 파괴된 것으로 간주된다.


우리의 공격이 끝나면, 하데스도 마찬가지 방법으로 우리를 공격한다.
하데스의 공격이 떨어진 부분을 X로 표시하고,
해당 위치에 함선이 있었다면 그 부분은 파괴된 것으로 간주한다.


이러한 방식으로 서로 공격을 한번씩 주고 받아서,
상대 함선을 먼저 모두 격침시키는 쪽이 승리한다.


단, 우리나 하데스 모두, 이미 한 번 공격한 위치는 다시 공격할 수 없다.


참고: 하데스의 경우, 화면에 보여주기 위한 정보와 함선 배치 정보를
각각 독립된 배열에 저장하면 구현이 더 편할 것임

HW#10
1) Pointer를 이용하여 함수(function)을 정비하라.
   
1: [원래 함수: row와 column을 별도의 함수에서 얻음]
int get_row(const char coordinate[10]);
int get_column(const char coordinate[10]);
-->
[개선된 함수: pointer를 사용하여 하나의 함수에서 얻음]
int get_coordinate(const char coordinate[10], int* row, int* column);

2: [원래 함수: row, column, direction을 별도의 함수에서 얻음]
int get_random_row(void);
int get_random_column(void);
char get_random_direction(void);
-->
[개선된 함수: pointer를 사용하여 하나의 함수에서 얻음]
int get_random_coordinate(const char coordinate[10], int* row, int* column, char* direction);

2) 파일(file)을 사용하여 역사를 기록하라.


파일에 현재까지 행성 포세이돈의 승수와 패수를 기록하고,
프로그램이 실행될 때 처음에 이 정보를 화면에 출력하라.


예)
====================================
사령관님 환영합니다.
====================================
현재까지 사령관님의 대 행성 하데스 전쟁 전적은
11승 0패 입니다.

3) 매번 지기만 하는 행성 하데스가 불쌍하다면, 좀 도와주자.


행성 하데스가 공격 좌표를 random하게 정하는 것이 아니라
좀 더 smart하게 정하도록 하는 code를 추가해보자.


- 어떤 방법을 사용하던 자유
