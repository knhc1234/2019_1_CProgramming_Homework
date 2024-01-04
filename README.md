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


